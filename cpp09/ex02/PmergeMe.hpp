/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:21:20 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/09 by wel-safa                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*
 * PmergeMe — Ford–Johnson merge-insertion sort (TAOCP Vol.3, p.184).
 *
 * Algorithm (no std::sort anywhere; pure Ford–Johnson):
 *   i)   Make floor(n/2) pairwise comparisons; if n is odd, set one aside.
 *   ii)  Recursively sort the floor(n/2) larger elements by merge-insertion.
 *   iii) Insert smaller elements into the main chain via bounded binary
 *        insertion in Jacobsthal order. Each pend[k] is searched only in
 *        [0, pos_of_partner_big) — no linear scans, no find_if.
 *
 * Duplicates are rejected in main, so all values are unique. This lets
 * us work with plain int (no Node/pair_id wrappers) and reconstruct
 * pairings by value after recursion.
 *
 * Two containers (std::vector and std::deque) as required by the subject.
 */

#include <string>
#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        /* Sort with both containers; print Before/After and timing lines. */
        void sort(const std::vector<int> &vec, const std::deque<int> &deq);

    private:
        std::vector<int> _vec;
        std::deque<int>  _deque;

        /* Ford–Johnson: one function per container (no templates, no Node overloads). */
        void _mergeInsertSortVector(std::vector<int> &c);
        void _mergeInsertSortDeque(std::deque<int> &c);

        long long _getTime() const;
        void _displayTime(const std::string &name, size_t size, long long ns) const;
        void _printSequence(const std::vector<int> &seq, const std::string &title) const;
};

#endif
