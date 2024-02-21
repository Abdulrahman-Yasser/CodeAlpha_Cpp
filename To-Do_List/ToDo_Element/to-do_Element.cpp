#include "to-do_Element.hpp"



namespace TO_DO_ELEMENT{
    To_Do_Element::To_Do_Element(std::string the_name = "not_defined", int id = -1, std::chrono::time_point<std::chrono::system_clock> start = std::chrono::time_point<std::chrono::system_clock>(0), std::chrono::duration<long, std::ratio<1, 60>> exec ):
        name(the_name), id(id), starting_time(start), Execution_Time(exec)
    {
        if(starting_time == std::chrono::time_point<std::chrono::system_clock>(0)){
            starting_time = std::chrono::system_clock::now();
        }
        if(this->Execution_Time == 0s){
            this->Execution_Time = 1d;
        }
        ending_time = starting_time + Execution_Time;
        status = waiting;
    }

    /* Copy constructor */
    To_Do_Element::To_Do_Element(const To_Do_Element& data)
        To_Do_Element::To_Do_Element(data->name, data->id, data->starting_time, data->Execution_Time)
    {

    }

    /* Move constructor */
    To_Do_Element::To_Do_Element(To_Do_Element&& data):
        To_Do_Element::To_Do_Element(data.name, data.id, data.starting_time, data.Execution_Time)
    {

    }


    void To_Do_Element::delay_taskElement(std::chrono::duration<long, std::ratio<1, 60>> x)
    {
        this->starting_time = this->starting_time + x;
        this->status = To_Do_state::waiting;
    }

    void To_Do_Element::expand_taskElement(std::chrono::duration<long, std::ratio<1, 60>> x)
    {
        this->Execution_Time = this->Execution_Time + x;
        this->status = To_Do_state::running;
    }


    void To_Do_Element::start_taskElement(void)
    {
        this->status = To_Do_state::running;
    }

    void To_Do_Element::pause_taskElement(void)
    {
        this->status = To_Do_state::paused;
    }

    void To_Do_Element::end_taskElement(void)
    {
        this->status = To_Do_state::done;
    }
}