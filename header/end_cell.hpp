#ifndef __END_CELL_HPP__
#define __END_CELL_HPP__

#include "../header/cell.hpp"

class EndCell : public Cell {
private:
public:
    EndCell(Task *ftask, Control *theControl) {
	cellType = 4;
        task = ftask;
        createMenuItem(new MenuItem("Edit Title", new CommandEditTitle(theControl)));
        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription(theControl)));
        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification(theControl)));
        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime(theControl)));
        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime(theControl)));
    }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
	int size = task->getEnd() - task->getStart();
	if(taskTitle.size() < 14) { 
		for (unsigned i = 6; i < 12; ++i) {
	            if (i < taskTitle.size()) {
        	        std::cout << taskTitle.at(i);
        	    }
        	    if (i >= taskTitle.size()) {
        	        std::cout << " ";
        	    }
		}
	}
	else if(size <= 100) {
                for (unsigned i = 6; i < 12; ++i) {
                    if (i < taskTitle.size()) {
                        std::cout << taskTitle.at(i);
                    }
                    if (i >= taskTitle.size()) {
                        std::cout << " ";
                    }
                }
	}
	else if ( ((((size - 1) / 50)*7)-1) > taskTitle.size()) {
		for (unsigned i = 0; i < 6; ++i) {
			std::cout << " ";
		}
	}

	else{
        for (unsigned i = 13; i < 19; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
	}
        std::cout << "|";
    }


    void drawTopCell() { std::cout << "------+"; }

    void drawMiddleCell() { std::cout << "      |"; }

    void drawBottomCell() { std::cout << "------+"; }

    void highlightTopCell() { std::cout << "*******"; }

    void highlightMiddleCell() { std::cout << "      *"; }

    void highlightBottomCell() { std::cout << "*******"; }

    void highlightMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        int size = task->getEnd() - task->getStart();
        if(taskTitle.size() < 14) {
                for (unsigned i = 6; i < 12; ++i) {
                    if (i < taskTitle.size()) {
                        std::cout << taskTitle.at(i);
                    }
                    if (i >= taskTitle.size()) {
                        std::cout << " ";
                    }
                }
        }
        else if(size <= 100) {
                for (unsigned i = 6; i < 12; ++i) {
                    if (i < taskTitle.size()) {
                        std::cout << taskTitle.at(i);
                    }
                    if (i >= taskTitle.size()) {
                        std::cout << " ";
                    }
                }
        }
        else if ( ((((size - 1) / 50)*7)-1) > taskTitle.size()) {
                for (unsigned i = 0; i < 6; ++i) {
                        std::cout << " ";
                }
        }

        else{
        for (unsigned i = 13; i < 19; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
        }
        std::cout << "*";

    }

};

#endif //__END_CELL_HPP__
