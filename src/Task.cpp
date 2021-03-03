#include "../header/Task.hpp"
#include "../header/Subtask.hpp"


#include <vector>
#include <string>

void Task::AddSubtask(std::string titIn, std::string descIn, std::string catIn, int month, int date, int startIn, int endIn, int priIn) {
    Subtask tempSubTask(titIn, descIn, catIn, month, date, startIn, endIn,  priIn);
    sub_tasks.push_back(tempSubTask);
}