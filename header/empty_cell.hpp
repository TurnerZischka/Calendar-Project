#ifndef __EMPTY_CELL_HPP__
#define __EMPTY_CELL_HPP__

#include "../header/cell.hpp"

class EmptyCell : public Cell {
	private:
	public:
		void drawTopCell() { std::cout << "     "; }
		void drawMiddleCell() { std::cout << "     "; }
		void drawBottomCell() { std::cout << "     "; }
};

#endif //__EMPTY_CELL_HPP__
