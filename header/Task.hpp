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
	    int ID;
	    std::tm tmStruct;
   public:
	    Task(std::string titIn,std::string descIn, std::string catIn, int month, int date, int startIn, int endIn, int priIn, int inID ):Moment(titIn,descIn, catIn, month, date, startIn, endIn, priIn ){
	//do we need to initilize the sub_tasks vector?
	        ID = inID;
	        tmStruct = {0, startIn%100, startIn/100, date, month, 2021-1900};

	    }
	    void AddSubtask(std::string, std::string, std::string, int, int, int, int, int);


};




#endif //FINAL_PROJECT_ALEE235_AREFA001_TZISC001_TASK_HPP
