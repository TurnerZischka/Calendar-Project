#include "gtest/gtest.h"

#include "header/start_cell.hpp"
#include "header/middle_cell.hpp"
#include "header/end_cell.hpp"
#include "header/empty_cell.hpp"
#include "header/single_cell.hpp"

TEST(StartCellTest, drawCell) {
	Cell* test = new StartCell;

	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	test->drawTopCell();
	test->drawMiddleCell();
	test->drawBottomCell();
	std::string capturedStdout = buffer.str();	
	EXPECT_EQ(capturedStdout, "+----|    +----");
}

TEST(MiddleCellTest, drawCell) {
        Cell* test = new MiddleCell;

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        test->drawMiddleCell();
        test->drawBottomCell();
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "-----     -----");
}

TEST(EndCellTest, drawCell) {
        Cell* test = new EndCell;

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        test->drawMiddleCell();
        test->drawBottomCell();
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "----+    |----+");
}

TEST(EmptyCellTest, drawCell) {
        Cell* test = new EmptyCell;

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        test->drawMiddleCell();
        test->drawBottomCell();
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "               ");
}

TEST(SingleCellTest, drawCell) {
        Cell* test = new SingleCell;

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        test->drawMiddleCell();
        test->drawBottomCell();
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "+---+|   |+---+");
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
