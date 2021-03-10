#ifndef __START_CELL_HPP__
#define __START_CELL_HPP__

#include <string>

#include "../header/cell.hpp"


class StartCell : public Cell {
private:
public:


	StartCell() {}
	StartCell(Task* ftask) {
		task = ftask;
	}

    StartCell(Task *ftask, Control* theControl) {
	    cellType = 2;
        task = ftask;
        taskID = ftask->getID();
        createMenuItem(new MenuItem("Edit Title", new CommandEditTitle(theControl)));
        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription(theControl)));
        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification(theControl)));
        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime(theControl)));
        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime(theControl)));
        createMenuItem(new MenuItem("Delete this task", new CommandDeleteTask(theControl)));
        createMenuItem(new MenuItem("Add Subtask", new CommandAddSubtask(theControl)));
    }

    void drawMiddleCellTitle() {
        std::string taskTitle = task->getTitle();
        std::cout << "\033[;34m|\033[0m";
        for (unsigned i = 0; i < 6; ++i) {
            if (i < taskTitle.size()) {
                std::cout << "\033[;34m" << taskTitle.at(i) << "\033[0m";
            }
            if (i >= taskTitle.size()) {
                std::cout << " ";
            }
        }
    }


	void drawMiddleCellTitle(int) {}

    ~StartCell() {}

    void drawTopCell() { std::cout << "\033[;34m+------\033[0m"; }

    void drawMiddleCell() { std::cout << "\033[;34m|      \033[0m"; }

    void drawBottomCell() { std::cout << "\033[;34m+------\033[0m"; }

    void highlightTopCell() { std::cout << "\033[;32m*******\033[0m"; }

    void highlightMiddleCell() { std::cout << "\033[;32m*      \033[0m"; }

    void highlightBottomCell() { std::cout << "\033[;32m*******\033[0m"; }

    void highlightMiddleCellTitle() {
        std::string taskTitle = task->getTitle();

        std::cout << "\033[;32m*\033[0m";
        for (unsigned i = 0; i < 6; ++i) {
            if (i < taskTitle.size()) {
                std::cout << "\033[;32m" <<  taskTitle.at(i) << "\033[0m";

            }
            if (i >= taskTitle.size()) {
                std::cout << " ";

            }
        }
    }

	void highlightMiddleCellTitle(int) {}

};

#endif //__START_CELL_HPP__
