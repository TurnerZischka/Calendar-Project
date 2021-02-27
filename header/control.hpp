#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include "Task.hpp"
#include "display.hpp"
#include <string>
#include <list>


class Control {
    private:
        Display* myDisplay;
        
    public:
        std::list<Task*> taskList;
        std::string calendarName;
        Control(std::list<Task*>, Display*);
        ~Control();
        void AddTask();
        void removeTask(int);
        void saveCalendar();
        void loadCalendar(std::string);
        void eventLoop();
        int getSelected();
};


#endif // __CONTROL_HPP__
