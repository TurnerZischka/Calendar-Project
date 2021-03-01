
#include "../header/Moment.hpp"
#include "../header/Task.hpp"
#include "../header/Subtask.hpp"

#include <vector>

void Task::AddSubtask(std::string titIn, std::string descIn, std::string catIn, double startIn, double endIn, double totIn, int priIn){
    Subtask tempSubTask (titIn,descIn, catIn, startIn, endIn, totIn, priIn );
	sub_tasks.push_back(tempSubTask);



}
