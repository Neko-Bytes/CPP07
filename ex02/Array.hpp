/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:42:52 by kmummadi          #+#    #+#             */
/*   Updated: 2026/01/16 06:53:31 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstddef>

/**
 * @file Array.hpp
 * @brief Template class for a dynamic array with bounds checking.
 */

// @brief command: new T[n] creates an T* array of size[n]
// command: new T[n]() creates the array and sets the bits to default value.

template <typename T> class Array {
private:
  T *_arr;
  unsigned int _size;

public:
  // @brief Constructors and Destructors

  Array() : _arr(nullptr), _size(0) {};

  Array(unsigned int n) : _size(n) { _arr = new T[n](); }

  Array(const Array &other) : _size(other._size) {
    _arr = new T[_size]();
    for (size_t i = 0; i < _size; i++) {
      _arr[i] = other._arr[i];
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _arr;
      _size = other._size;
      _arr = new T[_size]();
      for (size_t i = 0; i < _size; i++) {
        _arr[i] = other._arr[i];
      }
    }
    return (*this);
  }

  ~Array() { delete[] _arr; }

  // @brief Member functions

  unsigned int size() const { return (_size); };

  const T &operator[](const unsigned int &index) const {
    if (index >= _size)
      throw std::out_of_range("Index out of bounds");
    return (_arr[index]);
  }

  T &operator[](const unsigned int &index) {
    if (index >= _size)
      throw std::out_of_range("Index out of bounds");
    return (_arr[index]);
  }
};
