#include "../header/display.hpp"
#include "../header/Moment.hpp"
#include "../header/Subtask.hpp"
#include "../header/Task.hpp"
#include "../header/WeekSpatial.hpp"
#include "../header/control.hpp"
#include "../header/display.hpp"

#include <iostream>
#include <string>
#include <list>



int main() {
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    Control* myControl = new Control(taskList,myDisplay);
    myControl->eventLoop(); 

    delete myDisplay;
    delete myControl;
    


    return 0;
}