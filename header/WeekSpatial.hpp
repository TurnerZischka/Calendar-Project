#ifndef __WEEKSPATIAL_HPP__
#define __WEEKSPATIAL_HPP__

#include <iostream>
#include "./Moment.hpp"
#include "./Subtask.hpp"
#include "./Task.hpp"
#include "./diskpay.hpp"
#include "./cell.hpp"
#include "./empty_cell.hpp"
#include "./end_cell.hpp"
#include "./middle_cell.hpp"
#include "./single_cell.hpp"
#include "./start_cell.hpp"


using namespace std;

class Week_Spatial: public display {
    private:
	double currTime;
	Cell*[7][48] cells;
	int selectedDay;
	int selectedTime;
	int mode;  // either 1 or 2,  representing 1: visual and   2: submenu is being displayed
    public:
	virtual void redraw();
	void drawSubMenu();
	int getSelected();
	void recieveInput(int);





};





#endif  //__WEEKSPATIAL_HPP__


