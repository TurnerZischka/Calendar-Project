#ifndef __COMMAND_DELETE_TASK_HPP__
#define __COMMAND_DELETE_TASK_HPP__

#include "command.hpp"
#include "../header/control.hpp"


class CommandDeleteTask: public Command {

    public:
        CommandDeleteTask(Control* theControl):Command(theControl){}
        ~CommandDeleteTask(){}

        virtual void execute() {
            std::list<Task*>::iterator iter;
            for(iter = myControl->taskList.begin(); iter != myControl->taskList.end(); ++iter) {
                if ((*iter)->getID() == myControl->getSelected()) {
                    Task* temp = *iter;
                    *iter = nullptr;
                    delete temp;
                    this->myControl->taskList.erase(iter);
                    break;
                }
            }
        }
};

#endif // __COMMAND_DELETE_TASK_HPP__