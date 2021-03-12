#ifndef __CONTROL_TEST_HPP__
#define __CONTROL_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/control.hpp"



TEST(ControlTest, ControlAddTask) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "TEST";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);
    Control* myControl = new Control(taskList, myDisplay);
   

    EXPECT_EQ(myControl->taskList.size(),1);
}

TEST(ControlTest, ControlAddTask2) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "TEST";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    Task* myTask2 = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 2);

    taskList.push_back(myTask);
    taskList.push_back(myTask2);

    Control* myControl = new Control(taskList, myDisplay);
   

    EXPECT_EQ(myControl->taskList.size(),2);
}

TEST(ControlTest, ControlAddTask3) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "TEST";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    Task* myTask2 = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 2);
    Task* myTask3 = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 3);

    taskList.push_back(myTask);
    taskList.push_back(myTask2);
    taskList.push_back(myTask3);

    Control* myControl = new Control(taskList, myDisplay);
   

    EXPECT_EQ(myControl->taskList.size(),3);
}

TEST(ControlTest, ControlAddTask4) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "TEST";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    Task* myTask2 = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 2);
    Task* myTask3 = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 3);
    Task* myTask4 = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 4);

    taskList.push_back(myTask);
    taskList.push_back(myTask2);
    taskList.push_back(myTask3);
    taskList.push_back(myTask4);

    Control* myControl = new Control(taskList, myDisplay);
   

    EXPECT_EQ(myControl->taskList.size(),4);
}


#endif
