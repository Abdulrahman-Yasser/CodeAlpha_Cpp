#include "to-do_Element.hpp"
#include <cmath>
#include <cstring>
#include <iostream>
static std::string states_string[] = {"waiting", "running", "paused", "done"};

namespace TO_DO_ELEMENT_WR_NS
{
    To_Do_Element::To_Do_Element(  std::string start_date_dmy_str,
                    std::string the_name, 
                    unsigned char priority,
                    std::string is_it_periodic,
                    unsigned char id): name(the_name), priority(priority), periodicity(is_it_periodic), id(id)
    {
        this->execution_time = std::chrono::hours(24);
        reschedule_the_task(start_date_dmy_str);
    }

    To_Do_Element::To_Do_Element(  std::string the_name, 
                    unsigned char priority,
                    std::string is_it_periodic,
                    unsigned char id): name(the_name), priority(priority), periodicity(is_it_periodic), id(id)
    {
        this->execution_time = std::chrono::hours(24);
        this->start_time.change_tp(std::chrono::system_clock::now());
        change_end_time();
        change_nxt_time();
        check_task_state();
    }


    /* Copy constructor */
    To_Do_Element::To_Do_Element(const To_Do_Element &data) : To_Do_Element::To_Do_Element(data.name, data.priority, data.periodicity, data.id)
    {
    }

    /* Move constructor */
    To_Do_Element::To_Do_Element(To_Do_Element &&data) : To_Do_Element::To_Do_Element(data.name, data.priority, data.periodicity, data.id)
    {
    }

    void To_Do_Element::changing_task_execution(int duration_in_minutes)
    {
        execution_time = (std::chrono::minutes)duration_in_minutes;
        change_end_time();
        check_task_state();
    }

    bool To_Do_Element::is_that_you(std::string a_name)
    {
        if (a_name.compare(this->name) == 0)
        {
            return true;
        }
        return false;
    }

    bool To_Do_Element::is_that_you(int a_id)
    {
        if (a_id == this->id)
        {
            return true;
        }
        return false;
    }

    void To_Do_Element::change_nxt_time(void){
        nxt_time.change_tp(start_time);
        nxt_time.add_tp_duration(periodicity);
    }

    void To_Do_Element::delay_the_starting_time(std::string xxh_d_m_y){
        start_time.add_tp_duration(xxh_d_m_y);
        change_nxt_time();
        change_end_time();
        check_task_state();
    }

    void To_Do_Element::reschedule_the_task(std::string hdmy){
        start_time.change_tp(hdmy);
        change_nxt_time();
        change_end_time();
        check_task_state();
    }

    void To_Do_Element::reschedule_the_task(std::chrono::time_point<std::chrono::system_clock> tp){
        start_time.change_tp(tp);
        change_nxt_time();
        change_end_time();
        check_task_state();
    }


    void To_Do_Element::start_taskElement(void)
    {
        start_time.change_tp( std::chrono::system_clock::now() );
        change_end_time();
        change_nxt_time();
        check_task_state();
    }

    void To_Do_Element::pause_taskElement(void)
    {
        this->status = To_Do_state::paused;
        execution_time = CHRONO_WR_NS::Chrono_Wrapper::subtract_two_tp(end_time ,std::chrono::system_clock::now());
    }

    void To_Do_Element::end_taskElement(void)
    {
        this->status = To_Do_state::done;
        execution_time = CHRONO_WR_NS::Chrono_Wrapper::subtract_two_tp(start_time ,std::chrono::system_clock::now());
        end_time.change_tp(std::chrono::system_clock::now());
    }

    void To_Do_Element::print_task(void)
    {
        std::cout << "The task " << this->name << "\t| running since : ";
        start_time.print();
        std::cout << "\t| till ";
        end_time.print();
        std::chrono::minutes my_duration;
        switch (this->status)
        {
        case To_Do_state::waiting:
            std::cout << "status of task is : " << states_string[0] << "\t| "
                      << "start after ";
            my_duration = (std::chrono::minutes)starting_after_x_min();
            break;
        case To_Do_state::running:
            std::cout << "status of task is : " << states_string[1] << "\t| "
                      << "Remaining time ";
            my_duration = CHRONO_WR_NS::Chrono_Wrapper::subtract_two_tp(end_time ,std::chrono::system_clock::now());
            if (my_duration < (std::chrono::minutes)0)
            {
                my_duration = (std::chrono::minutes)0;
                this->status = To_Do_state::done;
            }
            break;
        case To_Do_state::paused:
            std::cout << "status of task is : " << states_string[2] << "\t| "
                      << "Remaining time ";
            my_duration = execution_time;
            break;
        case To_Do_state::done:
            std::cout << "status of task is : " << states_string[3] << "\t| "
                      << "Done for ";
            my_duration = (std::chrono::minutes)0;
            break;
        }

        std::cout << my_duration.count() << " minutes";
    }



    int To_Do_Element::ended_since_x_min(void)
    {
        std::chrono::minutes ended_since = CHRONO_WR_NS::Chrono_Wrapper::subtract_two_tp(std::chrono::system_clock::now(), end_time);
        if (ended_since.count() < 0)
        {
            ended_since = (std::chrono::minutes)0;
        }
        return ended_since.count();
    }

    int To_Do_Element::starting_after_x_min(void)
    {
        std::chrono::minutes starting_after = CHRONO_WR_NS::Chrono_Wrapper::subtract_two_tp(start_time ,std::chrono::system_clock::now());;
        if (starting_after.count() < 0)
        {
            starting_after = (std::chrono::minutes)0;
        }
        return starting_after.count();
    }


    void To_Do_Element::change_end_time(void)
    {
        end_time.change_tp(start_time);
        end_time.add_tp_duration(execution_time);
    }

    void To_Do_Element::check_task_state(void)
    {
        int temp = starting_after_x_min();
        if (temp == 0)
        {
            this->status = To_Do_state::running;
        }
        else
        {
            this->status = To_Do_state::waiting;
        }

        temp = ended_since_x_min();
        if (temp > 0)
        {
            this->status = To_Do_state::done;
        }
    }

}