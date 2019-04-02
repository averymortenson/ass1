/**
 * main.cpp is not used all test cases are in xxxcatch.cpp files
 * @author TODO
 * @date TODO
 */


#include <iostream>

#ifdef USE_CATCH
#include "catch.hpp"


#else

// forward declaration of testAll
// which is defined in turtleprogramcatch
void testAll();

// If not using CATCH framework, call functions directly
int main() {
  testAll();
  std::cout << "Done!" << std::endl;
  return 0;
}

#endif  // USE_CATCH
