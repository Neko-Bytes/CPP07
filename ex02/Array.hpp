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

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cstddef>

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

  Array() : _arr(NULL), _size(0) {}

  Array(unsigned int n) : _size(n) {
    if (n > 0)
      _arr = new T[n]();
    else
      _arr = NULL;
  }

  Array(const Array &other) : _size(other._size) {
    if (_size > 0) {
      _arr = new T[_size]();
      for (unsigned int i = 0; i < _size; ++i) {
        _arr[i] = other._arr[i];
      }
    } else {
      _arr = NULL;
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      T *new_arr = NULL;
      if (other._size > 0) {
        new_arr = new T[other._size]();
        for (unsigned int i = 0; i < other._size; ++i) {
          new_arr[i] = other._arr[i];
        }
      }
      delete[] _arr;
      _arr = new_arr;
      _size = other._size;
    }
    return (*this);
  }

  ~Array() { delete[] _arr; }

  // @brief Member functions

  unsigned int size() const { return (_size); }

  const T &operator[](unsigned int index) const {
    if (index >= _size)
      throw std::out_of_range("Index out of bounds");
    return (_arr[index]);
  }

  T &operator[](unsigned int index) {
    if (index >= _size)
      throw std::out_of_range("Index out of bounds");
    return (_arr[index]);
  }
};

#endif
