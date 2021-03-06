#ifndef __MIDDLE_CELL_HPP__
#define __MIDDLE_CELL_HPP__

#include "../header/cell.hpp"

class MiddleCell : public Cell {
private:
public:



    MiddleCell(Task *ftask, Control* theControl) {
	cellType = 3;
        task = ftask;
        createMenuItem(new MenuItem("Edit Title", new CommandEditTitle(theControl)));
        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription(theControl)));
        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification(theControl)));
        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime(theControl)));
        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime(theControl)));
    }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
	std::string returnString = "";
        for (unsigned i = 6; i < 13; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);

            }
            if (i >= taskTitle.size()) {
                std::cout << " ";

            }
        }
    }




    void drawTopCell() { std::cout << "-------"; }

    void drawMiddleCell() { std::cout << "       "; }

    void drawBottomCell() { std::cout << "-------"; }

    void highlightTopCell() { std::cout << "*******"; }

    void highlightMiddleCell() { std::cout << "       "; }

    void highlightBottomCell() { std::cout << "*******"; }

	

    void highlightMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        for (unsigned i = 6; i < 13; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
    }

				

};

#endif //__MIDDLE_CELL_HPP__

