#include "vec2.h"

#include "gtest/gtest.h"

TEST(Vec2Test, TestScalarMultCommutativity) {
  simphys::vec2 v1(2,2);
  simphys::vec2 v2 = 4 * v1;
  simphys::vec2 v3 = v1 * 4;

  EXPECT_EQ(v2.getX(), v3.getX());
  EXPECT_EQ(v2.getY(), v3.getY());

}
