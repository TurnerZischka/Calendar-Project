#include "../header/display.hpp"
#include "../header/Moment.hpp"
#include "../header/Subtask.hpp"
#include "../header/Task.hpp"
#include "../header/WeekSpatial.hpp"
#include "../header/control.hpp"
#include "../header/display.hpp"
#include "../header/cell.hpp"
#include "../header/empty_cell.hpp"
#include "../header/middle_cell.hpp"
#include "../header/single_cell.hpp"
#include "../header/start_cell.hpp"
#include "../header/menuitem.hpp"
#include "../header/commandEditClassification.hpp"
#include "../header/commandEditDescription.hpp"
#include "../header/commandEditEndTime.hpp"
#include "../header/commandEditStartTime.hpp"
#include "../header/commandEditTitle.hpp"



#include <iostream>
#include <string>



int main() {
    Display* myDisplay = new WeekSpatial();
    std::list<Task*> taskList;

    Control* myControl = new Control(taskList,myDisplay);
    myControl->eventLoop(); 

    delete myControl;
    delete myDisplay;


    return 0;
}