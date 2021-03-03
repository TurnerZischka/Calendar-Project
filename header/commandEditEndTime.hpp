#ifndef __COMMANDEDITENDTIME_HPP__
#define __COMMANDEDITENDTIME_HPP__

#include "command.hpp"
#include "../header/control.hpp"

class CommandEditEndTime: public Command {

public:
    CommandEditEndTime(Control* theControl):Command(theControl){}
    virtual void execute() {

        double newEndTime;
        std::cout << "Enter a new end time for the task:" << std::endl;
        std::cin >> newEndTime;

        if (newEndTime < 0 || newEndTime > 2359) {
            std::cout << "Invalid Time. Try again." << std::endl;
            return;
        }

        std::list<Task*>::iterator iter;
        for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
            if ((*iter)->getID() == myControl->getSelected()) {
                (*iter)->setEnd(newEndTime);
            }
        }
    }
};

#endif // __COMMAND_EDIT_END_TIME_HPP__