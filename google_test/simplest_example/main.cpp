#include "gtest/gtest.h"

TEST(BasicTest, ResultComparison)
{
	int one = 1;
    const int expected_one = 1;
    ASSERT_FALSE(true); // fail: stop case here
    ASSERT_TRUE(true);
    EXPECT_TRUE(false);
    ASSERT_EQ(expected_one, one);
}

TEST(BasicTest, Example)
{
    EXPECT_TRUE(false); // fail: still running the rest of code of the case
    ASSERT_TRUE(false);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
