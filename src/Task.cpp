#include "../header/Moment.hpp"
#include "../header/Task.hpp"
#include "../header/Subtask.hpp"

void Task::AddSubtask(std::string titIn, std::string descIn, std::string catIn, int startIn, int endIn, int totIn, int priIn) {

	Subtask* mySubTask = new Subtask(titIn,descIn, catIn, startIn, endIn, totIn, priIn);
	this->sub_tasks.push_back(mySubTask);
}
