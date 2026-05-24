/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 06:44:45 by kmummadi          #+#    #+#             */
/*   Updated: 2026/01/16 07:02:12 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
  // 1. Test Integer Array and Initialization
  std::cout << "--- Integer Array Test ---" << std::endl;
  try {
    Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++) {
      numbers[i] = i * 10;
    }

    std::cout << "Element at index 2: " << numbers[2] << " (expected 20)"
              << std::endl;

    std::cout << "Attempting to access index 10..." << std::endl;
    std::cout << numbers[10] << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught expected exception: " << e.what() << std::endl;
  }

  // 2. Test Deep Copy
  std::cout << "\n--- Deep Copy Test ---" << std::endl;
  Array<std::string> original(2);
  original[0] = "A";
  original[1] = "B";

  Array<std::string> copy = original;
  copy[0] = "Z";

  std::cout << "Original[0]: " << original[0] << " (should be A)" << std::endl;
  std::cout << "Copy[0]:     " << copy[0] << " (should be Z)" << std::endl;

  // 3. Test Complex Assignment
  std::cout << "\n--- Assignment Operator Test ---" << std::endl;
  Array<double> d1(3);
  d1[0] = 1.1;

  Array<double> d2;
  d2 = d1;

  std::cout << "D2[0]: " << d2[0] << " (should be 1.1)" << std::endl;
  std::cout << "D2 Size: " << d2.size() << std::endl;

  return 0;
}
