#ifndef __COMMAND_TEST_HPP__
#define __COMMAND_TEST_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "../header/command.hpp"
#include "../header/commandEditTitle.hpp"
#include "../header/commandEditDescription.hpp"
#include "../header/Moment.hpp"
#include "../header/Task.hpp"
#include "../header/control.hpp"
#include "../header/display.hpp"
#include <sstream>


void execute_title(std::string newTitle, Control* myControl) {
        std::list<Task*>::iterator iter;
        for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
            if ((*iter)->getID() == 1) {
                (*iter)->setTitle(newTitle); 
            }
        }
    }

void execute_description(std::string newDescription, Control* myControl) {
        std::list<Task*>::iterator iter;
        for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
            if ((*iter)->getID() == 1) {
                (*iter)->setDescription(newDescription); 
            }
        }
    }

void execute_classification(std::string newClassification, Control* myControl) {
        std::list<Task*>::iterator iter;
        for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
            if ((*iter)->getID() == 1) {
                (*iter)->setClass(newClassification); 
            }
        }
    }

void execute_start(int newStartTime, Control* myControl, std::ostream& out) {
        std::list<Task*>::iterator iter;

        if(newStartTime < 0 || newStartTime >= 2359) {
            out << "Invalid start time. Try again\n";
        }

        for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
            if ((*iter)->getID() == 1) {
                (*iter)->setStart(newStartTime); 
            }
        }
    }

void execute_end(int newEndTime, Control* myControl, std::ostream& out) {
        std::list<Task*>::iterator iter;

        if(newEndTime < 0 || newEndTime >= 2359) {
            out << "Invalid end time. Try again\n";
        }

        for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
            if ((*iter)->getID() == 1) {
                (*iter)->setEnd(newEndTime); 
            }
        }
    }

void execute_delete(int taskID, Control* myControl) {
            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == 1) {
                    Task* temp = *iter;
                    *iter = nullptr;
                    delete temp;
                    myControl->taskList.erase(iter);
                    break;
                }
            }
        }

void execute_add_subtask(std::string title, Control* myControl) {
         
            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if((*iter)->getID() == 1) {
                    (*iter)->AddSubtask(title);
                }
            }
        }




TEST(CommandEditTitleTest, EditTitleNorm) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "TEST";
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
   
    std::string newTitle = "CS120B";

    execute_title(newTitle,myControl);

    EXPECT_EQ(myTask->getTitle(), newTitle);    

}

TEST(CommandEditTitleTest, EditTitleNorm_2) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "TEST";
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
   
    std::string newTitle = "CS120A";

    execute_title(newTitle,myControl);

    EXPECT_EQ(myTask->getTitle(), newTitle);    

}


TEST(CommandEditTitleTest, EditTitleNorm_3) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "TEST";
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
   
    std::string newTitle = "CS120C";

    execute_title(newTitle,myControl);

    EXPECT_EQ(myTask->getTitle(), newTitle);    

}

TEST(CommandEditTitleTest, EditTitleNorm_4) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "TEST";
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
   
    std::string newTitle = "AAAAAAAAAAAA";

    execute_title(newTitle,myControl);

    EXPECT_EQ(myTask->getTitle(), newTitle);    

}

TEST(CommandEditDescriptionTest, EditDescriptionNorm) {
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
   
    std::string newDescription = "STUDYING IS LAME";

    execute_description(newDescription,myControl);

    EXPECT_EQ(myTask->getDescription(), newDescription);    

}

TEST(CommandEditDescriptionTest, EditDescriptionNorm_2) {
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
   
    std::string newDescription = "STUDYING IS EPIC";

    execute_description(newDescription,myControl);

    EXPECT_EQ(myTask->getDescription(), newDescription);    

}

TEST(CommandEditDescriptionTest, EditDescriptionNorm_3) {
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
   
    std::string newDescription = "STUDYING IS TIGHT";

    execute_description(newDescription,myControl);

    EXPECT_EQ(myTask->getDescription(), newDescription);    

}


TEST(CommandEditClassificationTest, EditClassificationNorm) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);
   
    std::string newClassification = "LECTURE";

    execute_classification(newClassification,myControl);

    EXPECT_EQ(myTask->getClass(), newClassification);    

}

TEST(CommandEditClassificationTest, EditClassificationNorm_2) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);
   
    std::string newClassification = "WORK";

    execute_classification(newClassification,myControl);

    EXPECT_EQ(myTask->getClass(), newClassification);    

}

TEST(CommandEditStartTimeTest, EditStartTime_Norm) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    int newStartTime = 2000;
    std::stringstream ss;
   

    execute_start(newStartTime,myControl, ss);

    EXPECT_EQ(myTask->getStart(), newStartTime);    

}

TEST(CommandEditStartTimeTest, EditStartTimeEdge_1) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    int newStartTime = 2500;

    std::stringstream ss;
   

    execute_start(newStartTime,myControl, ss);

    EXPECT_EQ(ss.str(), "Invalid start time. Try again\n");    

}

TEST(CommandEditStartTimeTest, EditStartTimeEdge_2) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    int newStartTime = -2500;

    std::stringstream ss;
   

    execute_start(newStartTime,myControl, ss);

    EXPECT_EQ(ss.str(), "Invalid start time. Try again\n");    

}

TEST(CommandEditStartTimeTest, EditEndTimeNorm) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    int newEndTime = 1600;

    std::stringstream ss;
   

    execute_end(newEndTime,myControl, ss);

    EXPECT_EQ(myTask->getEnd(), 1600);    

}

TEST(CommandEditStartTimeTest, EditEndTimeEdge_1) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    int newEndTime = 2500;

    std::stringstream ss;
   

    execute_end(newEndTime,myControl, ss);

    EXPECT_EQ(ss.str(), "Invalid end time. Try again\n");    

}

TEST(CommandEditStartTimeTest, EditEndTimeEdge_2) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    int newEndTime = -2500;

    std::stringstream ss;
   

    execute_end(newEndTime,myControl, ss);

    EXPECT_EQ(ss.str(), "Invalid end time. Try again\n");    

}

TEST(CommandDeleteTask, DeleteTask) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);

    execute_delete(myTask->getID(), myControl);

    EXPECT_EQ(myControl->taskList.size(),0);

}

TEST(CommandAddSubtask, addSubtask) {
    std::list<Task*> taskList;
    std::string myTitle = "CS111 Lecture";
    std::string myDescription = "STUDY RIGHT NOW";
    std::string myCategory = "School";
    std::string subtaskTitle = "MIDTERM";
    int month = 3;
    int date = 4;
    int startTime = 1400;
    int endTime = 1900;
    int priority = 0;

    Display* myDisplay = new WeekSpatial();

    Task* myTask = new Task(myTitle, myDescription, myCategory, month, date, startTime, endTime, 0, 1);
    taskList.push_back(myTask);

    Control* myControl = new Control(taskList, myDisplay);
    execute_add_subtask(subtaskTitle, myControl);

    std::list<Task*>::iterator iter = myControl->taskList.begin();

    EXPECT_EQ((*iter)->getSubtaskSize(), 1);

}










#endif
