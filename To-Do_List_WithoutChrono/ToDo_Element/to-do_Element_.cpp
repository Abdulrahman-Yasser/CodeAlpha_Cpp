// #include "to-do_Element.hpp"
// #include <cmath>
// #include <cstring>
// #include <iostream>
// static std::string states_string[] = {"waiting", "running", "paused", "done"};

// namespace TO_DO_ELEMENT_NS
// {
//     To_Do_Element::To_Do_Element(  std::string start_date_dmy_str,
//                     std::string the_name, 
//                     unsigned char priority,
//                     std::string is_it_periodic,
//                     unsigned char id): name(the_name), priority(priority), periodicity(is_it_periodic), id(id)
//     {
//         this->execution_time = std::chrono::hours(24);
//         reschedule_the_task(start_date_dmy_str);
//         this->end_time = this->start_time + this->execution_time;
//         change_nxt_time();
//         check_task_state();
//     }

//     To_Do_Element::To_Do_Element(  std::string the_name, 
//                     unsigned char priority,
//                     std::string is_it_periodic,
//                     unsigned char id): name(the_name), priority(priority), periodicity(is_it_periodic), id(id)
//     {
//         this->execution_time = std::chrono::hours(24);
//         this->start_time = std::chrono::system_clock::now();
//         this->end_time = this->start_time + this->execution_time;
//         change_nxt_time();
//         check_task_state();
//     }


//     /* Copy constructor */
//     To_Do_Element::To_Do_Element(const To_Do_Element &data) : To_Do_Element::To_Do_Element(data.name, data.priority, data.periodicity, data.id)
//     {
//     }

//     /* Move constructor */
//     To_Do_Element::To_Do_Element(To_Do_Element &&data) : To_Do_Element::To_Do_Element(data.name, data.priority, data.periodicity, data.id)
//     {
//     }

//     void To_Do_Element::changing_task_execution(int duration_in_minutes)
//     {
//         delay_time_point(duration_in_minutes, 'm', execution_time);
//         change_end_times();
//         check_task_state();
//     }

//     bool To_Do_Element::is_that_you(std::string a_name)
//     {
//         if (a_name.compare(this->name) == 0)
//         {
//             return true;
//         }
//         return false;
//     }

//     bool To_Do_Element::is_that_you(int a_id)
//     {
//         if (a_id == this->id)
//         {
//             return true;
//         }
//         return false;
//     }

//     void To_Do_Element::change_nxt_time(void){
//         delay_time_point(periodicity, nxt_time, start_time);
//     }

//     void To_Do_Element::delay_the_starting_time(std::string xxh_d_m_y){
//         delay_time_point(xxh_d_m_y, start_time);
//         change_nxt_time();
//         change_end_times();
//         check_task_state();
//     }

//     void To_Do_Element::reschedule_the_task(std::string hdmy){
//         reschedule_the_task(string_to_date(hdmy));
//     }

//     void To_Do_Element::reschedule_the_task(tm the_starting_time)
//     {
//         reschedule_time_point(the_starting_time, start_time);
//         change_end_times();
//         check_task_state();
//         change_nxt_time();
//     }


//     void To_Do_Element::delay_time_point(int the_delay, char sign, std::chrono::time_point<std::chrono::system_clock> &the_triggered_time)
//     {
//         switch (sign)
//         {
//         case 'h':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<3600>>)the_delay;
//             break;
//         case 'd':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<86400>>)the_delay;
//             break;
//         case 'w':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<604800>>)the_delay;
//             break;
//         case 'm':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<2629746>>)the_delay;
//             break;
//         case 'y':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<31556952>>)the_delay;
//             break;
//         }
//     }

//     void To_Do_Element::delay_time_point(int the_delay, char sign, std::chrono::minutes &the_triggered_time)
//     {
//         switch (sign)
//         {
//         case 'h':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<3600>>)the_delay;
//             break;
//         case 'd':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<86400>>)the_delay;
//             break;
//         case 'w':
//             the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<604800>>)the_delay;
//             break;
//         default:
//             break;
//         }
//     }

//     void To_Do_Element::delay_time_point(std::string the_delay, std::chrono::time_point<std::chrono::system_clock> &the_triggered_time, std::chrono::time_point<std::chrono::system_clock> change_based_on)
//     {
//         int temp = 0, str_length = the_delay.size();
//         char the_sign;
//         for (int i = 0; i < str_length && the_delay[i] != '\0'; ++i)
//         {
//             if (the_delay[i] >= '0' && the_delay[i] <= '9' && temp == 0)
//             {
//                 temp = the_delay[i] - '0';
//                 continue;
//             }
//             else if (the_delay[i] >= '0' && the_delay[i] <= '9' && temp != 0)
//             {
//                 temp = (temp * 10) + (the_delay[1] - '0');
//                 continue;
//             }
//             else if (the_delay[i] != '\0')
//             {
//                 the_sign = the_delay[i];
//             }
//             switch (the_sign)
//             {
//             case 'h':
//                 the_triggered_time = change_based_on + (std::chrono::duration<int, std::ratio<3600>>)temp;
//                 break;
//             case 'd':
//                 the_triggered_time = change_based_on + (std::chrono::duration<int, std::ratio<86400>>)temp;
//                 break;
//             case 'w':
//                 the_triggered_time = change_based_on + (std::chrono::duration<int, std::ratio<604800>>)temp;
//                 break;
//             case 'm':
//                 the_triggered_time = change_based_on + (std::chrono::duration<int, std::ratio<2629746>>)temp;
//                 break;
//             case 'y':
//                 the_triggered_time = change_based_on + (std::chrono::duration<int, std::ratio<31556952>>)temp;
//                 break;
//             }
//             temp = 0;
//         }
//     }

//     void To_Do_Element::delay_time_point(std::string the_delay, std::chrono::time_point<std::chrono::system_clock>& the_triggered_time)
//     {
//         int temp = 0, str_length = the_delay.size();
//         char the_sign;
//         for (int i = 0; i < str_length && the_delay[i] != '\0'; ++i)
//         {
//             if (the_delay[i] >= '0' && the_delay[i] <= '9' && temp == 0)
//             {
//                 temp = the_delay[i] - '0';
//                 continue;
//             }
//             else if (the_delay[i] >= '0' && the_delay[i] <= '9' && temp != 0)
//             {
//                 temp = (temp * 10) + (the_delay[1] - '0');
//                 continue;
//             }
//             else if (the_delay[i] != '\0')
//             {
//                 the_sign = the_delay[i];
//             }
//             switch (the_sign)
//             {
//             case 'h':
//                 the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<3600>>)temp;
//                 break;
//             case 'd':
//                 the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<86400>>)temp;
//                 break;
//             case 'w':
//                 the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<604800>>)temp;
//                 break;
//             case 'm':
//                 the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<2629746>>)temp;
//                 break;
//             case 'y':
//                 the_triggered_time = the_triggered_time + (std::chrono::duration<int, std::ratio<31556952>>)temp;
//                 break;
//             }
//             temp = 0;
//         }
//     }



//     void To_Do_Element::reschedule_time_point(tm rescheduled_time_point, std::chrono::time_point<std::chrono::system_clock> &triggered_time_point)
//     {
//         int temp;

//         /* Supposed to be only year, and other fields are zeros */
//         triggered_time_point = std::chrono::floor<std::chrono::duration<int, std::ratio<31556952>>>(triggered_time_point);
//         const std::time_t my_time_t = std::chrono::system_clock::to_time_t(triggered_time_point);
//         tm *triggered_time_tm = std::localtime(&my_time_t);

//         temp = rescheduled_time_point.tm_year - triggered_time_tm->tm_year;
//         triggered_time_point = (triggered_time_point + (std::chrono::duration<int, std::ratio<31556952>>)temp);
//         std::cout << "Difference in years is "<< temp ;

//         temp = rescheduled_time_point.tm_mon - triggered_time_tm->tm_mon;
//         triggered_time_point = triggered_time_point + (std::chrono::duration<int, std::ratio<2629746>>)temp;
//         std::cout << ", Difference in months is "<< temp ;

//         temp = rescheduled_time_point.tm_mday - triggered_time_tm->tm_mday;
//         triggered_time_point = triggered_time_point + (std::chrono::duration<int, std::ratio<86400>>)temp;
//         std::cout << ", Difference in days is "<< temp ;

//         temp = rescheduled_time_point.tm_hour - triggered_time_tm->tm_hour;
//         triggered_time_point = triggered_time_point + (std::chrono::duration<int, std::ratio<3600>>)temp;
//         std::cout << ", Difference in hours is "<< temp << "\n";
//     }



//     void To_Do_Element::start_taskElement(void)
//     {
//         this->status = To_Do_state::running;
//         start_time = std::chrono::system_clock::now();
//         change_end_times();
//         change_nxt_time();
//     }

//     void To_Do_Element::pause_taskElement(void)
//     {
//         this->status = To_Do_state::paused;
//         execution_time = std::chrono::duration_cast<std::chrono::minutes>(end_time - std::chrono::system_clock::now());
//         execution_time = std::chrono::abs(execution_time);
//     }

//     void To_Do_Element::end_taskElement(void)
//     {
//         this->status = To_Do_state::done;
//         execution_time = std::chrono::duration_cast<std::chrono::minutes>(start_time - std::chrono::system_clock::now());
//         execution_time = std::chrono::abs(execution_time);
//         end_time = std::chrono::system_clock::now();
//     }

//     void To_Do_Element::print_task(void)
//     {
//         std::cout << "The task " << this->name << "\t| running since : ";
//         std::time_t t_c = std::chrono::system_clock::to_time_t(start_time);
//         std::cout << std::put_time(std::localtime(&t_c), "%F %T.");
//         t_c = std::chrono::system_clock::to_time_t(end_time);
//         std::cout << "\t| till "
//                   << std::put_time(std::localtime(&t_c), "%F %T.");
//         std::chrono::minutes my_duration;
//         switch (this->status)
//         {
//         case To_Do_state::waiting:
//             std::cout << "status of task is : " << states_string[0] << "\t| "
//                       << "start after ";
//             my_duration = (std::chrono::minutes)starting_after_x_min();
//             break;
//         case To_Do_state::running:
//             std::cout << "status of task is : " << states_string[1] << "\t| "
//                       << "Remaining time ";
//             my_duration = std::chrono::duration_cast<std::chrono::minutes>(end_time - std::chrono::system_clock::now());
//             if (my_duration < (std::chrono::minutes)0)
//             {
//                 my_duration = (std::chrono::minutes)0;
//                 this->status = To_Do_state::done;
//             }
//             break;
//         case To_Do_state::paused:
//             std::cout << "status of task is : " << states_string[2] << "\t| "
//                       << "Remaining time ";
//             my_duration = execution_time;
//             break;
//         case To_Do_state::done:
//             std::cout << "status of task is : " << states_string[3] << "\t| "
//                       << "Done for ";
//             my_duration = (std::chrono::minutes)0;
//             break;
//         }

//         std::cout << my_duration.count() << " minutes";
//     }



//     int To_Do_Element::ended_since_x_min(void)
//     {
//         std::chrono::minutes ended_since = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::system_clock::now() - end_time);
//         if (ended_since.count() < 0)
//         {
//             ended_since = (std::chrono::minutes)0;
//         }
//         return ended_since.count();
//     }

//     int To_Do_Element::starting_after_x_min(void)
//     {
//         std::chrono::minutes starting_after = std::chrono::duration_cast<std::chrono::minutes>(start_time - std::chrono::system_clock::now());
//         if (starting_after.count() < 0)
//         {
//             starting_after = (std::chrono::minutes)0;
//         }
//         return starting_after.count();
//     }


//     void To_Do_Element::change_end_times(void)
//     {
//         if (execution_time == std::chrono::minutes(0))
//         {
//             end_time = start_time + std::chrono::hours(24);
//         }
//         else
//         {
//             end_time = start_time + execution_time;
//         }
//     }

//     void To_Do_Element::check_task_state(void)
//     {
//         int temp = starting_after_x_min();
//         if (temp == 0)
//         {
//             this->status = To_Do_state::running;
//         }
//         else
//         {
//             this->status = To_Do_state::waiting;
//         }

//         temp = ended_since_x_min();
//         if (temp > 0)
//         {
//             this->status = To_Do_state::done;
//         }
//     }

//     tm To_Do_Element::string_to_date(std::string string_dmy)
//     {
//         tm time_point_in_tm;
//         int temp = 0;
//         int str_len = string_dmy.size();
//         char sign;
//         if(str_len < 2){
//             return time_point_in_tm;
//         }
//         for (int i = 0; i < str_len && string_dmy[i] != '\0'; ++i)
//         {
//             if (string_dmy[i] >= '0' && string_dmy[i] <= '9' && temp == 0)
//             {
//                 temp = string_dmy[i] - '0';
//                 continue;
//             }
//             else if (string_dmy[i] >= '0' && string_dmy[i] <= '9' && temp != 0)
//             {
//                 temp = (temp * 10) + string_dmy[i] - '0';
//                 continue;
//             }
//             else if (string_dmy[i] != '\0')
//             {
//                 sign = string_dmy[i];
//             }

//             switch (sign)
//             {
//             case 'h':
//             case 'H':
//                 time_point_in_tm.tm_hour = (temp - 4)%24;
//                 break;
//             case 'm':
//             case 'M':
//                 time_point_in_tm.tm_mon = temp;
//                 break;
//             case 'y':
//             case 'Y':
//                 time_point_in_tm.tm_year = temp - 1900;
//                 break;
//             case 'd':
//             case 'D':
//                 time_point_in_tm.tm_mday = temp;
//                 break;
//             default:
//                 break;
//             }
//             temp = 0;
//         }
//         std::cout << "Hour : " << time_point_in_tm.tm_hour << "Day : " << time_point_in_tm.tm_mday << " Month : " <<  time_point_in_tm.tm_mon << " Year : " << time_point_in_tm.tm_year << "\n";
//         return time_point_in_tm;
//     }


// }