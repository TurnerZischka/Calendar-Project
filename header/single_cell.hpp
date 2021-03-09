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
        createMenuItem(new MenuItem("Delete this task", new CommandDeleteTask(theControl)));
        createMenuItem(new MenuItem("Add Subtask", new CommandAddSubtask(theControl)));
    }

    void drawTopCell() { std::cout << "\033[;34m+-----+\033[0m"; }

    void drawMiddleCell() { std::cout << "\033[;34m|     |\033[0m"; }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        std::cout << "\033[;34m|\033[0m";
        for (unsigned i = 0; i < 5; ++i) {
            if (i < taskTitle.size()) {
                std::cout << "\033{;34m" <<  taskTitle.at(i) << "\033[0m";
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
        std::cout << "\033[;34m|\033[0m";
    }


	void drawMiddleCellTitle(int) {}


    ~SingleCell() {}




    void drawBottomCell() { std::cout << "\033[;34m+-----+\033[0m"; }

    void highlightTopCell() { std::cout << "\033[;32m*******\033[0m"; }

    void highlightMiddleCell() { std::cout << "\033[;32m*     *\033[0m"; }

    void highlightBottomCell() { std::cout << "\033[;32m*******\033[0m"; }

    void highlightMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        std::cout << "\033[;32m*\033[0m";
        for (unsigned i = 0; i < 4; ++i) {
            if (i < taskTitle.size()) {
                std::cout << "\033[;32m" <<  taskTitle.at(i) << "\033[0m";
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
        std::cout << "\033[;32m*\033[0m";
    }
	void highlightMiddleCellTitle(int){}

};

#endif //__SINGLE_CELL_HPP__
