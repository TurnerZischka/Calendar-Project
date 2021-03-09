#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <string>
#include <vector>
#include <ctime>
#include <stdio.h>

#include "../header/Subtask.hpp"

class Task: public Moment {

   private:
        std::vector<Subtask> sub_tasks;

   public:
        std::tm tmStruct;
	    Task(std::string titIn,std::string descIn, std::string catIn, int month, int date, int startIn, int endIn, int priIn, int inID ):Moment(titIn,descIn, catIn, month, date, startIn, endIn, priIn, inID ){
	//do we need to initilize the sub_tasks vector?
	        tmStruct = {0, startIn%100, startIn/100, date, month, 2021-1900};

	    }
	    void AddSubtask(std::string);

		~Task(){}

	    int getEndTime(){
	        return getEnd();
	    }

        int getStartTime(){
            return getStart();
	    }

		int getSubtaskSize() { return sub_tasks.size();}
		std::string getSubtaskNum(int position) { return sub_tasks.at(position).getTitle();}



};




#endif //__TASK_HPP__