#ifndef __EMPTY_CELL_HPP__
#define __EMPTY_CELL_HPP__

#include "../header/cell.hpp"

class EmptyCell : public Cell {
	private:
	public:


		void drawTopCell() { std::cout << "     "; }
		void drawMiddleCell() { std::cout << "     "; }
		void drawBottomCell() { std::cout << "     "; }

        virtual void drawMiddleCellTitle(){ std::cout << "     " ; }
        virtual void highlightTopCell(){ std::cout << "*****" ;}
        virtual void highlightMiddleCell(){std::cout << "     " ;}
        virtual void highlightMiddleCellTitle(){std::cout << "     " ;}
        virtual void highlightBottomCell(){std::cout << "******" ;}
};

#endif //__EMPTY_CELL_HPP__
