#ifndef __MENU_ITEM_HPP__
#define __MENU_ITEM_HPP__

#include "command.hpp"
#include <string>

class MenuItem {
    public:
        Command* specificCommand;
        ~MenuItem() {delete this;}
        std::string itemName;

        MenuItem(std::string name, Command* myCommand) {
            this->specificCommand = myCommand;
            this->itemName = name;
        }

        void selected() {
            this->specificCommand->execute();
        }
};


#endif // __MENU_ITEM_HPP__
