#ifndef __START_CELL_HPP__
#define __START_CELL_HPP__

#include "../header/cell.hpp"

class StartCell : public Cell {
	private:
	public:
		StartCell() { 
			taskID = ID;
		}
		void drawTopCell() { std::cout << "+----"; }
		void drawMiddleCell() { std::cout << "|    "; }
		void drawBottomCell() { std::cout << "+----"; }
};

#endif //__START_CELL_HPP__
