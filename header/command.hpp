#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__


#include <iostream>
#include <string>

#include "../header/control.hpp"



class Command {
    public:
        Control* myControl ;
        Command(Control* theControl){ myControl = theControl;}
        virtual ~Command() {}
        virtual void execute() = 0;
};

#endif // __COMMAND_HPP__