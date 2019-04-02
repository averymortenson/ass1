/**
 * TODO file documentation
 *
 * @author TODO
 * @date TODO
 */

#ifdef USE_CATCH

#include "catch.hpp"
#include "turtleprogram.h"

// TODO write test cases for all functions
TEST_CASE("tp constructors") {
}

TEST_CASE("tp equality") {
}

TEST_CASE("tp math") {
}

#else

// not using CATCH, usiong assert statements to check the program
#include <cassert>
#include "turtleprogram.h"

void testConstructors() {
  // TODO
}

void testEquality() {
  // TODO
}

void testAll() {
  assert(1 == 1);
  // this assert should fail!
  assert(1 == 5);
  testConstructors();
  testEquality();
}



#endif  // USE_CATCH
