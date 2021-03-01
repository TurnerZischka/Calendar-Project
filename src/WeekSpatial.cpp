#include <iostream>
#include <list>
#include <vector>
#include "../header/Moment.hpp"
#include "../header/Subtask.hpp"
#include "../header/Task.hpp"
#include "../header/display.hpp"
#include "../header/WeekSpatial.hpp"
//#include "../header/cell.hpp"
//#include "../header/empty_cell.hpp"
//#include "../header/end_cell.hpp"
//#include "../header/middle_cell.hpp"
//#include "../header/single_cell.hpp"
//#include "../header/start_cell.hpp"





using namespace std;




void WeekSpatial::redraw(list<Task*> passingList){
    if(mode == 1) { //if mose is set to visual (1), then call respective function
	drawVisual(passingList);
    } else if ( mode == 2){
	drawSubMenu();
    } else {
	cout << "mode error in redraw" << endl;
    } 




}

void WeekSpatial::drawVisual(list<Task*> taskList){

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
    int menuSize = cells[selectedDay][selectedTime]->sizeOfMenu()
    cout << "Please choose one" << endl;
    for( int i = 0; i < menuSize; i++){
	if ( i == selectedMenuItem) { cout << " > ";}
	cout << i+1 <<  cells[selectedDay][selectedTime]->printMenuItem(i) << endl;		
    }
}



int WeekSpatial::getSelected(){
   return cells[selectedDay][selectedTime]->getAssociatedID();
}

void WeekSpatial::recieveInput(int inputSelection){
    if(mode == 1){
	if(inputSelection == 1){ //goes up
	    selectedDay--;
	    if( selectedDay < 0){ selectedDay = 0;} //out of boudn corrector
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
	    selectedMenuItem = 0;
	}
    }
    else if (mode == 2){
	

	
	if(inputSelection == 1){
	    selectedMenuItem--;
	    if(selectedMenuItem < 0) { selectedMenuItem = 0;}


	} else if (inputSelection == 3) {
	    selectedMenuItem++;
	    if(selectedMenuItem >= cells[selectedDay][selectedTime]->sizeofMenu()) { selectedMenuItem = cells[selectedDay][selectedTime]->sizeOfMenu()-1;}
	
	} else if (inputSelection == 5){
	    mode = 1;
	    int temp = selectedMenuItem;
	    selectedMenuItem = 0;
	    cells[selectedDay][selectedTime]->actMenu(temp);
	} else if (inputSelection == 6) {
	    mode = 1;
	    selectedMenuItem = 0;
	}

    }
    else {
	cout << "Mode error" << endl;
    } 




}
