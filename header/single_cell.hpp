#ifndef __SINGLE_CELL_HPP__
#define __SINGLE_CELL_HPP__

#include "../header/cell.cpp"

class SingleCell : public Cell {
	private:
	public:
		void drawTopCell() { cout << "+---+"; }
		void drawMiddleCell() { cout << "|    |"; }
		void drawBottomCell() { cout << "+---+"; }
}

#endif //__SINGLE_CELL_HPP__
