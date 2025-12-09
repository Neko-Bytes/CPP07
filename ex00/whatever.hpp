/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:11:08 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/09 23:36:44 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// What are C++ Templates?
// -----------------------
// Templates are a feature that allows writing generic programs(writing codes
// independent of data type).
// Instead of writing a specific function for each data type (int, float,
// string), we define a "blueprint" using a placeholder type (T).
//
// When the function is used, the compiler generates the actual code for that
// specific type. This is called "instantiation".
//
// Benefits:
// 1. Code Reusability: Write once, use for any type.
// 2. Type Safety: The compiler checks types at compile time. (more about this
//    explained in ex01)

template <typename T> void swap(T &var1, T &var2) {
  T temp;

  temp = var1;
  var1 = var2;
  var2 = temp;
}

template <typename T> const T &max(const T &var1, const T &var2) {
  return ((var1 > var2) ? var1 : var2);
}

template <typename T> const T &min(const T &var1, const T &var2) {
  return ((var1 > var2) ? var2 : var1);
}
