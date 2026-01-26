/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:47 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/26 00:11:35 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>

template <typename T, typename F>
void iter(T* array, const size_t length, F f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template <typename T, typename F>
void iter(const T* array, const size_t length, F f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif