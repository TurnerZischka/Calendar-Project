#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <string>
#include <vector>

#include "../header/Subtask.hpp"

class Task: public Moment {

   private:
        std::vector<Subtask> sub_tasks;
	    int ID;
   public:
	    Task(std::string titIn,std::string descIn, std::string catIn, double startIn, double endIn, double totIn, int priIn, int inID ):Moment(titIn,descIn, catIn, startIn, endIn, totIn, priIn ){
	//do we need to initilize the sub_tasks vector?
	        ID = inID;
	    }
	    void AddSubtask(std::string, std::string, std::string, double, double, double, int);


};




#endif //FINAL_PROJECT_ALEE235_AREFA001_TZISC001_TASK_HPP
