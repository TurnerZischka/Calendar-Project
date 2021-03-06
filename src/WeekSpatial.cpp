#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <stdio.h>

#include "../header/Moment.hpp"
#include "../header/Subtask.hpp"
#include "../header/Task.hpp"
#include "../header/display.hpp"
#include "../header/WeekSpatial.hpp"


#include "../header/empty_cell.hpp"
#include "../header/end_cell.hpp"
#include "../header/middle_cell.hpp"
#include "../header/single_cell.hpp"
#include "../header/start_cell.hpp"


using namespace std;

void WeekSpatial::clearScreen() {
    std::cout << std::endl;
    std::cout << "\033c" << std::endl;
}


void WeekSpatial::redraw(list<Task *> passingList, Control* theControl) {
    if (mode == 1) { //if mose is set to visual (1), then call respective function
        drawVisual(passingList, theControl);
    } else if (mode == 2) {
        drawSubMenu();
    } else {
        cout << "mode error in redraw" << endl;
    }


}

void WeekSpatial::drawVisual(std::list<Task *> taskList, Control* theControl) {

    clearScreen();    
	bool monday = false;
	bool tuesday = false;
	bool wednesday = false;
	bool thursday = false;
	bool friday = false;
	bool saturday = false;
	bool sunday = false;

    if( cells[1][1] != nullptr) { // this check is first because upon first draw, the cells will all be null. After first draw, non will be null
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 24; j++) {
                Cell* temp = cells[i][j];
                cells[i][j] = nullptr;
                delete temp;
            }

        }
    }


    // gets the time of today, coverts it to the struct, then manipulates the struct to make it first moment of today
    time_t currTime = time(0);
    std::tm *currTimeStruct = localtime(&currTime);
    currTimeStruct->tm_sec = 0;
    currTimeStruct->tm_min = 0;
    currTimeStruct->tm_hour = 0;

    //86400 represents seconds in a day
    //this conversion subtracts from the time_t of the very begginig of the day, the days from previous sunday. This means that intermediary is time of sunday at newday
    time_t intermediary = mktime(currTimeStruct) - static_cast<time_t>( 86400* currTimeStruct->tm_wday); //this
    std::tm *weekStart = localtime(&intermediary);


    //does this work? will earasing an element screw with for loop iterator?
    //the point of this loop is to remove all events out of the list that do not fall within the range
    for(std::list<Task*>::iterator it = taskList.begin(); it != taskList.end(); ++it){
        if(mktime(&(*it)->tmStruct) < mktime(weekStart) || mktime(&(*it)->tmStruct) > mktime(weekStart)+ static_cast<time_t>(604800)){
            taskList.erase(it);
        }
    }

    //this goes through all items in the list within the data range and assigns it a start spot, any middle spots, and an end spot
    //if the "span" is only one spot, it just allocates a single then
    for(std::list<Task*>::iterator it = taskList.begin(); it != taskList.end(); ++it){
        int span = (((((*it)->getEndTime()/100) - ((*it)->getStartTime()/100))*60) + ((*it)->getEndTime()%100) - ((*it)->getStartTime()%100) )/30;
        if (span > 1) {
            cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour*2) + ((*it)->tmStruct.tm_min/30)] = new StartCell(*it, theControl);

            for( int i = 1; i < span-1; i++){
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour*2) + ((*it)->tmStruct.tm_min/30) + (i)] = new MiddleCell(*it, theControl);
            }
            cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour*2) + ((*it)->tmStruct.tm_min/30) + (span-1)] = new EndCell(*it, theControl);
        } else {
            cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour*2) + ((*it)->tmStruct.tm_min/30)] = new SingleCell(*it, theControl);
        }
    }


    //fills null cells with empty_cell
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 24; j++){
            if(cells[i][j] == nullptr){
                cells[i][j] = new EmptyCell();
            } else {
                //do nothing
            }
        }

    }

cout << "          " <<  "hour1  " << "hour2  " << "hour3  " << "hour4  " << "hour5  " << "hour6  " << "hour7  " << "hour8  " << "hour9  " << "hour10 " << "hour11 " << "hour12 " << "hour13 " << "hour14 " << "hour15 " << "hour16 ";
cout << "hour17 " << "hour18 hour19 hour20 hour21 hour22 hour23 hour24" << endl;

    for (int i = 0; i < 7; i++) {

		if(monday == false) {
			cout << "Monday    ";
			monday = true;
		}
		else if(tuesday == false) {
			cout << "Tuesday   ";
			tuesday = true;
		}
		else if(wednesday == false) {
			cout << "Wednesday ";
			wednesday = true;
		}
		else if(thursday == false) {
			cout << "Thursday  ";
			thursday = true;
		}
		else if(friday == false) {
			cout << "Friday    ";
			friday = true;
		}
		else if(saturday ==false) {
			cout << "Saturday  ";
			saturday = true;
		}
		else if(sunday == false) {
			cout << "Sunday    ";
			sunday = true;
		}
		else { cout << "          "; }

	int checkLength = 1;
        for (int j = 0; j < 24; j++) {
            if (i == selectedDay && j == selectedTime) {
		if(cells[i][j]->cellType == 2) {
			cells[i][j]->highlightTopCell();
			while(cells[i][j+checkLength]->cellType == 3){
				cells[i][j+checkLength]->highlightTopCell();
				j++;
			}
			if(cells[i][j+checkLength]->cellType == 4) {
				cells[i][j+checkLength]->highlightTopCell();
				j++;
			}
		}
		else { cells[i][j]->highlightTopCell(); }
            } else {
                cells[i][j]->drawTopCell();
            }
        }
        cout << endl;
	cout << "          ";
        for (int j = 0; j < 24; j++) {
            if (i == selectedDay && j == selectedTime) {
		if(cells[i][j]->cellType == 2) {
			cells[i][j]->highlightMiddleCellTitle();
			while(cells[i][j+checkLength]->cellType == 3) {
				cells[i][j+checkLength]->highlightMiddleCellTitle();
				j++;
			}
			if(cells[i][j+1]->cellType == 4) {
				cells[i][j+1]->highlightMiddleCellTitle();
				j++;
			}
		}
		else { cells[i][j]->highlightMiddleCell(); }
            } else {
                cells[i][j]->drawMiddleCellTitle();
            }
        }
        cout << endl;
	cout << "          ";
        for (int j = 0; j < 24; j++) {
            if (i == selectedDay && j == selectedTime) {
                if(cells[i][j]->cellType == 2) {
                        cells[i][j]->highlightMiddleCell();
                        while(cells[i][j+checkLength]->cellType == 3) {
                                cells[i][j+checkLength]->highlightMiddleCell();
                                j++;
                        }
                        if(cells[i][j+1]->cellType == 4) {
                                cells[i][j+1]->highlightMiddleCell();
                                j++;
                        }
                }

                else { cells[i][j]->highlightMiddleCell(); }
            } else {
                cells[i][j]->drawMiddleCell();
            }
        }
        cout << endl;
	cout << "          ";
        for (int j = 0; j < 24; j++) {
            if (i == selectedDay && j == selectedTime) {
                if(cells[i][j]->cellType == 2) {
                        cells[i][j]->highlightTopCell();
                        while(cells[i][j+checkLength]->cellType == 3){
                                cells[i][j+checkLength]->highlightTopCell();
                                j++;
                        }
                        if(cells[i][j+checkLength]->cellType == 4) {
                                cells[i][j+checkLength]->highlightTopCell();
                                j++;
                        }
                }
                else { cells[i][j]->highlightBottomCell(); }

            } else {
                cells[i][j]->drawBottomCell();
            }
        }
        cout << endl;


    }


}

void WeekSpatial::drawSubMenu() {
    int menuSize = cells[selectedDay][selectedTime]->sizeOfMenu();
    cout << "Please choose one" << endl;
    for (int i = 0; i < menuSize; i++) {
        if (i == selectedMenuItem) { cout << " > "; }
        cout << i + 1 << cells[selectedDay][selectedTime]->printMenuItem(i) << endl;
    }
}


int WeekSpatial::getSelected() {
    return cells[selectedDay][selectedTime]->getAssociatedID();
}

void WeekSpatial::recieveInput(int inputSelection) {
    if (mode == 1) {
        if (inputSelection == 1) { //goes up
            selectedDay--;
            if (selectedDay < 0) { selectedDay = 0; } //out of boudn corrector
        } else if (inputSelection == 2) { //goes right
            selectedTime++;
            if (selectedTime > 23) { selectedTime = 23; }

        } else if (inputSelection == 3) {
            selectedDay++;
            if (selectedDay > 6) { selectedDay = 6; }

        } else if (inputSelection == 4) {
            selectedTime--;
            if (selectedTime < 0) { selectedTime = 0; }
        } else if (inputSelection == 5) {
            mode = 2;  //will switch modes, the drawing will be done once the event loop in control calls redraw
            selectedMenuItem = 0;
        }
    } else if (mode == 2) {


        if (inputSelection == 1) {
            selectedMenuItem--;
            if (selectedMenuItem < 0) { selectedMenuItem = 0; }


        } else if (inputSelection == 3) {
            selectedMenuItem++;
            if (selectedMenuItem >= cells[selectedDay][selectedTime]->sizeOfMenu()) { selectedMenuItem =
                                                                                              cells[selectedDay][selectedTime]->sizeOfMenu() -
                                                                                              1;
            }

        } else if (inputSelection == 5) {
            mode = 1;
            int temp = selectedMenuItem;
            selectedMenuItem = 0;
            cells[selectedDay][selectedTime]->actMenu(temp);
        } else if (inputSelection == 6) {
            mode = 1;
            selectedMenuItem = 0;
        }

    } else {
        cout << "Mode error" << endl;
    }


}
