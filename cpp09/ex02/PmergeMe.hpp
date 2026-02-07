/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:21:20 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/07 13:56:51 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*
 * PmergeMe — Ford–Johnson merge-insertion sort (TAOCP Vol.3).
 *
 * High-level algorithm (no std::sort; pure Ford–Johnson for defense):
 * 1. Pair elements (a, b) with a <= b; if size is odd, set aside one "straggler".
 * 2. Sort the "big" elements by recursively applying this same algorithm (not std::sort).
 * 3. Build main chain from sorted bigs; insert the first small at the front.
 * 4. Insert remaining smalls in Jacobsthal order, each via binary search (lower_bound)
 *    before its partner big (so comparisons are bounded and minimal).
 * 5. Reinsert the straggler with lower_bound into the final sorted sequence.
 *
 * We implement it for two containers (vector and deque) as required; timing includes
 * copy + sort per container so the comparison is fair.
 */

#include <string>
#include <vector>
#include <deque>
#include <cstddef>
#include <utility>
#include <time.h>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        /* Sort the sequence with both vector and deque; print Before/After and timings. */
        void sort(const std::vector<int> &sequence);
        void sort(const std::deque<int> &sequence);

    private:
        /* The two containers we sort (same algorithm, different container). */
        std::vector<int> _vec;
        std::deque<int> _deque;

        /* Ford–Johnson on vector<int> (entry) and on vector<Node> (recursive big chain). */
        void _mergeInsertSortVector(std::vector<int> &vec);
        void _mergeInsertSortVector(std::vector<std::pair<int, size_t> > &chain);

        /* Ford–Johnson on deque<int> (entry) and on deque<Node> (recursive big chain). */
        void _mergeInsertSortDeque(std::deque<int> &deq);
        void _mergeInsertSortDeque(std::deque<std::pair<int, size_t> > &chain);

        long long _getTime() const;
        void _displayTime(const std::string &containerName, size_t size, long long timeNs) const;
        void _printSequence(const std::vector<int> &sequence, const std::string &title) const;
        void _printSequence(const std::deque<int> &sequence, const std::string &title) const;
};

#endif
