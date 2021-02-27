#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "control.hpp"

class Command {
    public:
        Control* myControl;
        Command();
        virtual void execute() = 0;
};

#endif // __COMMAND_HPP__