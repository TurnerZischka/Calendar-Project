#include "../header/control.hpp"
#include <fstream>
#include <iostream>
#include <ncurses.h>

Control::Control(std::list<Task*> task_list, Display* my_display) {
    this->taskList = task_list;
    this->myDisplay = my_display;
}

Control::~Control() {delete this;}

void Control::AddTask() {
    Task* myTask = new Task();
    this->taskList.push_back(myTask);
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
    initscr();
    keypad(stdscr,TRUE);
    noecho();

    std::cout << "Welcome to the calendar application. Please select an option." << std::endl;
    std::cout << "c - Create new Calendar" << std::endl;
    std::cout << "l - Load existing Calendar" << std::endl;

    while ((ch = getch()) != 'q') {
        switch(ch) {

            case 'c': printw("Enter name for new calendar.\n");
            std::cin >> this->calendarName;
            break;

            case 'l': printw("Enter name of calendar to load\n");
            std::cin >> this->calendarName;
            case KEY_UP: 
            break;

            case KEY_DOWN: printw("\nDown");
            break;

            case KEY_LEFT: printw("\nLeft");
            break;

            case KEY_RIGHT: printw("\nRight");
            break;

            default: printw("%c", ch);
        }
    }



}


