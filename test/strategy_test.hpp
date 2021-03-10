#ifndef __STRATEGY_TEST_HPP__
#define __STRATEGY_TEST_HPP__



#include "gtest/gtest.h"


#include "../header/Moment.hpp"
#include "../header/Subtask.hpp"
#include "../header/Task.hpp"
#include "../header/WeekSpatial.hpp"
#include "../header/control.hpp"
#include "../header/display.hpp"
#include "../header/start_cell.hpp"
#include "../header/middle_cell.hpp"
#include "../header/end_cell.hpp"
#include "../header/empty_cell.hpp"
#include "../header/single_cell.hpp"
#include "../header/commandEditDescription.hpp"


TEST(BaseCell, getAssociatedID) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new SingleCell(temp);
	EXPECT_EQ(test->getAssociatedID(), -1);
}

TEST(BaseCell, sizeOfMenu) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new SingleCell(temp);
        EXPECT_EQ(test->sizeOfMenu(), 0);
}




	


TEST(SingleCell, drawTopCell) {
        Cell* test = new SingleCell();
	std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
	std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m+-----+\x1B[0m");
}


TEST(SingleCell, drawBottomCell) {
        Cell* test = new SingleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m+-----+\x1B[0m");
}


TEST(SingleCell, drawMiddleCell) {
        Cell* test = new SingleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m|     |\x1B[0m");
}


TEST(SingleCell, drawMiddleCellTitle) {
	Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);	
        Cell* test = new SingleCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34me\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mT\x1B[0m\x1B[;34m|\x1B[0m");



}

TEST(SingleCell, highlightTopCell) {
        Cell* test = new SingleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(SingleCell, highlightBottomCell) {
        Cell* test = new SingleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(SingleCell, highlightMiddleCell) {
        Cell* test = new SingleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*     *\x1B[0m");
}


TEST(SingleCell, highlightMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new SingleCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32me\x1B[0m\x1B[;32ms\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32mT\x1B[0m\x1B[;32m*\x1B[0m");



}




TEST(StartCell, drawTopCell) {
        Cell* test = new StartCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m+------\x1B[0m");
}

TEST(StartCell, drawBottomCell) {
        Cell* test = new StartCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m+------\x1B[0m");
}
TEST(StartCell, drawMiddleCell) {
        Cell* test = new StartCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m|      \x1B[0m");
}
TEST(StartCell, drawMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout,   "\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34me\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mT\x1B[0m\x1B[;34mi\x1B[0m");
}

TEST(StartCell, highlightTopCell) {
        Cell* test = new StartCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(StartCell, highlightBottomCell) {
        Cell* test = new StartCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(StartCell, highlightMiddleCell) {
        Cell* test = new StartCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*      \x1B[0m");
}


TEST(StartCell, highlightMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32me\x1B[0m\x1B[;32ms\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32mT\x1B[0m\x1B[;32mi\x1B[0m");



}





TEST(MiddleCell, drawTopCell) {
        Cell* test = new MiddleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m-------\x1B[0m");
}

TEST(MiddleCell, drawBottomCell) {
        Cell* test = new MiddleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m-------\x1B[0m");
}
TEST(MiddleCell, drawMiddleCell) {
        Cell* test = new MiddleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "       ");
}
TEST(MiddleCell, drawMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new MiddleCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout,   "\x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m    ");
}

TEST(MiddleCell, highlightTopCell) {
        Cell* test = new MiddleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(MiddleCell, highlightBottomCell) {
        Cell* test = new MiddleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(MiddleCell, highlightMiddleCell) {
        Cell* test = new MiddleCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "       ");
}


TEST(MiddleCell, highlightMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new MiddleCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m    ");



}




TEST(EndCell, drawTopCell) {
        Cell* test = new EndCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m------+\x1B[0m");
}

TEST(EndCell, drawBottomCell) {
        Cell* test = new EndCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m------+\x1B[0m");
}
TEST(EndCell, drawMiddleCell) {
        Cell* test = new EndCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m      |\x1B[0m");
}
TEST(EndCell, drawMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new EndCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout,   "\x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m   \x1B[;34m|\x1B[0m");
}

TEST(EndCell, highlightTopCell) {
        Cell* test = new EndCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightTopCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(EndCell, highlightBottomCell) {
        Cell* test = new EndCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightBottomCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*******\x1B[0m");
}


TEST(EndCell, highlightMiddleCell) {
        Cell* test = new EndCell();
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCell();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m      *\x1B[0m");
}


TEST(EndCell, highlightMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* test = new EndCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        test->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m   \x1B[;32m*\x1B[0m");
}

TEST(MultipleCells, OneStartCellOneEndCellHighlightMiddleCellTitle) {
	Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* endTest = new EndCell(temp);
	Cell* startTest = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        startTest->highlightMiddleCellTitle();
	endTest->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32me\x1B[0m\x1B[;32ms\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32mT\x1B[0m\x1B[;32mi\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m   \x1B[;32m*\x1B[0m");
}

TEST(MultipleCells, OneStartCellOneEndCellDrawMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* endTest = new EndCell(temp);
        Cell* startTest = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        startTest->drawMiddleCellTitle();
        endTest->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34me\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mT\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m   \x1B[;34m|\x1B[0m");
}

TEST(MultipleCells, OneStartCellOneMiddleCellOneEndCellHighlightMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* endTest = new EndCell(temp);
	Cell* middleTest = new MiddleCell(temp);
        Cell* startTest = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        startTest->highlightMiddleCellTitle();
	middleTest->highlightMiddleCellTitle();
        endTest->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32me\x1B[0m\x1B[;32ms\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32mT\x1B[0m\x1B[;32mi\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m    \x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m   \x1B[;32m*\x1B[0m");
}

TEST(MultipleCells, OneStartCellOneMiddleCellOneEndCellDrawMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* endTest = new EndCell(temp);
	Cell* middleTest = new MiddleCell(temp);
        Cell* startTest = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        startTest->drawMiddleCellTitle();
	middleTest->drawMiddleCellTitle();
        endTest->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34me\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mT\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m    \x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m   \x1B[;34m|\x1B[0m");
}

TEST(MultipleCells, OneStartCellTwoMiddleCellOneEndCellHighlightMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* endTest = new EndCell(temp);
        Cell* middleTest = new MiddleCell(temp);
        Cell* startTest = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        startTest->highlightMiddleCellTitle();
        middleTest->highlightMiddleCellTitle();
	middleTest->highlightMiddleCellTitle(2);
        endTest->highlightMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;32m*\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32me\x1B[0m\x1B[;32ms\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32mT\x1B[0m\x1B[;32mi\x1B[0m\x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m           \x1B[;32mt\x1B[0m\x1B[;32ml\x1B[0m\x1B[;32me\x1B[0m   \x1B[;32m*\x1B[0m");
}

TEST(MultipleCells, OneStartCellTwoMiddleCellOneEndCellDrawMiddleCellTitle) {
        Task* temp = new Task("testTitle","testDescription","testClassification",1,1,100,200,0,3);
        Cell* endTest = new EndCell(temp);
        Cell* middleTest = new MiddleCell(temp);
        Cell* startTest = new StartCell(temp);
        std::stringstream buffer;
        std::streambuf *sbuf = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
        startTest->drawMiddleCellTitle();
        middleTest->drawMiddleCellTitle();
	middleTest->drawMiddleCellTitle(2);
        endTest->drawMiddleCellTitle();
        std::cout.rdbuf(sbuf);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34me\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mT\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m           \x1B[;34mt\x1B[0m\x1B[;34ml\x1B[0m\x1B[;34me\x1B[0m   \x1B[;34m|\x1B[0m");
}










#endif
