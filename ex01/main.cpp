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

// function to print an integer
void printElement(int &i) { std::cout << i << "\n"; }

// function to increment an integer
void incrementElement(int &i) { i++; }

template <typename T> void print(const T &elem) { std::cout << elem << "\n"; }

class Awesome {
public:
  Awesome(void) : _n(42) {}
  int get(void) const { return this->_n; }

private:
  int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}

int main(void) {
  int array[] = {1, 2, 3, 4, 5};

  // Call iter:
  iter(array, 5, incrementElement);
  iter(array, 5, printElement);

  const int constArray[] = {0, 1, 2, 3, 4};
  iter(constArray, 5, print<int>);
  // iter(constArray, 5, incrementElement);

  Awesome awesomeArray[5];
  iter(awesomeArray, 5, print<Awesome>);

  return 0;
}
