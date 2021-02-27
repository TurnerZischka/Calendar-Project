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

void WeekSpatial::redraw(){
    for(int i = 0; i< 7; i++){
	for(int j = 0; j< 48;j++){
	    cells[i][j]->drawTopCell();
	}
	cout << endl;
	for(int j = 0; j< 48;j++){
	    cells[i][j]->drawMiddleCell();
	}
	cout << endl;
	for(int j = 0; j<48;j++){
	    cells[i][j]->drawBottomCell();
	}
	cout << endl;


    }


}

void WeekSpatial::drawSubMenu(){
    vector<menuitems> menuToPrint = cell[selectedDay][selectedTime]->menuOptions
    int i = 1;
    for( std::vector<int>::iterator it = menuToPrint.begin(); it != menuToPrint.end(); it++){
	cout << "please choose one" << endl;
	cout << i++ <<  it.name() << endl;	
	
    }


}


