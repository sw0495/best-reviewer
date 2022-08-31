#include <iostream>
#include "hello.h"

void print_hello()
{
    std::cout << "hello_add3\n";
}

// Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}