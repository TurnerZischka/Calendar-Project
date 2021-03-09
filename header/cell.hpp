#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <iostream>
#include <vector>
#include <string>

#include "../header/menuitem.hpp"
#include "../header/Task.hpp"

#include "../header/commandEditClassification.hpp"
#include "../header/commandEditDescription.hpp"
#include "../header/commandEditEndTime.hpp"
#include "../header/commandEditStartTime.hpp"
#include "../header/commandEditTitle.hpp"
#include "../header/commandDeleteTask.hpp"
#include "../header/commandAddSubtask.hpp"




class Cell {
	public:
		std::vector<MenuItem*> menuItemVect;
		int taskID = -1;	
		Task* task;
		int cellType;
		std::string remaining;



		void createMenuItem(MenuItem* item) { menuItemVect.push_back(item); }

		int getAssociatedID() { return taskID; }
		int sizeOfMenu() { return menuItemVect.size(); }
		std::string printMenuItem(int x) {
			return menuItemVect.at(x)->itemName;
		}
		void actMenu(int x) {
			menuItemVect.at(x)->selected();
		}

		virtual ~Cell(){
			while(!menuItemVect.empty()) {
				delete menuItemVect.back();
				menuItemVect.pop_back();
			}
		}
			
		virtual void drawTopCell() = 0;
		virtual void drawMiddleCell() = 0;
		virtual void drawMiddleCellTitle() = 0;
		virtual void drawMiddleCellTitle(int) = 0;
		virtual void drawBottomCell() = 0;

		virtual void highlightTopCell() = 0;
		virtual void highlightMiddleCell() = 0;
		virtual void highlightMiddleCellTitle() = 0;
		virtual void highlightMiddleCellTitle(int) = 0;
		virtual void highlightBottomCell() = 0;
};

#endif //__CELL_HPP__
