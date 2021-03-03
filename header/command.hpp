#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "control.hpp"
#include <iostream>
#include <string>


class Command {
    public:
        Control* myControl;
        Command();
        ~Command() {delete this;}
        virtual void execute() = 0;
};

#endif // __COMMAND_HPP__