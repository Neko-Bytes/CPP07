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

// #include "Array.hpp"
// #include <iostream>
// #include <string>
//
// int main() {
//   // 1. Test Integer Array and Initialization
//   std::cout << "--- Integer Array Test ---" << std::endl;
//   try {
//     Array<int> numbers(5);
//     std::cout << "Size: " << numbers.size() << std::endl;
//
//     for (unsigned int i = 0; i < numbers.size(); i++) {
//       numbers[i] = i * 10;
//     }
//
//     std::cout << "Element at index 2: " << numbers[2] << " (expected 20)"
//               << std::endl;
//
//     std::cout << "Attempting to access index 10..." << std::endl;
//     std::cout << numbers[10] << std::endl;
//   } catch (const std::exception &e) {
//     std::cerr << "Caught expected exception: " << e.what() << std::endl;
//   }
//
//   // 2. Test Deep Copy
//   std::cout << "\n--- Deep Copy Test ---" << std::endl;
//   Array<std::string> original(2);
//   original[0] = "A";
//   original[1] = "B";
//
//   Array<std::string> copy = original;
//   copy[0] = "Z";
//
//   std::cout << "Original[0]: " << original[0] << " (should be A)" <<
//   std::endl; std::cout << "Copy[0]:     " << copy[0] << " (should be Z)" <<
//   std::endl;
//
//   // 3. Test Complex Assignment
//   std::cout << "\n--- Assignment Operator Test ---" << std::endl;
//   Array<double> d1(3);
//   d1[0] = 1.1;
//
//   Array<double> d2;
//   d2 = d1;
//
//   std::cout << "D2[0]: " << d2[0] << " (should be 1.1)" << std::endl;
//   std::cout << "D2 Size: " << d2.size() << std::endl;
//
//   return 0;
// }

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750
int main(int, char **) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror; //
  return 0;
}
