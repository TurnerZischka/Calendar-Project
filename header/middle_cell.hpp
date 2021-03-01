#ifndef __MIDDLE_CELL_HPP__
#define __MIDDLE_CELL_HPP__

#include "../header/cell.hpp"

class MiddleCell : public Cell {
	private:
	public:

		void drawTopCell() { std::cout << "-----"; }
		void drawMiddleCell() { std::cout << "     "; }
		void drawBottomCell() { std::cout << "-----"; }
};

#endif //__MIDDLE_CELL_HPP__

