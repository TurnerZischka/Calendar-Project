#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include "Task.hpp"
#include "display.hpp"
#include <string>
#include <list>


class Control {
    private:
        std::list<Task*> taskList;
        Display* myDisplay;
        
    public:
        std::string calendarName;
        Control(std::list<Task*>, Display*);
        ~Control();
        void AddTask();
        void removeTask(int);
        void saveCalendar();
        void loadCalendar(std::string);
        void eventLoop();
};


#endif // __CONTROL_HPP__
