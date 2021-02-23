#ifndef __EMPTY_CELL_HPP__
#define __EMPTY_CELL_HPP__

#include "../header/cell.cpp"

class EmptyCell : public Cell {
	private:
	public:
		void drawTopCell() { cout << "     "; }
		void drawMiddleCell() { cout << "     "; }
		void drawBottomCell() { cout << "     "; }
}

#endif //__EMPTY_CELL_HPP__
