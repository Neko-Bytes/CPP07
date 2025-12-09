/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:04:50 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/09 23:33:11 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// The iter function template
// Arguments:
// 1. address of an array
// 2. length of the array
// 3. function to call on each element

// Why use 'typename F' instead of a Function Pointer?
// -------------------------------------------------------------
// You might ask: Why not write `void iter(T* array, size_t len, void
// (*func)(T&))`?
//
// 1. Flexibility (The "Callable" Concept):
//    Using a template parameter `F` allows this function to accept ANY
//    callable:
//    - Raw Function Pointers: Standard C-style functions.
//    - Functors: Classes that overload `operator()`.
//    - Lambdas: Anonymous functions (e.g., `[](int& i){ i++; }`), which define
//    their own unique types.
//
// 2. Optimization (Inlining):
//    - Function Pointer: The compiler must make an indirect call at runtime
//    (dereference pointer -> jump). Since a pointer can change anytime, it
//    cannot be inlined.
//    Hence, It is hard to optimize.
//    - Template `F`: The specific type of the function is known at compile
//    time.
//      The compiler can often "inline" the code (paste the function body
//      directly into the loop), making it significantly faster.

template <typename T, typename F> void iter(T *arr, size_t len, F funct) {
  for (size_t i = 0; i < len; ++i)
    funct(arr[i]);
}
