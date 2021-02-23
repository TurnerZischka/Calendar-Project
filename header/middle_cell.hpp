#ifndef __MIDDLE_CELL_HPP__
#define __MIDDLE_CELL_HPP__

#include "../header/cell.cpp"

class MiddleCell : public Cell {
	priavte:
	publlic:
		void drawTopCell() { cout << "-----"; }
		void drawMiddleCell() { cout << "     "; }
		void drawBottomCell() { cout << "-----"; }
}

#endif //__MIDDLE_CELL_HPP__

