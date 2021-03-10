#include "../header/Task.hpp"
#include "../header/Subtask.hpp"
#include <iostream>


#include <vector>
#include <string>

void Task::AddSubtask(std::string titIn) {
    Subtask tempSubTask(titIn);
    sub_tasks.push_back(tempSubTask);
    //std::cout << "Subtask added." << std::endl;
}