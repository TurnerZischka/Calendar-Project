#ifndef __EMPTY_CELL_HPP__
#define __EMPTY_CELL_HPP__

#include "../header/cell.hpp"

class EmptyCell : public Cell {
	private:
	public:
		EmptyCell() {
			cellType = 0;
		}



	virtual void drawTopCell() { std::cout << "+-----+"; }
	virtual void drawMiddleCell() { std::cout << "|     |"; }
	virtual void drawBottomCell() { std::cout << "+-----+"; }
        virtual void drawMiddleCellTitle(){ std::cout << "|     |";}
	void drawMiddleCellTitle(int) {}
      ~EmptyCell() {}
	


        virtual void highlightTopCell(){ std::cout << "\033[;32m*******\033[0m" ;}
        virtual void highlightMiddleCell(){std::cout << "\033[;32m*     *\033[0m" ;}
        virtual void highlightMiddleCellTitle(){std::cout << "\033[;32m*     *\033[0m" ;}
	void highlightMiddleCellTitle(int) {}
        virtual void highlightBottomCell(){std::cout << "\033[;32m*******\033[0m" ;}

};

#endif //__EMPTY_CELL_HPP__
