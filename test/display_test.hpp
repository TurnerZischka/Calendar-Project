#ifndef __DISPLAY_TEST_HPP__
#define __DISLPAY_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/display.hpp"
#include "../header/WeekSpatial.hpp"
#include "../header/control.hpp"

TEST(displayRedrawTest, testicles ){

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
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    myDisplay->redraw(taskList, myControl);

    std::string capturedStdout = buffer.str();



    

    EXPECT_EQ(capturedStdout, "" );
}


/*
TEST(display-redraw, ){

}

TEST(display-redraw, ){

}

TEST(display-drawVisual, ){

}

TEST(display-drawVisual, ){

}

TEST(display-drawVisual, ){

}

TEST(display-getSelected, ){

}

TEST(display-getSelected, ){

}

TEST(display-getSelected, ){

}

TEST(display-getSelected, ){

}

TEST(display-recieveInput, ){

}

TEST(display-recieveInput-mode-1, ){

}

TEST(display-recieveInput-mode-1, ){

}

TEST(display-recieveInput-mode-1, ){

}

TEST(display-recieveInput-mode-2, ){

}

TEST(display-recieveInput-mode-2, ){

}

TEST(display-recieveInput-mode-2, ){

}

TEST(display-setMode, ){

}

TEST(display-setMode, ){

}

*/







#endif
