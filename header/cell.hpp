#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <iostream>

class Cell {
	private:
	public:
		virtual void drawTopCell() = 0;
		virtual void drawMiddleCell() = 0;
		virtual void drawBottomCell() = 0;
};

#endif //__CELL_HPP__
