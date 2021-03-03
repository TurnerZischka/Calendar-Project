#include "gtest/gtest.h"

#include "command_test.hpp"
#include "control_test.hpp"
#include "composite_test.hpp"
#include "strategy_test.hpp"




int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
