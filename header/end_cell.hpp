#ifndef __END_CELL_HPP__
#define __END_CELL_HPP__

#include "../header/cell.hpp"

class EndCell : public Cell {
private:
public:
    EndCell(Task *ftask, Control *theControl) {
        task = ftask;
        createMenuItem(new MenuItem("Edit Title", new CommandEditTitle(theControl)));
        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription(theControl)));
        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification(theControl)));
        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime(theControl)));
        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime(theControl)));
    }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        for (unsigned i = 11; i < 17; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
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
        for (unsigned i = 11; i < 17; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
        std::cout << "*";
    }

};

#endif //__END_CELL_HPP__
