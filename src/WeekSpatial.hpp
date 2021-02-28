#include <iostream>
#include <list>
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


}


void WeekSpatial::redraw(list<task*> passingList){
    if(mode == 1) { //if mose is set to visual (1), then call respective function
	drawVisual(passingList);
    } else if ( mode == 2){
	drawSubMenu();
    } else {
	cout << "mode error in redraw" << endl;
    } 




}

void WeekSpatial::drawVisual(list<task*> taskList){

//delete all old cells
//to assign each spot in cells the apprioate cell

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
    cout << "Please choose one" << endl;
    int i = 1;
    for( std::vector<int>::iterator it = menuToPrint.begin(); it != menuToPrint.end(); it++){
	if ( i == selectedMenuItem+1) { cout << " > ";}
	cout << i++ <<  it.printMenuItem() << endl;		
    }
}



int WeekSpatial::getSelected(){
   return cells[selectedDay][selectedTime]->getAssociatedID();
}

void recieveInput(int inputSelection){
    if(mode == 1){
	if(inputSelection == 1){ //goes up
	    selectedDay--;
	    if( selecedDay < 0){ selectedDay = 0;} //out of boudn corrector
	} else if (inputSelection == 2){ //goes right
	    selectedTime++;
	    if(selectedTime > 47) {selectedTime = 47;}
	    
	} else if (inputSelection == 3){
	    selectedDay++;
	    if( selectedDay > 6) { selectedDay = 6;}

	} else if (inputSelection == 4) {
	    selectedTime--;
	    if(selectedTime< 0) {selectedTime = 0;}
	} else if (inputSelection == 5) {
	    mode = 2;  //will switch modes, the drawing will be done once the event loop in control calls redraw
	    selectedMenuitem = 0;
	}
    }
    else if (mode == 2){
	

	
	if(inputSelection == 1){
	    selectedMenuItem--;
	    if(selectedMenuItem < 0) { selectedMenuItem = 0;}


	} else if (inputSelection == 3) {
	    selectedMenuItem++;
	    if(selectedMenuItem >= cells[selectedDay][selectedTime]->sizeofMenu()) { selectedMenuItem = cells[selectedDay][selectedTime]->sizeofMenu()-1;}
	
	} else if (inputSelection == 5){
	    mode = 1;
	    selectedMenuItem = 0;
	    cells[selectedDay][selectedTime]->actMenu(selectedMenuItem)
	} else if (inputSelection == 6) {
	    mode = 1;
	    selectedMenuItem = 0;
	}

    }
    else {
	cout << "Mode error" << endl;
    } 




}
