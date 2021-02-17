#ifndef __Task_HPP__
#define __Task_HPP__

#include <string>
#include <vector>

class Subtask;

class Task: public Moment {
   private:
	vector<Subtask> sub_tasks;
   public:
	

	void AddSubtask();



};



#endif
