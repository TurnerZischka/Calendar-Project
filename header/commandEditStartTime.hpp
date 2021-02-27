#ifndef __COMMAND_EDIT_START_TIME_HPP__
#define __COMMAND_EDIT_START_TIME_HPP__

#include "command.hpp"


class CommandEditStartTime: public Command {

    public:
        virtual void execute() {

            double newStartTime;
            std::cout << "Enter a new start time for the task:" << std::endl;
            std::cin >> newStartTime;

            if (newStartTime < 0 || newStartTime > 2359) {
                std::cout << "Invalid Time. Try again." << std::endl;
                return;
            }

            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setStart(newStartTime); 
                }
            }
        }
};

#endif // __COMMAND_EDIT_START_TIME_HPP__
