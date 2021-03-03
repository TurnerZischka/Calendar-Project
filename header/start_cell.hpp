#ifndef __START_CELL_HPP__
#define __START_CELL_HPP__

#include <string>

#include "../header/cell.hpp"


class StartCell : public Cell {
private:
public:
    StartCell(Task *ftask, Control* theControl) {
        task = ftask;
        createMenuItem(new MenuItem("Edit Title", new CommandEditTitle(theControl)));
        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription(theControl)));
        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification(theControl)));
        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime(theControl)));
        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime(theControl)));
    }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        std::cout << "|";
        for (unsigned i = 0; i < 5; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
    }


    void drawTopCell() { std::cout << "+-----"; }

    void drawMiddleCell() { std::cout << "|     "; }

    void drawBottomCell() { std::cout << "+-----"; }

    void highlightTopCell() { std::cout << "******"; }

    void highlightMiddleCell() { std::cout << "*     "; }

    void highlightBottomCell() { std::cout << "******"; }

    void highlightMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        std::cout << "*";
        for (unsigned i = 0; i < 5; ++i) {
            if (i < taskTitle.size()) {
                std::cout << taskTitle.at(i);
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
    }

};

#endif //__START_CELL_HPP__
