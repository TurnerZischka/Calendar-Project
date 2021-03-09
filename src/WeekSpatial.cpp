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


WeekSpatial::WeekSpatial(){
   

}

void WeekSpatial::clearScreen() {
    std::cout << std::endl;
    std::cout << "\033c" << std::endl;
}


void WeekSpatial::redraw(list<Task *> passingList, Control* theControl) {
    drawVisual(passingList, theControl);
    
}

WeekSpatial::~WeekSpatial() {
    
    
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 24; ++j) {
            Cell* temp = cells[i][j];
            cells[i][j] = nullptr;
            delete temp; 
            
        }
    }


  //  clearScreen();    
}


void WeekSpatial::drawVisual(std::list<Task*> taskList, Control* theControl) {

    clearScreen();   

        bool monday = false;
        bool tuesday = false;
        bool wednesday = false;
        bool thursday = false;
        bool friday = false;
        bool saturday = false;
        bool sunday = false;


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

    //this goes through all items in the list within the data range and assigns it a start spot, any middle spots, and an end spot
    //if the "span" is only one spot, it just allocates a single then
    for(std::list<Task*>::iterator it = taskList.begin(); it != taskList.end(); ++it){
        if(((mktime(&(*it)->tmStruct) >= mktime(weekStart)) && (mktime(&(*it)->tmStruct) <= mktime(weekStart)+ static_cast<time_t>(604800))) ){
            int span = (((*it)->getEndTime()/100) - ((*it)->getStartTime()/100));
            if (span > 1) {
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour)] = new StartCell(*it, theControl);

                for( int i = 1; i < span-1; i++){
                    cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour) + (i)] = new MiddleCell(*it, theControl);
                }
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour)  + (span-1)] = new EndCell(*it, theControl);
            } else {
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour)] = new SingleCell(*it, theControl);
            }
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



    if (mode == 1) { //if mose is set to visual (1), then call respective function
       cout << "          " << "0000   " << "0100   " << "0200   " << "0300   " << "0400   " << "0500   " << "0600   " << "0700   " << "0800   " << "0900   " << "1000   " << "1100   " << "1200   " << "1300   " << "1400   " << "1500   " << "1600   ";
cout << "1700   " << "1800   1900   2000   2100   2200   2300" << endl;

    for (int i = 0; i < 7; i++) {

        if(sunday == false) {
			cout << "Sunday    ";
			sunday = true;
		}

		else if(monday == false) {
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
	int place = 1;
        for (int j = 0; j < 24; j++) {
            if (i == selectedDay && j == selectedTime) {
		if(cells[i][j]->cellType == 1) {
			cells[i][j]->highlightMiddleCellTitle();
		}
		else if(cells[i][j]->cellType == 2) {
			cells[i][j]->highlightMiddleCellTitle();
			place = 1;
			while(cells[i][j+checkLength]->cellType == 3) {
				cells[i][j+checkLength]->highlightMiddleCellTitle(place);
				j++;
				place++;
			}
			if(cells[i][j+1]->cellType == 4) {
				cells[i][j+1]->highlightMiddleCellTitle();
				j++;
			}
		}
		else { cells[i][j]->highlightMiddleCell(); }
            } else {
		if(cells[i][j]->cellType == 2) {
	                cells[i][j]->drawMiddleCellTitle();
			place = 1;
			while(cells[i][j+1]->cellType == 3) {
				cells[i][j+1]->drawMiddleCellTitle(place);
				j++;
				place++;
			}
			if(cells[i][j+1]->cellType == 4) {
				cells[i][j+1]->drawMiddleCellTitle();
				j++;
			}
		}
		else { cells[i][j]->drawMiddleCellTitle(); }

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
                        cells[i][j]->highlightBottomCell();
                        while(cells[i][j+checkLength]->cellType == 3){
                                cells[i][j+checkLength]->highlightBottomCell();
                                j++;
                        }
                        if(cells[i][j+checkLength]->cellType == 4) {
                                cells[i][j+checkLength]->highlightBottomCell();
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
    } else if (mode == 2) {
        if (cells[selectedDay][selectedTime]->cellType != 0) {
            cout << " ----- ~ " << cells[selectedDay][selectedTime]->task->getTitle() << " ~ -----"<< endl;

            string splitDescription = cells[selectedDay][selectedTime]->task->getDescription() ;
            int splitPosition = 0;
            int spaceCounter = 0;
            while(splitPosition < splitDescription.size() && splitDescription.find(" ", splitPosition) != string::npos){
                splitPosition = splitDescription.find(' ', splitPosition);
                if(spaceCounter < 4){
                    spaceCounter++;
                    splitPosition++;
                } else {
                    spaceCounter = 0;
                    splitDescription.insert( splitPosition,"\n   ");
                    splitPosition += 5;
                }
            }
            
            cout << "   ~" << splitDescription << endl << endl;
            cout << "Classification   : " << cells[selectedDay][selectedTime]->task->getClass() << endl;
            cout << "Date             : " << cells[selectedDay][selectedTime]->task->getMonth() << "/" << cells[selectedDay][selectedTime]->task->getDate() << endl;
            cout << "Start            : " << cells[selectedDay][selectedTime]->task->getStart() << endl;
            cout << "End              : " << cells[selectedDay][selectedTime]->task->getEnd() << endl;
            cout << "Subtask -- " << endl;
            if(cells[selectedDay][selectedTime]->task->getSubtaskSize() != 0) {
                for( int i = 0 ; i < cells[selectedDay][selectedTime]->task->getSubtaskSize(); i++ ){
                    cout << "\t- " << cells[selectedDay][selectedTime]->task->getSubtaskNum(i) << endl;;
                }
            } else {
                cout << "\t no subtasks" << endl;
            }


            cout << "_______________________________" << endl;

            int menuSize = cells[selectedDay][selectedTime]->sizeOfMenu();
            cout << "Please choose one" << endl;
            for (int i = 0; i < menuSize; i++) {
                if (i == selectedMenuItem) { cout << " > ";
            }
            cout << cells[selectedDay][selectedTime]->printMenuItem(i) << endl;
        }
        }
    }
     else {

    }



    

    for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 24; j++) {
                Cell* temp = cells[i][j];
                cells[i][j] = nullptr;
                delete temp; 
            }
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

void WeekSpatial::recieveInput(int inputSelection, std::list<Task*> taskList, Control* theControl) {
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

    //this goes through all items in the list within the data range and assigns it a start spot, any middle spots, and an end spot
    //if the "span" is only one spot, it just allocates a single then
    for(std::list<Task*>::iterator it = taskList.begin(); it != taskList.end(); ++it){
        if(((mktime(&(*it)->tmStruct) >= mktime(weekStart)) && (mktime(&(*it)->tmStruct) <= mktime(weekStart)+ static_cast<time_t>(604800))) ){
            int span = (((*it)->getEndTime()/100) - ((*it)->getStartTime()/100));
            if (span > 1) {
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour)] = new StartCell(*it, theControl);

                for( int i = 1; i < span-1; i++){
                    cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour) + (i)] = new MiddleCell(*it, theControl);
                }
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour)  + (span-1)] = new EndCell(*it, theControl);
            } else {
                cells[(*it)->tmStruct.tm_wday][((*it)->tmStruct.tm_hour)] = new SingleCell(*it, theControl);
            }
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






    if (mode == 1) {
        if (inputSelection == 1) { //goes up
            selectedDay--;
            if (selectedDay < 0) { selectedDay = 0; } //out of boudn corrector
            while(cells[selectedDay][selectedTime]->cellType == 3 || cells[selectedDay][selectedTime]->cellType == 4){
                selectedTime--;
                if(selectedTime < 0){
                    selectedTime = 0;
                    break;
                }
            }
        } else if (inputSelection == 2) { //goes right
            int revert = selectedTime;
            selectedTime++;
            if (cells[selectedDay][selectedTime]->cellType == 3 || cells[selectedDay][selectedTime]->cellType == 4){ 
                while((cells[selectedDay][selectedTime]->cellType == 3 || cells[selectedDay][selectedTime]->cellType == 4)){
                    selectedTime++; 
                    if(selectedTime > 23){
                        selectedTime = revert;
                        break;
                    }

                }
                
                  
            }
            if (selectedTime > 23) { selectedTime = 23; }

        } else if (inputSelection == 3) {
            selectedDay++;
            while(cells[selectedDay][selectedTime]->cellType == 3 || cells[selectedDay][selectedTime]->cellType == 4){
                selectedTime--;
                if(selectedTime < 0){
                    selectedTime = 0;
                    break;
                }
            }
            if (selectedDay > 6) { selectedDay = 6; }

        } else if (inputSelection == 4) {
            int revert = selectedTime;
            selectedTime--;
            if (cells[selectedDay][selectedTime]->cellType == 3 || cells[selectedDay][selectedTime]->cellType == 4){ 
                while((cells[selectedDay][selectedTime]->cellType == 3 || cells[selectedDay][selectedTime]->cellType == 4)){
                    selectedTime--; 
                    if(selectedTime > 23){
                        selectedTime = revert;
                        break;
                    }

                }
            }
                
            if (selectedTime < 0) { selectedTime = 0; }
        } else if (inputSelection == 5) {
            if (cells[selectedDay][selectedTime]->cellType != 0) {
                mode = 2;  //will switch modes, the drawing will be done once the event loop in control calls redraw
                selectedMenuItem = 0;
            }
        }
        else {
            std::cout << "ERROR" << std::endl;
        }


    } else if (mode == 2) {


        if (inputSelection == 1) {
            selectedMenuItem--;
            if (selectedMenuItem < 0) { selectedMenuItem = 0; }


        } else if (inputSelection == 3) {
            selectedMenuItem++;
            if (selectedMenuItem >= cells[selectedDay][selectedTime]->sizeOfMenu()) { selectedMenuItem =
                    cells[selectedDay][selectedTime]->sizeOfMenu() - 1;     
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
        else {
            std::cout << "ERROR" << std::endl;
        }

    } else {
        cout << "Mode error" << endl;
    }


    for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 24; j++) {
                Cell* temp = cells[i][j];
                cells[i][j] = nullptr;
                delete temp; 
            }
    }

}

