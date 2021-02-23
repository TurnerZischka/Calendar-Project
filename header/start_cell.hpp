#ifndef __START_CELL_HPP__
#define __START_CELL_HPP__

#include "../header/cell.hpp"

class StartCell : public Cell {
	private:
	public:
		void drawTopCell() { cout << "+----"; }
		void drawMiddleCell() { cout << "|     "; }
		void drawBottomCell() { cout << "+----"; }
}

#endif //__START_CELL_HPP__
