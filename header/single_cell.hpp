#ifndef __SINGLE_CELL_HPP__
#define __SINGLE_CELL_HPP__

#include "../header/cell.hpp"

class SingleCell : public Cell {
	private:
	public:
		void drawTopCell() { std::cout << "+---+"; }
		void drawMiddleCell() { std::cout << "|   |"; }
		void drawBottomCell() { std::cout << "+---+"; }
};

#endif //__SINGLE_CELL_HPP__
