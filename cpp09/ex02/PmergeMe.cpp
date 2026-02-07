/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:51:44 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/07 13:59:14 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

/* ========================================================================== */
/* Ford–Johnson helpers (used only in this .cpp; not exposed in header)       */
/* ========================================================================== */

/* Node = (value, pair_id). We carry the pair index so we can match big/small
   after recursion and handle duplicates (strict weak ordering by value then id). */
typedef std::pair<int, size_t> Node;

/* Compare two Nodes: first by value, then by id (for stability and duplicates). */
struct CompareNode {
    bool operator()(const Node &a, const Node &b) const {
        return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    }
};

/* Functor to find the Node whose .second (id) equals a given id (used in int version
   to locate the “partner big” for a given pend index). */
struct FindById {
    size_t id;
    FindById(size_t i) : id(i) {}
    bool operator()(const Node &x) const { return x.second == id; }
};

/* Functor to find the Node with a given (value, id). Used in Node recursion to
   find the partner big unambiguously (avoids matching the inserted small with same id). */
struct FindByValueAndId {
    int value;
    size_t id;
    FindByValueAndId(int v, size_t i) : value(v), id(i) {}
    bool operator()(const Node &x) const { return x.first == value && x.second == id; }
};

/* Build the Jacobsthal insertion order for pend indices 1..count.
   Jacobsthal: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2) → 0,1,1,3,5,11,21,...
   Ford–Johnson inserts pend in blocks; block boundaries are J(k)-1 (e.g. 2,4,10,20,...).
   We output indices in that block order (e.g. count=4 → 2,1,4,3) to minimize comparisons. */
static std::vector<size_t> buildJacobsthalOrder(size_t count) {
    std::vector<size_t> order;
    if (count == 0)
        return order;
    order.reserve(count);
    size_t J_prev = 1, J_cur = 1;
    size_t prevMilestonePend = 0;
    for (;;) {
        /* Next Jacobsthal number */
        size_t J_next = J_cur + 2 * J_prev;
        J_prev = J_cur;
        J_cur = J_next;
        /* This block ends at pend index (J_cur - 1), capped by count */
        size_t milestonePend = J_cur - 1;
        size_t end = (milestonePend < count) ? milestonePend : count;
        size_t start = prevMilestonePend + 1;
        /* Push indices from end down to start (descending within block) */
        if (start <= end) {
            for (size_t j = 0; j <= end - start; j++)
                order.push_back(end - j);
        }
        prevMilestonePend = end;
        if (prevMilestonePend >= count)
            break;
        if (start > count)
            break;
    }
    return order;
}

/* Ensure each pair (c[i], c[i+1]) is ordered so the smaller is first. */
static void pairAndSortVectorInt(std::vector<int> &c) {
    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        if (c[i] > c[i + 1])
            std::swap(c[i], c[i + 1]);
    }
}

/* Same for vector of Nodes: compare by value then id (CompareNode). */
static void pairAndSortVectorNode(std::vector<std::pair<int, size_t> > &c) {
    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        if (CompareNode()(c[i + 1], c[i]))
            std::swap(c[i], c[i + 1]);
    }
}

/* Same pairing for deque<int>. */
static void pairAndSortDequeInt(std::deque<int> &c) {
    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        if (c[i] > c[i + 1])
            std::swap(c[i], c[i + 1]);
    }
}

/* Same pairing for deque of Nodes. */
static void pairAndSortDequeNode(std::deque<std::pair<int, size_t> > &c) {
    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        if (CompareNode()(c[i + 1], c[i]))
            std::swap(c[i], c[i + 1]);
    }
}

/* ========================================================================== */
/* PmergeMe: constructors, destructor, operator=                              */
/* ========================================================================== */

PmergeMe::PmergeMe() : _vec(), _deque() {
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deque(other._deque) {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
}

/* ========================================================================== */
/* sort: time each container independently (only its own copy + sort)         */
/* ========================================================================== */

/* Vector overload: accept sequence as vector; time vector then deque separately. */
void PmergeMe::sort(const std::vector<int> &sequence) {
    _printSequence(sequence, "Before");

    /* Vector: time includes only copying into _vec and sorting _vec. */
    long long start = _getTime();
    _vec = sequence;
    _mergeInsertSortVector(_vec);
    long long durationVector = _getTime() - start;

    /* Deque: time includes only copying into _deque and sorting _deque. */
    start = _getTime();
    _deque.assign(sequence.begin(), sequence.end());
    _mergeInsertSortDeque(_deque);
    long long durationDeque = _getTime() - start;

    _printSequence(_vec, "After");
    _displayTime("std::vector", sequence.size(), durationVector);
    _displayTime("std::deque", sequence.size(), durationDeque);
}

/* Deque overload: same logic; accept sequence as deque. */
void PmergeMe::sort(const std::deque<int> &sequence) {
    _printSequence(sequence, "Before");

    long long start = _getTime();
    _vec.assign(sequence.begin(), sequence.end());
    _mergeInsertSortVector(_vec);
    long long durationVector = _getTime() - start;

    start = _getTime();
    _deque = sequence;
    _mergeInsertSortDeque(_deque);
    long long durationDeque = _getTime() - start;

    _printSequence(_vec, "After");
    _displayTime("std::vector", sequence.size(), durationVector);
    _displayTime("std::deque", sequence.size(), durationDeque);
}

/* ========================================================================== */
/* Timing and I/O (all in .cpp so header stays free of I/O)                   */
/* ========================================================================== */

/* Monotonic clock in nanoseconds; not affected by system time changes (e.g. NTP). */
long long PmergeMe::_getTime() const {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000LL + (long long)ts.tv_nsec;
}

/* timeNs = duration in nanoseconds; we display it in microseconds with decimals. */
void PmergeMe::_displayTime(const std::string &containerName, size_t size, long long timeNs) const {
    std::cout << "Time to process a range of " << size << " elements with "
              << containerName << " : "
              << std::fixed << std::setprecision(5)
              << (static_cast<double>(timeNs) / 1000.00000) << " us"
              << std::endl;
}

void PmergeMe::_printSequence(const std::vector<int> &sequence, const std::string &title) const {
    std::cout << title << ": ";
    for (size_t i = 0; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::_printSequence(const std::deque<int> &sequence, const std::string &title) const {
    std::cout << title << ": ";
    for (size_t i = 0; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;
}

/* ========================================================================== */
/* Ford–Johnson: vector<int> entry point                                      */
/* ========================================================================== */

void PmergeMe::_mergeInsertSortVector(std::vector<int> &container) {
    if (container.size() <= 1)
        return;

    /* Step 1 — Straggler: if size is odd, put the last element aside; we sort the rest in pairs. */
    bool hasStraggler = (container.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = container.back();
        container.pop_back();
    }

    /* Step 2 — Pair and order: each pair (container[i], container[i+1]) becomes (small, big). */
    pairAndSortVectorInt(container);

    /* Step 3 — Split into bigs (mainChain) and smalls (pend). Then sort bigs by Ford–Johnson
       recursively (no std::sort): we pass (big, pair_id) so we can rebuild pend after. */
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < container.size(); i += 2) {
        pend.push_back(container[i]);
        mainChain.push_back(container[i + 1]);
    }

    typedef std::vector<Node> NodeVec;
    NodeVec bigChain;
    for (size_t i = 0; i < mainChain.size(); i++)
        bigChain.push_back(std::make_pair(mainChain[i], i));
    std::vector<int> savedPend = pend;
    _mergeInsertSortVector(bigChain);

    /* Step 4 — Rebuild mainChain and pend in the order returned by recursion (sorted by big). */
    mainChain.clear();
    pend.clear();
    for (size_t i = 0; i < bigChain.size(); i++) {
        mainChain.push_back(bigChain[i].first);
        pend.push_back(savedPend[bigChain[i].second]);
    }

    /* Step 5 — S is the main chain as (value, id); insert pend[0] at the front (Ford–Johnson). */
    NodeVec S;
    for (size_t i = 0; i < mainChain.size(); i++)
        S.push_back(std::make_pair(mainChain[i], i));
    if (pend.size() > 0)
        S.insert(S.begin(), std::make_pair(pend[0], static_cast<size_t>(0)));

    /* Step 6 — Insert remaining pend in Jacobsthal order: for each index i, find the partner
       big (same id) in S, then lower_bound in [begin, partner) and insert (pend[i], i). */
    size_t count = (pend.size() > 1) ? (pend.size() - 1) : 0;
    std::vector<size_t> order = buildJacobsthalOrder(count);
    for (size_t k = 0; k < order.size(); k++) {
        size_t i = order[k];
        NodeVec::iterator posBig = std::find_if(S.begin(), S.end(), FindById(i));
        if (posBig == S.end())
            throw std::runtime_error("Error: partner big not found in main chain");
        Node node = std::make_pair(pend[i], i);
        NodeVec::iterator insertPos = std::lower_bound(S.begin(), posBig, node, CompareNode());
        S.insert(insertPos, node);
    }

    /* Step 7 — Write back only the values; then reinsert straggler with lower_bound. */
    container.clear();
    for (size_t k = 0; k < S.size(); k++)
        container.push_back(S[k].first);
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.end(), straggler);
        container.insert(pos, straggler);
    }
}

/* ========================================================================== */
/* Ford–Johnson: vector<Node> — recursive sort of the “big” chain             */
/* ========================================================================== */
/* Used when we sort the list of bigs: each element is (value, pair_id). We must
   preserve .second across recursion so the caller can rebuild pend correctly.
   If the big chain has odd size, we handle a Node straggler the same way as int. */

void PmergeMe::_mergeInsertSortVector(std::vector<std::pair<int, size_t> > &chain) {
    if (chain.size() <= 1)
        return;

    /* Straggler for odd-sized chain (e.g. 6 input → 3 pairs → 3 bigs → 1 straggler). */
    bool hasStraggler = (chain.size() % 2 != 0);
    Node straggler = Node(0, 0);
    if (hasStraggler) {
        straggler = chain.back();
        chain.pop_back();
    }

    pairAndSortVectorNode(chain);
    std::vector<Node> mainChain;
    std::vector<Node> pend;
    for (size_t i = 0; i < chain.size(); i += 2) {
        pend.push_back(chain[i]);
        mainChain.push_back(chain[i + 1]);
    }

    /* origIndex[id] = position of the big with that id before we sort mainChain.
       After recursion, mainChain is reordered; we use origIndex to rebuild pend
       so pend[j] is the small that belonged to mainChain[j] before the sort. */
    std::vector<Node> savedPend = pend;
    size_t maxId = 0;
    for (size_t j = 0; j < mainChain.size(); j++)
        if (mainChain[j].second > maxId)
            maxId = mainChain[j].second;
    std::vector<size_t> origIndex(maxId + 1, 0);
    for (size_t j = 0; j < mainChain.size(); j++)
        origIndex[mainChain[j].second] = j;

    _mergeInsertSortVector(mainChain);

    pend.clear();
    for (size_t j = 0; j < mainChain.size(); j++)
        pend.push_back(savedPend[origIndex[mainChain[j].second]]);

    /* Build S and insert pend[0]; then Jacobsthal insert rest. Partner is found by
       (value, id) so we hit the big, not an already-inserted small with same id. */
    std::vector<Node> S;
    for (size_t i = 0; i < mainChain.size(); i++)
        S.push_back(std::make_pair(mainChain[i].first, mainChain[i].second));
    if (pend.size() > 0)
        S.insert(S.begin(), std::make_pair(pend[0].first, pend[0].second));

    size_t count = (pend.size() > 1) ? (pend.size() - 1) : 0;
    std::vector<size_t> order = buildJacobsthalOrder(count);
    for (size_t k = 0; k < order.size(); k++) {
        size_t i = order[k];
        std::vector<Node>::iterator posBig = std::find_if(S.begin(), S.end(),
            FindByValueAndId(mainChain[i].first, mainChain[i].second));
        if (posBig == S.end())
            throw std::runtime_error("Error: partner big not found in main chain");
        Node node = std::make_pair(pend[i].first, pend[i].second);
        std::vector<Node>::iterator insertPos = std::lower_bound(S.begin(), posBig, node, CompareNode());
        S.insert(insertPos, node);
    }

    if (hasStraggler) {
        std::vector<Node>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler, CompareNode());
        S.insert(pos, straggler);
    }

    chain.clear();
    for (size_t idx = 0; idx < S.size(); idx++)
        chain.push_back(S[idx]);
}

/* ========================================================================== */
/* Ford–Johnson: deque<int> entry point                                       */
/* ========================================================================== */
/* Same algorithm as vector<int>, but on std::deque                           */

void PmergeMe::_mergeInsertSortDeque(std::deque<int> &container) {
    if (container.size() <= 1)
        return;

    bool hasStraggler = (container.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = container.back();
        container.pop_back();
    }

    pairAndSortDequeInt(container);

    std::deque<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < container.size(); i += 2) {
        pend.push_back(container[i]);
        mainChain.push_back(container[i + 1]);
    }

    typedef std::deque<Node> NodeDeque;
    NodeDeque bigChain;
    for (size_t i = 0; i < mainChain.size(); i++)
        bigChain.push_back(std::make_pair(mainChain[i], i));
    std::vector<int> savedPend = pend;
    _mergeInsertSortDeque(bigChain);

    mainChain.clear();
    pend.clear();
    for (size_t i = 0; i < bigChain.size(); i++) {
        mainChain.push_back(bigChain[i].first);
        pend.push_back(savedPend[bigChain[i].second]);
    }

    NodeDeque S;
    for (size_t i = 0; i < mainChain.size(); i++)
        S.push_back(std::make_pair(mainChain[i], i));
    if (pend.size() > 0)
        S.insert(S.begin(), std::make_pair(pend[0], static_cast<size_t>(0)));

    size_t count = (pend.size() > 1) ? (pend.size() - 1) : 0;
    std::vector<size_t> order = buildJacobsthalOrder(count);
    for (size_t k = 0; k < order.size(); k++) {
        size_t i = order[k];
        NodeDeque::iterator posBig = std::find_if(S.begin(), S.end(), FindById(i));
        if (posBig == S.end())
            throw std::runtime_error("Error: partner big not found in main chain");
        Node node = std::make_pair(pend[i], i);
        NodeDeque::iterator insertPos = std::lower_bound(S.begin(), posBig, node, CompareNode());
        S.insert(insertPos, node);
    }

    container.clear();
    for (size_t k = 0; k < S.size(); k++)
        container.push_back(S[k].first);
    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.end(), straggler);
        container.insert(pos, straggler);
    }
}

/* ========================================================================== */
/* Ford–Johnson: deque<Node> — recursive sort of the big chain                */
/* ========================================================================== */
/* Same as vector<Node>: we preserve .second (pair id) so the caller can rebuild
   pend; we use origIndex to reorder pend after sorting mainChain; we handle
   odd-sized chain with a Node straggler. */

void PmergeMe::_mergeInsertSortDeque(std::deque<std::pair<int, size_t> > &chain) {
    if (chain.size() <= 1)
        return;

    bool hasStraggler = (chain.size() % 2 != 0);
    Node straggler = Node(0, 0);
    if (hasStraggler) {
        straggler = chain.back();
        chain.pop_back();
    }

    pairAndSortDequeNode(chain);
    std::deque<Node> mainChain;
    std::deque<Node> pend;
    for (size_t i = 0; i < chain.size(); i += 2) {
        pend.push_back(chain[i]);
        mainChain.push_back(chain[i + 1]);
    }

    std::deque<Node> savedPend = pend;
    size_t maxId = 0;
    for (size_t j = 0; j < mainChain.size(); j++)
        if (mainChain[j].second > maxId)
            maxId = mainChain[j].second;
    std::vector<size_t> origIndex(maxId + 1, 0);
    for (size_t j = 0; j < mainChain.size(); j++)
        origIndex[mainChain[j].second] = j;

    _mergeInsertSortDeque(mainChain);

    pend.clear();
    for (size_t j = 0; j < mainChain.size(); j++)
        pend.push_back(savedPend[origIndex[mainChain[j].second]]);

    std::deque<Node> S;
    for (size_t i = 0; i < mainChain.size(); i++)
        S.push_back(std::make_pair(mainChain[i].first, mainChain[i].second));
    if (pend.size() > 0)
        S.insert(S.begin(), std::make_pair(pend[0].first, pend[0].second));

    size_t count = (pend.size() > 1) ? (pend.size() - 1) : 0;
    std::vector<size_t> order = buildJacobsthalOrder(count);
    for (size_t k = 0; k < order.size(); k++) {
        size_t i = order[k];
        std::deque<Node>::iterator posBig = std::find_if(S.begin(), S.end(),
            FindByValueAndId(mainChain[i].first, mainChain[i].second));
        if (posBig == S.end())
            throw std::runtime_error("Error: partner big not found in main chain");
        Node node = std::make_pair(pend[i].first, pend[i].second);
        std::deque<Node>::iterator insertPos = std::lower_bound(S.begin(), posBig, node, CompareNode());
        S.insert(insertPos, node);
    }

    if (hasStraggler) {
        std::deque<Node>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler, CompareNode());
        S.insert(pos, straggler);
    }

    chain.clear();
    for (size_t idx = 0; idx < S.size(); idx++)
        chain.push_back(S[idx]);
}
