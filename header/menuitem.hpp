#ifndef __MENUITEM_HPP__
#define __MENUITEM_HPP__

#include "command.hpp"
#include <string>

class MenuItem {
    public:
        Command* specificCommand;
        std::string itemName;

        ~MenuItem() {delete this->specificCommand;}


        MenuItem(std::string name, Command* myCommand) {
            this->specificCommand = myCommand;
            this->itemName = name;
        }

        void selected() {
            this->specificCommand->execute();
        }
};


#endif // __MENU_ITEM_HPP__
