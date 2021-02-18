#ifndef __Task_HPP__
#define __Task_HPP__

#include <string>
#include <vector>

class Subtask;

class Task: public Moment {
   private:
	vector<Subtask> sub_tasks;
   public:
	Task(string titIn, string descIn, string catIn, double startIn, double endIn, double totIn, int priIn ):Moment(titIn,descIn, catIn, startIn, endIn, totIn, priIn ){
	//do we need to initilize the sub_tasks vector?
	
	}
	void AddSubtask();



};



#endif
