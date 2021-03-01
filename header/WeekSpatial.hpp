#ifndef __WEEKSPATIAL_HPP__
#define __WEEKSPATIAL_HPP__

#include <iostream>
#include <list>

#include "../header/Moment.hpp"
#include "../header/Subtask.hpp"
#include "../header/Task.hpp"
#include "../header/display.hpp"
//#include "../header/cell.hpp"
//#include "../header/empty_cell.hpp"
//#include "../header/end_cell.hpp"
//#include "../header/middle_cell.hpp"
//#include "../header/single_cell.hpp"
//#include "../header/start_cell.hpp"


using namespace std;

class Week_Spatial: public Display {
    private:
	double currTime;
	Cell*[7][48] cells;
	int selectedDay;
	int selectedTime;
	int mode;  // either 1 or 2,  representing 1: visual and   2: submenu is being displayed
	int selectedMenuItem;
    public:
	virtual void redraw(list<task*>);
	void drawVisual(list<task*>);
	void drawSubMenu();
	int getSelected();
	void recieveInput(int);





};





#endif  //__WEEKSPATIAL_HPP__


