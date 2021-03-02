#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__


#include <iostream>
#include <list>
#include "./Moment.hpp"
#include "./Subtask.hpp"
#include "./Task.hpp"


using namespace std;

class Display{
    private:


    public:
	virtual void redraw(list<Task*>)= 0;

};





#endif

