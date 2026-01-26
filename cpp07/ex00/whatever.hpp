/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:55:09 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/25 23:55:11 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
    return;
}

template <typename T>
T min(const T& a, const T& b) {
    return a < b ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

#endif