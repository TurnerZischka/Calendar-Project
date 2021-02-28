#ifndef __SINGLE_CELL_HPP__
#define __SINGLE_CELL_HPP__

#include<iostream>
#include<cstring>

#include "../header/cell.hpp"


class SingleCell : public Cell {
	private:
	public:
		SingleCell(int ID) { 
			taskID = ID;
			createMenuItem(new MenuItem("Edit Title",new CommandEditTitle));
			createMenuItem(new MenuItem("Edit Description", new CommandEditDescription));
			createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification));
			createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime));
			createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime));
		}

		void drawTopCell() { std::cout << "+---+"; }
		void drawMiddleCell() { std::cout << "|   |"; }
		/* void drawMilddleCell() { 
			//How do we get task title? Going to implement assuming string taskTitle hold task title.
			string taskTitle;
			cout << "|";
			for(unsigned i = 0; i < 3; ++i) {
				if(i < taskTitle.size()) {
					cout << taskTitle.at(i);
				}
				if(i >= x.size()) {
					cout << " ";
				}
			}
			cout << "|";
		}*/
		void drawBottomCell() { std::cout << "+---+"; }
};

#endif //__SINGLE_CELL_HPP__
