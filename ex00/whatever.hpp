/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:11:08 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/08 22:15:15 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
