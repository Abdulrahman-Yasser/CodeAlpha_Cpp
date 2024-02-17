#include <string.h>
#include <chrono>
#include <stdbool.h>
#include "../to-do_class/to-do.hpp"

namespace TO_DO_GROUP
{
    class GroupOfTasks{
    private:
        std::vector< TO_DO_ELEMENT::To_Do_Element > started_tasks_group;
        std::vector< TO_DO_ELEMENT::To_Do_Element > paused_tasks_group;
        std::vector< TO_DO_ELEMENT::To_Do_Element > waiting_tasks_group;
        std::string group_name;
        int id;
        static (void*)start_call_back(int);
        static (void*)pause_call_back(int);
        static (void*)finish_call_back(int);
        int tasks_counter = 0;
    public:
        GroupOfTasks(std::string name = "default", TO_DO_ELEMENT::To_Do_Element the_task, int id);
        int add_task(std::string name = "default", TO_DO_ELEMENT::To_Do_Element the_element);
        std::vector<int> checking_tasks_arrival(void);
        std::vector<int> checking_tasks_ending(void);
        bool start_task(int task_id);
        bool start_task(string task_name);
        bool pause_task(string task_name);
        bool pause_task(int task_id);
        void call_back_finishingTask( (void*)fun(int) );
    };

}