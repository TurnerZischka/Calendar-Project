#ifndef __COMMAND_EDIT_END_TIME_HPP__
#define __COMMAND_EDIT_END_TIME_HPP__

#include "command.hpp"

class CommandEditEndTime: public Command {

    public:
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