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
  // 1. Test Empty Array
  std::cout << "--- Empty Array Test ---" << std::endl;
  Array<int> empty;
  std::cout << "Empty size: " << empty.size() << std::endl;
  try {
    std::cout << empty[0] << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // 2. Test accessing array elements
  std::cout << "\n--- Integer Array Test ---" << std::endl;
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
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // 3. Test Const Array Access
  std::cout << "\n--- Const Array Test ---" << std::endl;
  Array<int> nonConstArr(3);
  for (unsigned int i = 0; i < nonConstArr.size(); i++) {
    nonConstArr[i] = (i + 1) * 100;
  }
  const Array<int> constArr = nonConstArr;
  for (unsigned int i = 0; i < constArr.size(); i++) {
    std::cout << "constArr[" << i << "] = " << constArr[i] << std::endl;
  }

  // 4. Test Deep Copy
  std::cout << "\n--- Deep Copy Test ---" << std::endl;
  Array<std::string> original(2);
  original[0] = "A";
  original[1] = "B";

  Array<std::string> copy = original;
  copy[0] = "Z";

  std::cout << "Original[0]: " << original[0] << " (should be A)" << std::endl;
  std::cout << "Copy[0]:     " << copy[0] << " (should be Z)" << std::endl;

  return 0;
}
