#include "../header/control.hpp"
#include <fstream>
#include <iostream>
#include <climits>
#include "../header/conio.h"

Control::Control(std::list<Task*> task_list, Display* my_display) {
    this->taskList = task_list;
    this->myDisplay = my_display;
}

Control::~Control() {delete this;}

void Control::AddTask() {
    std::string title;
    std::string classification;
    std::string description;
    int startTime;
    int endTime;
    int taskID = this->taskList.size();

    std::cout << "Enter a title for your task." << std::endl;
    getline(std::cin,title);
    std::cout << "Enter a classification (School, Work, etc.)" << std::endl;

    getline(std::cin,classification);
    std::cout << "Enter a brief description for your task." << std::endl;
    std::cin >> description;
    getline(std::cin, description);
    std::cin.clear();
    std::cout << "Enter a start time as a double (0000 - 2359)" << std::endl;
    std::cin >> startTime;
    std::cin.clear();

    if(startTime < 0 || startTime > 2359) {
        std::cout << "Invalid start time\n";
        return;
    }

    std::cout << "Enter an end time as a double (0 - 2359)" << std::endl;
    std::cin >> endTime;
    std::cin.clear(); std::cin.ignore(INT_MAX,'\n');

    if(endTime < 0 || endTime > 2359 || endTime < startTime) {
        std::cout << "Invalid end time" << std::endl;
        return;
    }

    int totalTime = endTime - startTime;

    Task* myTask = new Task(title,description,classification,startTime, endTime, totalTime, 0, taskID);
    this->taskList.push_back(myTask);
    std::cout << "Task successfully added.\n";
}

void Control::removeTask(int taskID) {
    std::list<Task*>::iterator iter;

    for (iter = this->taskList.begin(); iter != this->taskList.end(); ++iter) {
        if ((*iter)->getID() == taskID) {
            this->taskList.erase(iter);
        }
    }
}

void Control::saveCalendar() {
    std::ofstream outFS;
    outFS.open(this->calendarName);
    std::list<Task*>::iterator iter;

    for (iter = this->taskList.begin(); iter != this->taskList.end(); ++iter) {
        outFS << (*iter)->getTitle() << std::endl;
        outFS << (*iter)->getID() << std::endl;
        outFS << std::endl;
    }

    outFS.close();
}

void Control::loadCalendar(std::string fileName) {
    std::ifstream inFS;
    inFS.open(fileName + ".txt");

    while(false) {
        // Read from txt file contents and create new tasks with information as arguments.
    } //FIX ME

}

void Control::eventLoop() {
    int ch;

    //std::cout << "Welcome to the calendar application. Please select an option." << std::endl;
    //std::cout << "c - Create new Calendar" << std::endl;
    //std::cout << "l - Load existing Calendar" << std::endl;
    //std::cout << "c - Create new Calendar" << std::endl;
    //std::cout << "l - Load existing Calendar" << std::endl;
    std::cout << "Welcome to the calendar application. Please select an option. \n";
    //printw("c - Create new Calendar\n");
    //printw("l - Load existing Calendar\n");
    std::cout << "Press 'a' to add a task\n";

    while ((ch = getch()) != 'q') {

        switch(ch) {

            case '/033':                
                case 'A':
                std::cout << "UpArrow\n";
                this->myDisplay->recieveInput(1);
                this->myDisplay->redraw(this->taskList);
                break;

                case 'B':
                std::cout << "DownArrow\n";
                this->myDisplay->recieveInput(3);
                this->myDisplay->redraw(this->taskList);
                break;

                case 'C':
                std::cout << "RightArrow\n";
                this->myDisplay->recieveInput(2);
                this->myDisplay->redraw(this->taskList);
                break;

                case 'D':
                std::cout << "LeftArrow\n";
                this->myDisplay->recieveInput(4);
                this->myDisplay->redraw(this->taskList);
                break;

            break;

            case '\n':
                std::cout << "Enter" << std::endl;

            case 'a': AddTask();
            break;

        }
    }
}


