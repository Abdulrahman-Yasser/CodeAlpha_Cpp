
#ifndef TO_DO_ELEMENT_HPP
#define TO_DO_ELEMENT_HPP



#include <string>
#include <stdbool.h>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "../chrono_wrapper/chrono_wrapper.hpp"

namespace TO_DO_ELEMENT_WR_NS
{
enum class time_type{
    year,
    month,
    day,
    hour,
    minute,
    seconds
};

class To_Do_Element{
public:
    unsigned char priority;

    To_Do_Element(  std::string start_date_dmy_str,
                    std::string the_name = "not_defined", 
                    unsigned char priority = 255,
                    std::string is_it_periodic = "0s",
                    unsigned char id = 0
                    );

    To_Do_Element(  std::string the_name = "not_defined", 
                    unsigned char priority = 255,
                    std::string is_it_periodic = "0s",
                    unsigned char id = 0
                    );

    /* Copy constructor */
    To_Do_Element(const To_Do_Element& data);

    /* Move constructor */
    To_Do_Element(To_Do_Element&& data);
    void start_taskElement(void);
    void pause_taskElement(void);
    void end_taskElement(void);

    void print_task(void);

    void changing_task_execution(int duration_in_minutes);
    void reschedule_the_task(std::string hdmy);
    void delay_the_starting_time(std::string xxh_d_m_y);
    bool is_that_you(std::string a_name);
    bool is_that_you(int a_id);
    int starting_after_x_min(void);
    int ended_since_x_min(void);
private:
    enum class To_Do_state{
        waiting,
        running,
        paused,
        done
    };
    CHRONO_WR_NS::Chrono_Wrapper start_time, end_time, nxt_time;
    std::string                 name;
    std::chrono::minutes        execution_time;
    To_Do_state                 status = To_Do_state::waiting;
    void change_end_time(void);
    void check_task_state(void);
    void change_nxt_time(void);
protected:
    std::string                 periodicity;
    unsigned char               id;

};

}


#endif