#ifndef __COMMAND_EDIT_DESCRIPTION_HPP__
#define __COMMAND_EDIT_DESCRIPTION_HPP__

#include "command.hpp"


class CommandEditDescription: public Command {

    public:
        virtual void execute() {

            std::string newDescription;
            std::cout << "Enter a new description for the task:" << std::endl;
            std::cin >> newDescription;

            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setDescription(newDescription); 
                }
            }
        }
};


#endif // __COMMAND_EDIT_DESCRIPTION_HPP__