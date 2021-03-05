#ifndef __SINGLE_CELL_HPP__
#define __SINGLE_CELL_HPP__

#include<iostream>
#include<cstring>

#include "../header/Task.hpp"
#include "../header/cell.hpp"


class SingleCell : public Cell {
private:
public:

    SingleCell(Task *ftask, Control* theControl) {
        task = ftask;


        createMenuItem(new MenuItem("Edit Title", new CommandEditTitle(theControl)));
        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription(theControl)));
        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification(theControl)));
        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime(theControl)));
        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime(theControl)));
    }

    void drawTopCell() { std::cout << "+-----+"; }

    void drawMiddleCell() { std::cout << "|     |"; }

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
        std::cout << "|";
    }


    /*void drawMilddleCellStartTime() {
            int taskTime = task->getStart();
            std::cout << "|";
            for(unsigned i = 0; i < 4; ++i) {
                    if(i < taskTitle.size()) {
                            std::cout << taskTitle.at(i);
                    }
                    if(i >= x.size()) {
                            std::cout << " ";
                    }
            }
            std::cout << "|";
    }*/




    void drawBottomCell() { std::cout << "+-----+"; }

    void highlightTopCell() { std::cout << "*******"; }

    void highlightMiddleCell() { std::cout << "*     *"; }

    void highlightBottomCell() { std::cout << "*******"; }

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
        std::cout << "*";
    }

};

#endif //__SINGLE_CELL_HPP__
