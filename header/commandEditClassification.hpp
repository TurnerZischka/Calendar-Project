#ifndef __COMMANDEDITCLASSIFICATION_HPP__
#define __COMMANDEDITCLASSIFICATION_HPP__

#include "command.hpp"
#include "../header/control.hpp"


class CommandEditClassification: public Command {

    public:
        CommandEditClassification(Control* theControl):Command(theControl){}
        ~CommandEditClassification(){}

        virtual void execute() {

            std::string newClassification;
            std::cout << "Enter a new classification for the task:" << std::endl;
            getline(std::cin, newClassification);

            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setClass(newClassification); 
                }
            }
        }
};


#endif // __COMMAND_EDIT_CLASSIFICATION_HPP__