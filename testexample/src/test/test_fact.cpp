/*
  Simple demonstration of Google Test.
  Tests a factorial function.

  \author Richard Kelley
*/

#include "gtest/gtest.h"

#include "factorial.h"

TEST(FactorialTest, HandlesZero) {
  EXPECT_EQ(1, factorial(0));
}

TEST(FactorialTest, HandlesPositive) {
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(6, factorial(3));

  /*
    Note that 5! = 120, not 125. This shows two things: 

    1. What a failed test looks like. We'll change it in class to see
    what all tests passing looks like.

    2. When you start writing test code, you need to remember that it
    can be buggy too. You want to be careful when writing test code,
    so that you don't end up having to debug your test code.
  */
  EXPECT_EQ(125, factorial(5));
}

TEST(FactorialTest, HandlesNegative) {
  EXPECT_EQ(1, factorial(-354));
}
