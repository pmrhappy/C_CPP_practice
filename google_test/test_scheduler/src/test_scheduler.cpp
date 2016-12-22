#include <iostream>
#include "gtest/gtest.h"

// The following lines pull in the real gtest *.cc files.
#include "src/gtest.cc"
#include "src/gtest-death-test.cc"
#include "src/gtest-filepath.cc"
#include "src/gtest-port.cc"
#include "src/gtest-printers.cc"
#include "src/gtest-test-part.cc"
#include "src/gtest-typed-test.cc"

#include "../../main_scheduler/src/scheduler.h"

// Verifies that the command line flag variables can be accessed
// in code once <gtest/gtest.h> has been #included.
// Do not move it after other #includes.

int NUM_TOTAL_PROCESS=176;
int NUM_JOB=6;
TEST(BasicTest, DISABLED_ResultComparison) {
	int const result_size=NUM_TOTAL_PROCESS;


	// for g++ compile -O0
	int expected_result[] = {2, 3, 3, 0, 4, 5, 5, 1, 5, 4, 5, 5, 3, 3, 2, 0, 0,
			 0, 0, 0, 3, 0, 3, 0, 4, 4, 1, 1, 1, 0, 0, 0, 0, 0,
			 0, 5, 5, 2, 2, 4, 5, 5, 3, 3, 3, 0, 5, 5, 5, 0, 0,
			 2, 3, 1, 0, 3, 3, 3, 3, 3, 3, 0, 0, 3, 4, 4, 5, 1,
			 4, 0, 5, 5, 3, 3, 4, 4, 1, 1, 0, 0, 5, 1, 0, 0, 4,
			 4, 1, 3, 3, 3, 5, 3, 3, 2, 2, 4, 4, 5, 5, 5, 2, 1,
			 3, 3, 0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 0, 0, 2, 3, 4,
			 3, 0, 4, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 4, 4, 3,
			 3, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 4, 4, 1,
			 1, 1, 1, 1, 4, 4, 2, 0, 0, 0, 0, 0, 2, 4, 4, 4, 2,
			 2, 2, 2, 2, 2, 2};

	Process *result = scheduler_main(new Info(0, 0, nullptr))->process;

	for(int index=0 ; index<result_size ; index++)
		EXPECT_EQ( expected_result[index], result[index].job );


	//EXPECT_TRUE( expected_result[1] == result[1] );
	//EXPECT_TRUE(dummy || !dummy);  // Suppresses warning that dummy is unused.
}


GTEST_API_ main(int argc, char **argv) {

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

