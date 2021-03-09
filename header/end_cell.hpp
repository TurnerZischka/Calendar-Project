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
        createMenuItem(new MenuItem("Delete this task", new CommandDeleteTask(theControl)));
    }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
	int size = task->getEnd() - task->getStart();
	int soFar = ((((size - 1) / 100)*7)-1) ;
	if(size <= 200) {
                for (unsigned i = 6; i < 12; ++i) {
                    if (i < taskTitle.size()) {
                                        std::cout << "\033[;34m" << taskTitle.at(i) << "\033[0m";
                    }
                    if (i >= taskTitle.size()) {
                        std::cout << " ";
                    }
                }
	}
	else if ( soFar > taskTitle.size()) {
		for (unsigned i = 0; i < 6; ++i) {
			std::cout << " ";
		}
	}
        else if ( soFar < taskTitle.size()) {
		for (unsigned i = soFar; i < soFar + 6; ++i) {
			if (i < taskTitle.size()) {
                                        std::cout << "\033[;34m" << taskTitle.at(i) << "\033[0m";
			}
			if (i >= taskTitle.size()) {
				std::cout << " ";
			}
		}
	}
	else{
        for (unsigned i = 13; i < 19; ++i) {
            if (i < taskTitle.size()) {
                                        std::cout << "\033[;34m" << taskTitle.at(i) << "\033[0m";
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
	}
        std::cout << "\033[;34m|\033[0m";
    }


	void drawMiddleCellTitle(int) {}

    ~EndCell() {}



    void drawTopCell() { std::cout << "\033[;34m------+\033[0m"; }

    void drawMiddleCell() { std::cout << "\033[;34m      |\033[0m"; }

    void drawBottomCell() { std::cout << "\033[;34m------+\033[0m"; }

    void highlightTopCell() { std::cout << "\033[;32m*******\033[0m"; }

    void highlightMiddleCell() { std::cout << "\033[;32m      *\033[0m"; }

    void highlightBottomCell() { std::cout << "\033[;32m*******\033[0m"; }
	    void highlightMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        int size = task->getEnd() - task->getStart();
        int soFar = ((((size - 1) / 100)*7)-1) ;
        if(size <= 200) {
                for (unsigned i = 6; i < 12; ++i) {
                    if (i < taskTitle.size()) {
                        std::cout << "\033[;32m" << taskTitle.at(i) << "\033[0m";
                    }
                    if (i >= taskTitle.size()) {
                        std::cout << " ";
                    }
                }
        }
        else if ( soFar > taskTitle.size()) {
                for (unsigned i = 0; i < 6; ++i) {
                        std::cout << " ";
                }
        }
        else if ( soFar < taskTitle.size()) {
                for (unsigned i = soFar; i < soFar + 6; ++i) {
                        if (i < taskTitle.size()) {
                        std::cout << "\033[;32m" << taskTitle.at(i) << "\033[0m";
                        }
                        if (i >= taskTitle.size()) {
                                std::cout << " ";
                        }
                }
        }
        else{
        for (unsigned i = 13; i < 19; ++i) {
            if (i < taskTitle.size()) {
                std::cout << "\033[;32m" << taskTitle.at(i) << "\033[0m";
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
        }
        std::cout << "\033[;32m*\033[0m";
    }


	void highlightMiddleCellTitle(int){}

};

#endif //__END_CELL_HPP__
