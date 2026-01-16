/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:42:52 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/09 23:43:04 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> class Array {
private:
  T *_arr;

public:
  Array();
  Array(unsigned int n);
  Array(Array<T> *arr);
  Array &operator=(Array<T> *arr);
  ~Array();
};
