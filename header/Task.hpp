#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "Moment.hpp"
#include <list>
#include <string>
#include <vector>

class Subtask;

class Task: public Moment {
   private:
	std::list<Subtask*> sub_tasks;
	int ID;
   public:
	Task();
	Task(std::string titIn, std::string descIn, std::string catIn, double startIn, double endIn, double totIn, int priIn, int inID ):Moment(titIn,descIn, catIn, startIn, endIn, totIn, priIn ){
	//do we need to initilize the sub_tasks vector?
	ID = inID;
	}
	void AddSubtask(std::string titIn, std::string descIn, std::string catIn, double startIn, double endIn, double totIn, int priIn);



};



#endif
