#include <chrono>
#include "ToDo_Element_with_wrapper/to-do_Element.hpp"
#include "DS/LinkedList.hpp"


void get_task_data(std::string& task_name, unsigned char& task_priority, std::string& periodic_type);
void get_task_data(std::string& task_name, unsigned char& task_priority, std::string& periodic_type, std::string& starting);

int main(void)
{
    int x, y;
    tm a_time_representation;
    a_time_representation.tm_hour = 5;
    a_time_representation.tm_year = 2026;
    TO_DO_ELEMENT_WR_NS::To_Do_Element first_ele = TO_DO_ELEMENT_WR_NS::To_Do_Element{"first_task", 1,  "2h"};
    TO_DO_ELEMENT_WR_NS::To_Do_Element sec_ele = TO_DO_ELEMENT_WR_NS::To_Do_Element{"second_task", 2,  "2h"};
    TO_DO_ELEMENT_WR_NS::To_Do_Element thrd_ele = TO_DO_ELEMENT_WR_NS::To_Do_Element{"third_task", 1,  "2h"};
    TO_DO_ELEMENT_WR_NS::To_Do_Element frth_ele = TO_DO_ELEMENT_WR_NS::To_Do_Element{"forth_task", 1,  "2h"};
    TO_DO_ELEMENT_WR_NS::To_Do_Element ffth_ele = TO_DO_ELEMENT_WR_NS::To_Do_Element{"fifth_task", 1,  "2h"};
    LinkedList my_ll = LinkedList();
    my_ll.insertNode(&first_ele);
    my_ll.insertNode(&sec_ele);
    my_ll.insertNode(&thrd_ele);
    my_ll.insertNode(&frth_ele);
    my_ll.insertNode(&ffth_ele);
    my_ll.printList();

    std::cout << "Hey, ";

    std::string task_name ;
    unsigned char task_priority;
    std::string periodic_type;
    std::string starting_time;
    TO_DO_ELEMENT_WR_NS::To_Do_Element* a_task;
    std::string temp_date;
    while (1)
    {
        std::cout << "What do you want to do !\n1 - Add a task\n2 - start a task \n3 - End a task\n4 - Pause a task\n5 - Remove a task\n6 - Edit a task\n7 - Print\n";
        std::cin >> x;

        if(x < 7){
            std::cout << "Please enter the task's ID or Name\n";
            std::cin >> task_name;
        }
        switch (x)
        {
        case 1:
            std::cout << "Will you enter full schedule for the task? 1 for yes, 2 for No\n";
            std::cin >> y;
            if(y == 2){
                get_task_data(task_name, task_priority, periodic_type);
                my_ll.insertNode(TO_DO_ELEMENT_WR_NS::To_Do_Element{task_name, task_priority, periodic_type});
            }else if(y == 1){
                get_task_data(task_name, task_priority, periodic_type, starting_time);
                my_ll.insertNode(TO_DO_ELEMENT_WR_NS::To_Do_Element{starting_time, task_name, task_priority, periodic_type});
            }
            break;
        case 2:
            if(task_name[0] >= '0' && task_name[0] <= '9'){
                int wanted_id = stoi(task_name);
                a_task = my_ll.get_task(wanted_id);
            }else{
                a_task = my_ll.get_task(task_name);
            }
            a_task->start_taskElement();
            break;
        case 3:
            if(task_name[0] >= '0' && task_name[0] <= '9'){
                int wanted_id = stoi(task_name);
                a_task = my_ll.get_task(wanted_id);
            }else{
                a_task = my_ll.get_task(task_name);
            }
            a_task->end_taskElement();
            break;
        case 4:
            if(task_name[0] >= '0' && task_name[0] <= '9'){
                int wanted_id = stoi(task_name);
                a_task = my_ll.get_task(wanted_id);
            }else{
                a_task = my_ll.get_task(task_name);
            }
            a_task->end_taskElement();
            break;
        case 5:
            if(task_name[0] >= '0' && task_name[0] <= '9'){
                int wanted_id = stoi(task_name);
                a_task = my_ll.get_task(wanted_id);
            }else{
                a_task = my_ll.get_task(task_name);
            }
            my_ll.deleteNode(a_task);
            break;
        case 6:
            std::cout << "What kind of eddition you wanna make\n1 - Reschedule\n2 - delay\n3 - Extend execution time\n";
            std::cout << "12h : 12 hours, 1m: 1 month, 2d : 2 days\n";
            std::cin >> y;

            switch(y){
            case 1:
                std::cout << "(Reschedule) - Time will be in hdmy ex: 12h26d6m2029y\n";
                std::cin >> periodic_type;
                break;
            case 2:
                std::cout << "(delay)\n";
                std::cin >> periodic_type;
                break;
            case 3:
                std::cout << "(Extend execution time) Enter the number in integer only\n";
                std::cin >> periodic_type;
                break;
            default :
                break;
            }
            
            /* Getting the task of the linked list */
            if(task_name[0] >= '0' && task_name[0] <= '9'){
                int wanted_id = stoi(task_name);
                a_task = my_ll.get_task(wanted_id);
            }else{
                a_task = my_ll.get_task(task_name);
            }

            switch(y){
                case 1:
                    a_task->reschedule_the_task(periodic_type);
                    break;
                case 2:
                    a_task->delay_the_starting_time(periodic_type);
                    break;
                case 3:
                    a_task->changing_task_execution(stoi(periodic_type));
                    break;
                default:
                    break;
            }
            break;
        case 7:
            my_ll.printList();
            break;
        default:
            break;
        }
    }
}


void get_task_data(std::string& task_name, unsigned char& task_priority, std::string& periodic_type){
    std::string temp_str;
    int temp_int;
    std::cout << "Enter the" << task_name << " task priority : ";
    std::cin >> task_priority;
    std::cout << "If it's periodic, please enter the type : \nExamples: 1h:hour, 2h:2 hours, 12W:weakly, 1m:monthly, 1y:yearly\n";
    std::cin >> temp_str;
}

void get_task_data(std::string& task_name, unsigned char& task_priority, std::string& periodic_type, std::string& starting){
    std::string temp_str;
    int temp_int;
    std::cout << "Enter the " << task_name << " task priority : ";
    std::cin >> task_priority;
    std::cout << "If it's periodic, please enter the type : \nExamples: 1h:hour, 2h:2 hours, 12W:weakly, 1m:monthly, 1y:yearly\n";
    std::cin >> temp_str;
    std::cout << "Enter when you want it to start\nExamples: 13h2d5m2026y: hour 13, second day, May, 2026\n";
    std::cin >> starting;
}


