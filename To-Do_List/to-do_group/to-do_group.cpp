
#include "to-do_group.hpp"

namespace TO_DO_GROUP
{
    (void*) GroupOfTasks::start_call_back(int) = nullptr;
    (void*) GroupOfTasks::pause_call_back(int) = nullptr;
    (void*) GroupOfTasks::finish_call_back(int) = nullptr;

    GroupOfTasks::GroupOfTasks
        (   std::string name = "default", 
            TO_DO_ELEMENT::To_Do_Element the_task, 
            int id):
        group_name(name), waiting_tasks_group[0](the_task), id(id)
    {
        
    }

    int GroupOfTasks::add_task(TO_DO_ELEMENT::To_Do_Element the_element)
    {
        the_element.id = tasks_counter;
        tasks_counter++;
        waiting_tasks_group.push_back(the_element);
        return the_element.id;
    }
    std::vector<int> GroupOfTasks::checking_tasks_arrival(void)
    {

    }
    std::vector<int> GroupOfTasks::checking_tasks_ending(void)
    {

    }
    bool GroupOfTasks::start_task(int task_id)
    {

    }
    bool GroupOfTasks::start_task(string task_name)
    {

    }
    bool GroupOfTasks::pause_task(string task_name)
    {

    }
    bool GroupOfTasks::pause_task(int task_id)
    {

    }
    void GroupOfTasks::call_back_finishingTask( 
        (void*)starting(int), 
        (void*)finishing(int), 
        (void*)pausing(int) )
    {
        start_call_back = starting;
        pause_call_back = pausing;
        finish_call_back = finishing;
    }
}