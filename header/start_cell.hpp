#ifndef __START_CELL_HPP__
#define __START_CELL_HPP__

#include "../header/cell.hpp"

class StartCell : public Cell {
	private:
	public:
                StartCell(Task* ftask) {
                        task = ftask;
                        createMenuItem(new MenuItem("Edit Title",new CommandEditTitle));
                        createMenuItem(new MenuItem("Edit Description", new CommandEditDescription));
                        createMenuItem(new MenuItem("Edit Classification", new CommandEditClassification));
                        createMenuItem(new MenuItem("Edit Start Time", new CommandEditStartTime));
                        createMenuItem(new MenuItem("Edit End Time", new CommandEditEndTime));
                }
		
                void drawMilddleCellTitle() {
                        string taskTitle = task->getTitle();
                        std::cout << "|";
                        for(unsigned i = 0; i < 4; ++i) {
                                if(i < taskTitle.size()) {
                                        std::cout << taskTitle.at(i);
                                }
                                if(i >= x.size()) {
                                        std::cout << " ";
                                }
                        }
                }


		void drawTopCell() { std::cout << "+----"; }
		void drawMiddleCell() { std::cout << "|    "; }
		void drawBottomCell() { std::cout << "+----"; }
};

#endif //__START_CELL_HPP__
