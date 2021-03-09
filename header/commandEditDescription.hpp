#ifndef __COMMANDEDITDESCRIPTION_HPP__
#define __COMMANDEDITDESCRIPTION_HPP__

#include "command.hpp"
#include "../header/control.hpp"

class CommandEditDescription: public Command {

    public:
        CommandEditDescription(Control* theControl):Command(theControl){}
        ~CommandEditDescription(){}

        virtual void execute() {

            std::string newDescription;
            std::cout << "Enter a new description for the task:" << std::endl;
            getline(std::cin, newDescription);

            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setDescription(newDescription); 
                }
            }
        }
};


#endif // __COMMAND_EDIT_DESCRIPTION_HPP__