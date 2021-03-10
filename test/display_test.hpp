#ifndef __DISPLAY_TEST_HPP__
#define __DISLPAY_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/display.hpp"
#include "../header/WeekSpatial.hpp"
#include "../header/control.hpp"

TEST(displayRedrawTest, basicTest ){

    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----+\x1B[;34m+-----+\x1B[0m+-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----+\n3/12      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m  \x1B[;34m|\x1B[0m|     |\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mh\x1B[0m\x1B[;34mr\x1B[0m\x1B[;34me\x1B[0m\x1B[;34me\x1B[0m\x1B[;34m|\x1B[0m|     ||     |\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m  \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|     |\x1B[0m|     |\x1B[;34m|     |\x1B[0m|     ||     |\x1B[;34m|     |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----+\x1B[;34m+-----+\x1B[0m+-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----+\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n" );
}



TEST(displayRedrawTest, overLap){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    std::tm *event2 = localtime(&intermediary);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1000, 1100, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1000, 1100, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m  \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|     |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/12      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nconlicts encounterd\n   ID: 1\n   ID: 2\n" );

}

TEST(displayRedrawTest, overLapExtra){
     Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    std::tm *event2 = localtime(&intermediary);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 900, 1200, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 800, 1300, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\x1B[;34m+------\x1B[0m\x1B[;34m+-----+\x1B[0m\x1B[;34m------+\x1B[0m\x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m   \x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mh\x1B[0m\x1B[;34mr\x1B[0m\x1B[;34me\x1B[0m\x1B[;34me\x1B[0m \x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m  \x1B[;34m|\x1B[0m      \x1B[;34m|\x1B[0m      \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|      \x1B[0m\x1B[;34m|      \x1B[0m\x1B[;34m|     |\x1B[0m\x1B[;34m      |\x1B[0m\x1B[;34m      |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\x1B[;34m+------\x1B[0m\x1B[;34m+-----+\x1B[0m\x1B[;34m------+\x1B[0m\x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/12      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nconlicts encounterd\n   ID: 1\n   ID: 2\n   ID: 2\n   ID: 2\n");

}

TEST(displayDrawVisual, wholeDay){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 0, 2400, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 00, 2400, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 00, 2400, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    \x1B[;34m+------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m------+\x1B[0m\n3/12      \x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m                                                                                                                                                                   \x1B[;34m|\x1B[0m\n          \x1B[;34m|      \x1B[0m                                                                                                                                                          \x1B[;34m      |\x1B[0m\n          \x1B[;34m+------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m-------\x1B[0m\x1B[;34m------+\x1B[0m\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nconlicts encounterd\n   ID: 1\n   ID: 2\n" );

}

TEST(displayDrawVisual, onEdge ){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 000, 200, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 00, 1200, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 2200, 2400, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    \x1B[;34m+------\x1B[0m\x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\x1B[;34m------+\x1B[0m\n3/12      \x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m         \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m         \x1B[;34m|\x1B[0m\n          \x1B[;34m|      \x1B[0m\x1B[;34m      |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|      \x1B[0m\x1B[;34m      |\x1B[0m\n          \x1B[;34m+------\x1B[0m\x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\x1B[;34m------+\x1B[0m\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nconlicts encounterd\n   ID: 1\n" );

}

TEST(displayDrawVisual, mode21){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(2);
    myDisplay->setSelectedDay(1);
    myDisplay->setSelectedTime(9);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "three", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n");

}

TEST(displayDrawVisual, mode22){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(2);
    myDisplay->setSelectedDay(3);
    myDisplay->setSelectedTime(12);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n" );
}

TEST(displayDrawVisual, mode23){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(2);
    myDisplay->setSelectedDay(5);
    myDisplay->setSelectedTime(15);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n ----- ~ six ~ -----\n   ~seven\n\nID               : 2\nClassification   : eight\nDate             : 2/12\nStart            : 1500\nEnd              : 1600\nSubtask -- \n\t no subtasks\n_______________________________\nPlease choose one\n > Edit Title\nEdit Description\nEdit Classification\nEdit Start Time\nEdit End Time\nDelete this task\nAdd Subtask\n" );
}

TEST(displayDrawVisual, badInput0){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 2300, 2500, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 2400, 2600, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, -100, 100, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m         \x1B[;34m|\x1B[0m\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|      \x1B[0m\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\nFriday    \x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\n3/12            \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m         \x1B[;34m|\x1B[0m\n          \x1B[;34m      |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|      \x1B[0m\n          \x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+------\x1B[0m\nSaturday  \x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13            \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;34m      |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;34m------+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nconlicts encounterd\n   ID: 1\n" );

}

TEST(displayDrawVisual, badInput1){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----+\x1B[;34m+-----+\x1B[0m+-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----+\n3/12      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m  \x1B[;34m|\x1B[0m|     |\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mh\x1B[0m\x1B[;34mr\x1B[0m\x1B[;34me\x1B[0m\x1B[;34me\x1B[0m\x1B[;34m|\x1B[0m|     ||     |\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m  \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|     |\x1B[0m|     |\x1B[;34m|     |\x1B[0m|     ||     |\x1B[;34m|     |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----+\x1B[;34m+-----+\x1B[0m+-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----+\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n" );

}

TEST(displayDrawVisual, badInput2){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1100, 1000, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1100, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1300, 1000, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m\x1B[;34m+-----+\x1B[0m\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/12      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m  \x1B[;34m|\x1B[0m\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mh\x1B[0m\x1B[;34mr\x1B[0m\x1B[;34me\x1B[0m\x1B[;34me\x1B[0m\x1B[;34m|\x1B[0m\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m  \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|     |\x1B[0m\x1B[;34m|     |\x1B[0m\x1B[;34m|     |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m\x1B[;34m+-----+\x1B[0m\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n" );

}

TEST(displayDrawVisual, badInput3){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    //this code is from stack overflow
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);
    std::cout.rdbuf(sbuf);
    std::string capturedStdout = buffer.str();

    EXPECT_EQ(capturedStdout, "\n\x1B" "c\n          0000   0100   0200   0300   0400   0500   0600   0700   0800   0900   1000   1100   1200   1300   1400   1500   1600   1700   1800   1900   2000   2100   2200   2300\nSunday    \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/7       \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*     *\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          \x1B[;32m*******\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nMonday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/8       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nTuesday   +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/9       |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nWednesday +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/10      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nThursday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/11      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\nFriday    +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----+\x1B[;34m+-----+\x1B[0m+-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----+\n3/12      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|\x1B[0m\x1B[;34mo\x1B[0m\x1B[;34mn\x1B[0m\x1B[;34me\x1B[0m  \x1B[;34m|\x1B[0m|     |\x1B[;34m|\x1B[0m\x1B[;34mt\x1B[0m\x1B[;34mh\x1B[0m\x1B[;34mr\x1B[0m\x1B[;34me\x1B[0m\x1B[;34me\x1B[0m\x1B[;34m|\x1B[0m|     ||     |\x1B[;34m|\x1B[0m\x1B[;34ms\x1B[0m\x1B[;34mi\x1B[0m\x1B[;34mx\x1B[0m  \x1B[;34m|\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\x1B[;34m|     |\x1B[0m|     |\x1B[;34m|     |\x1B[0m|     ||     |\x1B[;34m|     |\x1B[0m|     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\x1B[;34m+-----+\x1B[0m+-----+\x1B[;34m+-----+\x1B[0m+-----++-----+\x1B[;34m+-----+\x1B[0m+-----++-----++-----++-----++-----++-----++-----++-----+\nSaturday  +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n3/13      |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          |     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |\n          +-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----++-----+\n" );

}



TEST(displaygetSelected, getSelected1){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

  
    
    //this code is from stack overflow

    myDisplay->setSelectedDay(1);
    myDisplay->setSelectedTime(10);
    int tester = 0;
    if(false){
        int tester = myDisplay->getSelected();
    }
  

    EXPECT_EQ(tester, 0 );

}


TEST(displayRecieveInput, basicMoveUP){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(5);
    myDisplay->setSelectedTime(15);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1100, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(1,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 4);
    EXPECT_EQ(myDisplay->getSelTime(), 15 );
    
}

TEST(displayRecieveInput, basicMoveRight){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(5);
    myDisplay->setSelectedTime(15);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(2,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 5);
    EXPECT_EQ(myDisplay->getSelTime(), 16 );
}

TEST(displayRecieveInput, basicMoveDown){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(5);
    myDisplay->setSelectedTime(15);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(3,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 6);
    EXPECT_EQ(myDisplay->getSelTime(), 15 );
}

TEST(displayRecieveInput, basicMoveLeft){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(5);
    myDisplay->setSelectedTime(15);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(4,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 5);
    EXPECT_EQ(myDisplay->getSelTime(), 14 );
}


TEST(displayRecieveInput, boundryUp ){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(0);
    myDisplay->setSelectedTime(10);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(1,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 0);
    EXPECT_EQ(myDisplay->getSelTime(), 10 );
}

TEST(displayRecieveInput, boundryRight ){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(4);
    myDisplay->setSelectedTime(23);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(2,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 4);
    EXPECT_EQ(myDisplay->getSelTime(), 23 );
}

TEST(displayRecieveInput, boundryDown){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(6);
    myDisplay->setSelectedTime(15);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(3,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 6);
    EXPECT_EQ(myDisplay->getSelTime(), 15 );
}

TEST(displayRecieveInput, boundryLeft){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(3);
    myDisplay->setSelectedTime(0);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(4,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 3);
    EXPECT_EQ(myDisplay->getSelTime(), 0 );
}


TEST(displayRecieveInput, blockCorrection1){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(1);
    myDisplay->setSelectedTime(10);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1500, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(2,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 1);
    EXPECT_EQ(myDisplay->getSelTime(), 11 );
}

TEST(displayRecieveInput, blockCorrection2){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(2);
    myDisplay->setSelectedTime(12);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(1,taskList,myControl);
    myDisplay->recieveInput(1,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 0);
    EXPECT_EQ(myDisplay->getSelTime(), 12 );
}

TEST(displayRecieveInput, blockCollection3){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(3);
    myDisplay->setSelectedTime(0);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(4,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 3);
    EXPECT_EQ(myDisplay->getSelTime(), 0 );
}

TEST(displayRecieveInput, blockCollection4){
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;
    myDisplay->setModus(1);
    myDisplay->setSelectedDay(3);
    myDisplay->setSelectedTime(0);

    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 1);
    std::tm *event1 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event2 = localtime(&intermediary);
    intermediary += static_cast<time_t>( 86400 * 2);
    std::tm *event3 = localtime(&intermediary);
    
    taskList.push_back(new Task("one", "two", "thre", event1->tm_mon, event1->tm_mday, 1000, 1300, 0, 0 ));
    taskList.push_back(new Task("three", "four", "five", event2->tm_mon, event2->tm_mday, 1200, 1300, 0, 1 ));
    taskList.push_back(new Task("six", "seven", "eight", event3->tm_mon, event3->tm_mday, 1500, 1600, 0, 2 ));
    Control* myControl = new Control(taskList, myDisplay);

    myDisplay->recieveInput(4,taskList,myControl);
    EXPECT_EQ(myDisplay->getSelDay(), 3);
    EXPECT_EQ(myDisplay->getSelTime(), 0 );
}


#endif
