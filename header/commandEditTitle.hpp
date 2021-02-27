#ifndef __COMMAND_EDIT_TITLE_HPP__
#define __COMMAND_EDIT_TITLE_HPP__

#include "command.hpp"


class CommandEditTitle: public Command {

    public:
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