#ifndef __COMPOSITE_TEST_HPP__
#define __COMPOSITE_TEST_HPP__

#include "gtest/gtest.h"

//do not need to include Moment.hpp as it is included in the two below
#include "../header/Task.hpp"
#include "../header/Subtask.hpp"
#include <ctime>

TEST( TaskTest, basicCreate ){
    Task* temp = new Task("one", "two" , "three", 2, 8, 1000, 1200, 0, 0);
    time_t tempTime = mktime(&temp->tmStruct);

    EXPECT_EQ(tempTime, 1615226400);
}

TEST( TaskTest, changeCreate ){
    Task* temp = new Task("one", "two" , "three", 2, 8, 1000, 1200, 0, 0);
    temp->setStart(0700);
    temp->tmStruct.tm_hour=700/100;
    temp->tmStruct.tm_min = 700%100;
    time_t tempTime = mktime(&temp->tmStruct);

    EXPECT_EQ(tempTime, 1615215600);
}


TEST( SubtaskTest, SubtaskVectorSize ){
    Task* temp = new Task("one", "two" , "three", 2, 8, 1000, 1200, 0, 0);
    temp->AddSubtask("one");
    temp->AddSubtask("two");

    EXPECT_EQ(temp->getSubtaskSize(), 2);



}


TEST( SubtaskTest, SubtasRetunName ){
    Task* temp = new Task("one", "two" , "three", 2, 8, 1000, 1200, 0, 0);
    temp->AddSubtask("one");
    temp->AddSubtask("two");


    EXPECT_EQ(temp->getSubtaskNum(0), "one");
    EXPECT_EQ(temp->getSubtaskNum(1), "two");
}

TEST( SubtaskTest , checkExtraVariables ){
    Task* temp = new Task("one", "two" , "three", 2, 8, 1000, 1200, 0, 0);
    temp->AddSubtask("one");
    temp->AddSubtask("two");

    EXPECT_EQ(temp->getSubtask(0).getClass(), "null");

}



#endif 
