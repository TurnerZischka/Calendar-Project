#ifndef __COMMAND_ADD_SUBTASK__
#define __COMMAND_ADD_SUBTASK__

#include "command.hpp"
#include "../header/control.hpp"

class CommandAddSubtask: public Command {

    public:
        CommandAddSubtask(Control* theControl):Command(theControl){}
        ~CommandAddSubtask(){}

        virtual void execute() {
            std::string title;
            std::cout << "Enter a title for the subtask: " << std::endl;
            getline(std::cin, title);

            std::list<Task*>::iterator iter;
            for(iter = this->myControl->taskList.begin(); iter != this->myControl->taskList.end(); ++iter) {
                if((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->AddSubtask(title);
                }
            }
        }

};


#endif