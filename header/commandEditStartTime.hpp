#ifndef __COMMANDEDITSTARTTIME_HPP__
#define __COMMANDEDITSTARTTIME_HPP__

#include "command.hpp"
#include "../header/control.hpp"


class CommandEditStartTime: public Command {

    public:
        CommandEditStartTime(Control* theControl):Command(theControl){}
        ~CommandEditStartTime(){}

        void execute() {

            int newStartTime;
            std::cout << "Enter a new start time for the task:" << std::endl;
            std::cin >> newStartTime;
            std::cin.clear();
            std::cin.ignore(100000,'\n'); 

            if (newStartTime < 0 || newStartTime > 2359) {
                std::cout << "Invalid Time. Try again." << std::endl;
                return;
            }

            for(std::list<Task*>::iterator iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setStart(newStartTime); 
                    (*iter)->tmStruct.tm_hour = newStartTime/100;
                    (*iter)->tmStruct.tm_min = newStartTime % 100;
                }
            }
        }
};

#endif // __COMMAND_EDIT_START_TIME_HPP__
