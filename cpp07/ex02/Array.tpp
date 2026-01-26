/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-safa <wel-safa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:55:45 by wel-safa          #+#    #+#             */
/*   Updated: 2026/01/26 00:55:48 by wel-safa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(size_t n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : array(new T[other._size]), _size(other._size) {
    for (size_t i = 0; i < _size; i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other)
        return *this;
    delete[] array;
    array = new T[other._size];
    _size = other._size;
    for (size_t i = 0; i < _size; i++) {
        array[i] = other.array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return array[index];
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}
