/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:21:34 by wel-safa          #+#    #+#             */
/*   Updated: 2026/02/07 13:26:13 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PmergeMe launcher: parse positive integers from argv, run Ford–Johnson sort
 * with both std::vector and std::deque, print Before/After and timings.
 */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: no arguments provided" << std::endl;
        return 1;
    }

    /* Parse each argument as a positive integer (subject: positive integers only). */
    std::vector<int> sequence;

    for (int i = 1; i < argc; ++i) {
        char *endptr;
        errno = 0;
        long num = std::strtol(argv[i], &endptr, 10);
        /* Reject: overflow (ERANGE), no digits (endptr == argv[i]), trailing junk (*endptr),
           non-positive, or above INT_MAX so it fits in int. */
        if (errno == ERANGE || endptr == argv[i] || *endptr != '\0' ||
            num <= 0 || num > INT_MAX) {
            std::cerr << "Error: all arguments must be +ve within int range" << std::endl;
            return 1;
        }
        sequence.push_back(static_cast<int>(num));
    }

    /* Sort with PmergeMe: prints Before, After (from vector), and time for each container. */
    try {
        PmergeMe pmergeMe;
        pmergeMe.sort(sequence);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
