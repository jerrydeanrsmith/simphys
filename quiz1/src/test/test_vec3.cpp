#include "vec3.h"

#include "gtest/gtest.h"

/*
  Note that even without proper implementations, this test will
  pass. Why is that? You should make the test pass because the code is
  correct, not because of trivial correctness conditions.
 */
TEST(Vec3Test, VectorAdditionCommutativity) {
  simphys::vec3 v1(1.0f, 2.0f, 3.0f);
  simphys::vec3 v2(4.0f, 5.0f, 6.0f);

  simphys::vec3 v3 = v1 + v2;
  simphys::vec3 v4 = v2 + v1;
  
  // EXPECT_FLOAT_EQ tests two floating-point numbers for equality and
  // is aware of numerical precision.
  EXPECT_FLOAT_EQ(v3.getX(), v4.getX());
  EXPECT_FLOAT_EQ(v3.getY(), v4.getY());
  EXPECT_FLOAT_EQ(v3.getZ(), v4.getZ());
}

/*
  TODO - put your tests here.
*/
