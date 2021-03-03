#ifndef __COMMAND_EDIT_CLASSIFICATION_HPP__
#define __COMMAND_EDIT_CLASSIFICATION_HPP__

#include "command.hpp"


class CommandEditClassification: public Command {

    public:
        virtual void execute() {

            std::string newClassification;
            std::cout << "Enter a new classification for the task:" << std::endl;
            std::cin >> newClassification;

            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    (*iter)->setClass(newClassification); 
                }
            }
        }
};


#endif // __COMMAND_EDIT_CLASSIFICATION_HPP__