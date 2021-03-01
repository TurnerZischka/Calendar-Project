#include <iostream>
#include "../header/control.hpp"
#include "../header/display.hpp"
#include "../header/Task.hpp"

int main() {
    Display* myDisplay = new Display();
    std::list<Task*> taskList;

    Control* myControl = new Control(taskList,myDisplay);
    myControl->eventLoop(); 

    delete myControl;
    delete myDisplay;

    return 0;
}