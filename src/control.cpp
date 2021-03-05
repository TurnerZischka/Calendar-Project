#include "../header/control.hpp"
#include <fstream>
#include <iostream>
#include <climits>
#include <ctime>
#include <list>
//#include "../header/conio.h"
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
    int month = -1;  //these 4 ints are initalized to trigger the respective for loops undderneath
    int date = 0;
    int startTime = -1;
    int endTime = -1;
    int taskID = this->taskList.size();

    std::cout << "Enter a title for your task." << std::endl;
    getline(std::cin, title);

    std::cout << "Enter a classification (School, Work, etc.)" << std::endl;
    getline(std::cin, classification);

    std::cout << "Enter a brief description for your task." << std::endl;
    getline(std::cin, description);

    while (month < 0 || month > 11) {
        std::cout << "Enter Month in a numbers, Jan = 1, Dec = 12" << std::endl;
        std::cin >> month;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        month--;  //month needs to be months since january, possible values of 0 -11
        if (month < 0 || month > 11) { std::cout << "INVALID INPUT" << std::endl;}
    }

    while (date < 1 || date > 31) {
        std::cout << "Enter the day of the month, 1 -31" << std::endl;
        std::cin >> date;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        if ( date < 1 || date > 31) { std::cout << "INVALID INPUT" << std::endl;}
    }

    while( startTime < 0 || startTime > 2359) {
        std::cout << "Enter a start time as a double (0000 - 2359)" << std::endl;
        std::cin >> startTime;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        if ( startTime < 0 || startTime > 2359) { std::cout << "INVALID INPUT" << std::endl;}
    }

    //old implmentation of error checking
    /*if(startTime < 0 || startTime > 2359) {
        std::cout << "Invalid start time\n";
        return;
    }*/

    while( endTime < 0 || endTime > 2359) {
        std::cout << "Enter an end time as a double (0 - 2359)" << std::endl;
        std::cin >> endTime;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        if ( endTime < 0 || endTime > 2359) { std::cout << "INVALID INPUT" << std::endl;}
    }


    //old implimentation of error checking
    /*if(endTime < 0 || endTime > 2359 || endTime < startTime) {
        std::cout << "Invalid end time" << std::endl;
        return;
    }*/


    Task* myTask = new Task(title,description,classification, month, date, startTime, endTime, 0, taskID);
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
                this->myDisplay->redraw(this->taskList, this);
                break;

                case 'B':
                std::cout << "DownArrow\n";
                this->myDisplay->recieveInput(3);
                this->myDisplay->redraw(this->taskList, this);
                break;

                case 'C':
                std::cout << "RightArrow\n";
                this->myDisplay->recieveInput(2);
                this->myDisplay->redraw(this->taskList, this);
                break;

                case 'D':
                std::cout << "LeftArrow\n";
                this->myDisplay->recieveInput(4);
                this->myDisplay->redraw(this->taskList, this);
                break;

            break;

            case '\n':
                std::cout << "Enter" << std::endl;

            case 'a': AddTask();
            break;

        }
    }
}

int Control::getSelected() {
    return myDisplay->getSelected();
}


