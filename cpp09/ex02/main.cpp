/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:21:34 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/09 by wel-safa                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PmergeMe launcher: parse positive integers from argv, reject duplicates,
 * run Ford–Johnson sort with both std::vector and std::deque, print
 * Before / After and timing lines.
 */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <set>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vecSeq;
    std::deque<int> deqSeq;
    std::set<int> seen;

    for (int i = 1; i < argc; ++i) {
        char *endptr;
        errno = 0;
        long num = std::strtol(argv[i], &endptr, 10);

        /* Reject: overflow, no digits, trailing junk, <1 or > INT_MAX */
        if (errno == ERANGE || endptr == argv[i] || *endptr != '\0' ||
            num <= 0 || num > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        int val = static_cast<int>(num);

        /* Remove duplicates */
        /* check if the value is already in the set, if yes, ignore it 
        else add it to the sequence */
        if (seen.find(val) == seen.end()) {
            seen.insert(val);
            vecSeq.push_back(val);
            deqSeq.push_back(val);
        }
    }

    try {
        PmergeMe sorter;
        sorter.sort(vecSeq, deqSeq);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
