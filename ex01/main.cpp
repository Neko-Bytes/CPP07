/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:20:20 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/09 23:40:36 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

// Simple function to print an integer
void printElement(int &i) { std::cout << i << "\n"; }

// Simple function to increment an integer
void incrementElement(int &i) { i++; }

int main(void) {
  int array[] = {1, 2, 3, 4, 5};

  // Call iter:
  iter(array, 5, incrementElement);
  iter(array, 5, printElement);

  return 0;
}
