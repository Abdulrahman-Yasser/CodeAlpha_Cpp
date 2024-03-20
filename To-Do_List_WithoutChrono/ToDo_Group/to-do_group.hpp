// #include "../DS/LinkedList.hpp"
// #include "../ToDo_Element/to-do_Element.hpp"



// namespace TO_DO_GROUP
// {

// class GroupOfTasks{
// private:
    
//     LinkedList running_group();
//     LinkedList waiting_group();
//     LinkedList done_group();
//     std::string group_name;
//     int id;
//     static (void*)start_call_back(int);
//     static (void*)pause_call_back(int);
//     static (void*)finish_call_back(int);
//     int tasks_counter = 0;
// public:
//     GroupOfTasks(std::string name = "default", TO_DO_ELEMENT::To_Do_Element the_task, int id);
//     int add_task(std::string name = "default", TO_DO_ELEMENT::To_Do_Element the_element);
//     std::vector<int> checking_tasks_arrival(void);
//     std::vector<int> checking_tasks_ending(void);
//     bool start_task(int task_id = -1, string task_name = "Notknown");
//     bool pause_task(int task_id = -1, string task_name = "Notknown");
//     bool end_task(int task_id = -1, string task_name = "Notknown");
//     void call_back_finishingTask( (void*)fun(int) );
// };

// }