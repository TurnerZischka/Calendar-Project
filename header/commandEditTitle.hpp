#ifndef __COMMANDEDITTITLE_HPP__
#define __COMMANDEDITTITLE_HPP__

#include "command.hpp"
#include "../header/control.hpp"


class CommandEditTitle: public Command {


    public:
        CommandEditTitle(Control* theControl):Command(theControl){ }
        ~CommandEditTitle(){}

        virtual void execute() {

            std::string newTitle;
            std::cout << "Enter a new title for the task:" << std::endl;
            std::cin >> newTitle;

            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setTitle(newTitle); 
                }
            }
        }
};


#endif // __COMMAND_EDIT_TITLE_HPP__