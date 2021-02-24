#ifndef __END_CELL_HPP__
#define __END_CELL_HPP__

#include "../header/cell.hpp"

class EndCell : public Cell {
	private:
	public:
		void drawTopCell() { std::cout << "----+"; }
		void drawMiddleCell() { std::cout << "    |"; }
		void drawBottomCell() { std::cout << "----+"; }
};

#endif //__END_CELL_HPP__
