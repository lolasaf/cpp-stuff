/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:51:44 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/09 by wel-safa                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>



/* ========================================================================== */
/* Orthodox canonical form                                                     */
/* ========================================================================== */

PmergeMe::PmergeMe() : _vec(), _deque() {}

PmergeMe::PmergeMe(const PmergeMe &o) : _vec(o._vec), _deque(o._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &o) {
    if (this != &o) {
        _vec = o._vec;
        _deque = o._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


/* ========================================================================== */
/* Jacobsthal insertion order                                                 */
/* ========================================================================== */

/*
 * Referenced from: TAOCP Vol.3, p.184, eq.11-13
 * Ford–Johnson inserts pend elements in a specific order derived from
 * Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
 *     → 0, 1, 1, 3, 5, 11, 21, 43, ...
 *
 * BLOCK BOUNDARIES (t_k)
 * ──────────────────────
 * The sequence t_k = (2^(k+1) + (-1)^k) / 3   (TAOCP eq.13)
 *     → 1, 3, 5, 11, 21, 43, ...
 * defines which pend elements belong to each insertion block:
 *   Block 1: b_3, b_2         (indices t_2=3  down to t_1+1=2)
 *   Block 2: b_5, b_4         (indices t_3=5  down to t_2+1=4)
 *   Block 3: b_11, ..., b_6   (indices t_4=11 down to t_3+1=6)
 *   Block 4: b_21, ..., b_12  (indices t_5=21 down to t_4+1=12)
 *   etc.
 *
 * WHY THIS ORDER MINIMIZES COMPARISONS
 * ─────────────────────────────────────
 * The key identity is (TAOCP eq.12):
 *     t_{k-1} + t_k = 2^k
 *
 * When we insert b_{t_k} (first in block k), the main chain before its
 * partner a_{t_k} contains:
 *   - (t_k - 1)  sorted bigs before a_{t_k}
 *   - t_{k-1}    pend elements already inserted from previous blocks
 *   Total = (t_k - 1) + t_{k-1} = 2^k - 1
 *
 * A binary search over (2^k - 1) elements takes at most
 *     ceil(log2(2^k)) = k comparisons.
 *
 * By inserting the block in descending order (t_k down to t_{k-1}+1),
 * each subsequent element in the block also searches a range of at most
 * (2^k - 1) elements — because earlier inserts in the same block only
 * add to the region BEFORE the current element's partner, not after.
 * So every element in block k costs at most k comparisons.
 *
 * This is what makes Ford–Johnson comparison-optimal for small n
 * (TAOCP eq.18-20): F(n) = ceil(lg(3n/4)) per additional element,
 * and F(n) = ceil(lg n!) for n <= 11 and n = 20, 21.
 *
 * EXAMPLE
 * ───────
 * count=4  → [2, 1, 4, 3]
 * count=10 → [2, 1, 4, 3, 10, 9, 8, 7, 6, 5]
 *
 * In this function, the Jacobsthal recurrence J(n)=J(n-1)+2*J(n-2) is
 * used to compute block boundaries: milestone = J(k) - 1 gives the t_k
 * values. Indices within each block are pushed in descending order.
 */
 static std::vector<size_t> buildJacobsthalOrder(size_t count) {
    std::vector<size_t> order;
    if (count == 0)
        return order;
    order.reserve(count);

    size_t jPrev = 1, jCur = 1;  /* first 2 Jacobsthal nums: J(1)=1, J(2)=1 */
    size_t prevEnd = 0;

    while (prevEnd < count) {
        size_t jNext = jCur + 2 * jPrev;  /* J(n) = J(n-1) + 2 * J(n-2) */
        jPrev = jCur;
        jCur = jNext;

        size_t milestone = jCur - 1;  /* block boundary (t_k) */
        size_t end = (milestone < count) ? milestone : count; // if milestone is greater than count, set end to count
        size_t start = prevEnd + 1; // start from the next index after the previous end

        /* Push indices from end down to start (descending within block). */
        for (size_t i = end; i >= start && i != 0; i--)
            order.push_back(i);

        prevEnd = end;
    }
    return order;
}

/* ========================================================================== */
/* sort(): copy into each container, time independently (data mgmt + sort)    */
/* ========================================================================== */

void PmergeMe::sort(const std::vector<int> &vec, const std::deque<int> &deq) {
    _printSequence(vec, "Before");

    /* Time vector: copy + Ford–Johnson sort. */
    long long start = _getTime();
    _vec = vec;
    _mergeInsertSortVector(_vec);
    long long durVec = _getTime() - start;

    /* Time deque: copy + Ford–Johnson sort. */
    start = _getTime();
    //_deque = deq;
    _deque.assign(vec.begin(), vec.end()); // 
    _mergeInsertSortDeque(_deque);
    long long durDeq = _getTime() - start;

    _printSequence(_vec, "After");
    _displayTime("std::vector", vec.size(), durVec);
    _displayTime("std::deque", deq.size(), durDeq);
}

/* ========================================================================== */
/* Timing and output                                                          */
/* ========================================================================== */

/* Monotonic clock in nanoseconds */
long long PmergeMe::_getTime() const {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000LL + (long long)ts.tv_nsec;
}

/* Convert nanoseconds to microseconds with 5 dec. places */
void PmergeMe::_displayTime(const std::string &name, size_t size, long long ns) const {
    std::cout << "Time to process a range of " << size
              << " elements with " << name << " : "
              << std::fixed << std::setprecision(4)
              << (static_cast<double>(ns) / 1000.0) << " us"
              << std::endl;
}

void PmergeMe::_printSequence(const std::vector<int> &seq, const std::string &title) const {
    std::cout << title << ":";
    for (size_t i = 0; i < seq.size(); i++) {
        std::cout << " " << seq[i];
        if (i > 10) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;
}

/* ========================================================================== */
/* Ford–Johnson merge-insertion sort on std::vector<int>                      */
/* ========================================================================== */

/*
 * TAOCP Vol.3 p.184 — merge insertion for n elements:
 *   i)   Make floor(n/2) pairwise comparisons. If n is odd, set one aside.
 *   ii)  Recursively sort the larger elements by merge-insertion.
 *   iii) Insert smaller elements into the main chain using bounded binary
 *        insertion in Jacobsthal order. The bound for pend[k] is the current
 *        position of its partner big in the chain: search only [0, pos[k]).
 *
 * Key design choices:
 *   - No Node/pair type: since all values are unique (duplicates rejected in
 *     main), we can reconstruct pend ordering by matching big values after
 *     recursion. This removes find_if / FindById entirely.
 *   - pos[i] gives O(1) lookup for the current position of big[i] in chain.
 *     After each insert, pos[] is updated in O(m) — dominated by the O(n)
 *     vector::insert anyway. Comparisons remain minimal (bounded search).
 */
void PmergeMe::_mergeInsertSortVector(std::vector<int> &c) {
    /* Base case: 0 or 1 elements are already sorted. */
    if (c.size() <= 1)
        return;

    /* ── Step i: pairwise comparisons ─────────────────────────────────────── */

    /* If n is odd, save the last element as a "straggler"; it has no pair.
       We'll reinsert it at the end with a full binary search (TAOCP step i). */
    bool hasStrag = (c.size() % 2 != 0);
    int strag = 0;
    if (hasStrag) {
        strag = c.back();
        c.pop_back();
    }

    /* Pair consecutive elements; swap so each pair is (small, big).
       This uses exactly floor(n/2) comparisons — one per pair. */
    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        if (c[i] > c[i + 1])
            std::swap(c[i], c[i + 1]);
    }

    /* Split into pend (smalls) and big (bigs), keeping the pairing implicit:
       pend[k] is the small partner of big[k]. */
    std::vector<int> pend, big;
    for (size_t i = 0; i < c.size(); i += 2) {
        pend.push_back(c[i]);       /* small of pair k = i/2 */
        big.push_back(c[i + 1]);    /* big   of pair k = i/2 */
    }

    /* ── Step ii: recursively sort the larger elements ────────────────────── */

    /* Save the original pairing so we can reconstruct pend after sorting big.
       Since all values are unique (duplicates removed), each big value maps
       unambiguously to exactly one small partner. */
    std::vector<int> savedBig  = big;
    std::vector<int> savedPend = pend;

    _mergeInsertSortVector(big);  /* recursive Ford–Johnson on the bigs */

    /* Rebuild pend to match the now-sorted big ordering.
       big[] is sorted after recursion, so for each original pair (savedBig[k],
       savedPend[k]) we binary-search big[] to find savedBig[k]'s new position j,
       then set pend[j] = savedPend[k]. O(m log m) total — no linear scans. */
    pend.resize(big.size()); // resize pend to the size of the bigs (to match the sorted big ordering)
    for (size_t k = 0; k < savedBig.size(); k++) {
        size_t j = static_cast<size_t>(
            std::lower_bound(big.begin(), big.end(), savedBig[k]) - big.begin());
        pend[j] = savedPend[k];
    }

    /* ── Step iii: insert pend into the main chain ────────────────────────── */

    /* The main chain starts as the sorted bigs: big[0] ≤ big[1] ≤ ... ≤ big[m-1].
       pos[i] = current index of big[i] in the chain.
       This gives O(1) partner lookup — no find_if, no linear scan. */
    std::vector<int> chain = big; // the main chain starts as the sorted bigs
    std::vector<size_t> pos(big.size()); // pos[i] = current index of big[i] in the chain
    for (size_t i = 0; i < big.size(); i++) // initialize pos to the index of the bigs
        pos[i] = i;

    /* Insert pend[0] (= b_1 in TAOCP notation) at the front.
       We know pend[0] < big[0] (from pairing), and big[0] is the smallest
       sorted big, so pend[0] belongs before everything. Zero comparisons.
       TAOCP: "call b_1 and the a's the main chain." */
    if (!pend.empty()) {
        chain.insert(chain.begin(), pend[0]); // insert pend[0] at the front
        for (size_t i = 0; i < pos.size(); i++) // all bigs shifted right by 1
            pos[i]++;
    }

    /* Insert remaining pend elements in Jacobsthal order (TAOCP eq.11).
       For pend[idx]: partner big is at chain[pos[idx]].
       We know pend[idx] < big[idx] = chain[pos[idx]], so pend[idx] must be
       somewhere in chain[0 .. pos[idx]-1]. Binary search only that prefix.
       The Jacobsthal schedule ensures this prefix has at most 2^k - 1 elements,
       so each insertion uses at most k comparisons (TAOCP eq.18). */
    size_t pendCount = (pend.size() > 1) ? (pend.size() - 1) : 0;
    std::vector<size_t> order = buildJacobsthalOrder(pendCount);

    for (size_t k = 0; k < order.size(); k++) {
        size_t idx   = order[k];     /* which pend element to insert     */
        size_t bound = pos[idx];     /* partner big's current position   */

        /* Bounded binary search in [0, bound). */
        std::vector<int>::iterator beg = chain.begin();
        std::vector<int>::iterator end = beg + static_cast<long>(bound);
        std::vector<int>::iterator ins = std::lower_bound(beg, end, pend[idx]);
        size_t insIdx = static_cast<size_t>(ins - beg);

        chain.insert(ins, pend[idx]);

        /* Update pos[]: every big at or after insIdx shifted right by 1. */
        for (size_t j = 0; j < pos.size(); j++) {
            if (pos[j] >= insIdx)
                pos[j]++;
        }
    }

    /* Reinsert straggler (no partner bound).
       Full binary search over the entire chain. */
    if (hasStrag) {
        std::vector<int>::iterator it = std::lower_bound(
            chain.begin(), chain.end(), strag);
        chain.insert(it, strag);
    }

    c = chain; // assign the sorted chain to the container
}

/* ========================================================================== */
/* Ford–Johnson merge-insertion sort on std::deque<int>                        */
/* ========================================================================== */

/*
 * Identical algorithm to the vector version, operating on std::deque.
 */
void PmergeMe::_mergeInsertSortDeque(std::deque<int> &c) {
    if (c.size() <= 1)
        return;

    /* ── Step i: pairwise comparisons ─────────────────────────────────────── */

    bool hasStrag = (c.size() % 2 != 0);
    int strag = 0;
    if (hasStrag) {
        strag = c.back();
        c.pop_back();
    }

    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        if (c[i] > c[i + 1])
            std::swap(c[i], c[i + 1]);
    }

    std::vector<int> pend;
    std::deque<int>  big;
    for (size_t i = 0; i < c.size(); i += 2) {
        pend.push_back(c[i]);
        big.push_back(c[i + 1]);
    }

    /* ── Step ii: recursive sort of bigs ──────────────────────────────────── */

    std::vector<int> savedBig(big.begin(), big.end());
    std::vector<int> savedPend = pend;

    _mergeInsertSortDeque(big);

    /* Rebuild pend: big[] is sorted, binary-search each savedBig[k] to find
       its new position j, then pend[j] = savedPend[k]. */
    pend.resize(big.size());
    for (size_t k = 0; k < savedBig.size(); k++) {
        size_t j = static_cast<size_t>(
            std::lower_bound(big.begin(), big.end(), savedBig[k]) - big.begin());
        pend[j] = savedPend[k];
    }

    /* ── Step iii: insert pend into the main chain ────────────────────────── */

    std::deque<int> chain = big; // the main chain starts as the sorted bigs
    // pos[i] gives O(1) lookup for the current position of big[i] in chain
    // pos[i] = current index of big[i] in the chain
    std::vector<size_t> pos(big.size());
    for (size_t i = 0; i < big.size(); i++)
        pos[i] = i;

    /* Insert pend[0] at front (deque::push_front is O(1)) */
    if (!pend.empty()) {
        chain.push_front(pend[0]);
        // all bigs shifted right by 1
        for (size_t i = 0; i < pos.size(); i++)
            pos[i]++;
    }

    /* Jacobsthal-order bounded insertions. */
    size_t pendCount = (pend.size() > 1) ? (pend.size() - 1) : 0; // get pend count
    std::vector<size_t> order = buildJacobsthalOrder(pendCount); // get the order of the pend elements

    // insert pend elements in Jacobsthal order
    for (size_t k = 0; k < order.size(); k++) {
        size_t idx   = order[k]; // which pend element to insert
        size_t bound = pos[idx]; // partner big's current position

        std::deque<int>::iterator beg = chain.begin(); // start of the chain
        std::deque<int>::iterator endIt = beg + static_cast<long>(bound); // end of the chain
        std::deque<int>::iterator ins = std::lower_bound(beg, endIt, pend[idx]);
        size_t insIdx = static_cast<size_t>(ins - beg);

        chain.insert(ins, pend[idx]);

        for (size_t j = 0; j < pos.size(); j++) {
            if (pos[j] >= insIdx)
                pos[j]++;
        }
    }

    if (hasStrag) {
        std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), strag);
        chain.insert(it, strag);
    }

    c = chain; // assign the sorted chain to the container
}
