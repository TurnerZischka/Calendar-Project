#include "../header/control.hpp"
#include <fstream>

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
        if ((*iter)->taskID == taskID) {
            this->taskList.erase(iter);
        }
    }
}

void Control::saveCalendar() {
    std::ofstream outFS;
    outFS.open("savedCalendar.txt");
    std::list<Task*>::iterator iter;

    for (iter = this->taskList.begin(); iter != this->taskList.end(); ++iter) {
        outFS << (*iter)->title << std::endl;
        outFS << (*iter)->taskID << std::endl;
        outFS << std::endl;
    }

    outFS.close();
}

void Control::loadCalendar(std::string fileName) {
    std::ifstream inFS;
    inFS.open(fileName);

    while(false) {
        // Read from txt file contents and create new tasks with information as arguments.
    } //FIX ME
}

void Control::eventLoop() {}

