#ifndef __END_CELL_HPP__
#define __END_CELL_HPP__

#include "../header/cell.cpp"

class EndCell : public Cell {
	private:
	public:
		void drawTopCell() { cout << "----+"; }
		void drawMiddleCell() { cout << "    |"; }
		void drawBottomCell() { cout << "----+"; }
}

#endif //__END_CELL_HPP__
