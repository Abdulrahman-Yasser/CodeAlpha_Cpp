#include "chrono_wrapper.hpp"
#include <cmath>
#include <cstring>
#include <iostream>
#include <type_traits>
namespace CHRONO_WR_NS
{
    Chrono_Wrapper::Chrono_Wrapper(std::chrono::time_point<std::chrono::system_clock> tp) : main_time_point(tp)
    {
    }
    void Chrono_Wrapper::change_tp(std::chrono::time_point<std::chrono::system_clock> tp)
    {
        main_time_point = tp;
    }

    void Chrono_Wrapper::change_tp(Chrono_Wrapper tp)
    {
        main_time_point = tp.main_time_point;
    }

    void Chrono_Wrapper::change_tp(std::string tp)
    {
        change_tp(tm_to_tp(string_to_date(tp)));
    }

    template <typename T>
    void Chrono_Wrapper::add_tp_duration(T the_duration)
    {
        if (!(std::is_same<T, std::chrono::minutes>::value ||
              std::is_same<T, std::chrono::hours>::value ||
              std::is_same<T, std::chrono::duration<int, std::ratio<86400>>>::value))
        {
            std::cout << "Wrong type\n";
            return;
        }

        main_time_point += the_duration;
    }

    void Chrono_Wrapper::add_tp_duration(std::string the_duration)
    {
        return add_tp_duration(string_to_duration(the_duration));
    }

    std::chrono::time_point<std::chrono::system_clock> Chrono_Wrapper::read_tp(void)
    {
        return main_time_point;
    }

    std::chrono::minutes subtract_two_tp(std::chrono::time_point<std::chrono::system_clock> tp_1,
                                                                std::chrono::time_point<std::chrono::system_clock> tp_2)
    {
        std::chrono::minutes temp = std::chrono::duration_cast<std::chrono::minutes>(tp_1 - tp_2);
        if (temp <= (std::chrono::minutes)0)
        {
            return (std::chrono::minutes)0;
        }
        else
        {
            return temp;
        }
    }

    std::chrono::minutes subtract_two_tp(std::chrono::time_point<std::chrono::system_clock> tp_1,
                                                                Chrono_Wrapper tp_2)
    {
        std::chrono::minutes temp = std::chrono::duration_cast<std::chrono::minutes>(tp_1 - tp_2.read_tp());
        if (temp <= (std::chrono::minutes)0)
        {
            return (std::chrono::minutes)0;
        }
        else
        {
            return temp;
        }
    }

    std::chrono::minutes subtract_two_tp(Chrono_Wrapper tp_1,
                                                                std::chrono::time_point<std::chrono::system_clock> tp_2)
    {
        std::chrono::minutes temp = std::chrono::duration_cast<std::chrono::minutes>(tp_1.read_tp() - tp_2);
        if (temp <= (std::chrono::minutes)0)
        {
            return (std::chrono::minutes)0;
        }
        else
        {
            return temp;
        }
    }

    std::chrono::minutes subtract_two_tp(Chrono_Wrapper tp_1,
                                                                Chrono_Wrapper tp_2)
    {
        std::chrono::minutes temp = std::chrono::duration_cast<std::chrono::minutes>(tp_1.read_tp() - tp_2.read_tp());
        if (temp <= (std::chrono::minutes)0)
        {
            return (std::chrono::minutes)0;
        }
        else
        {
            return temp;
        }
    }

    template <typename T>
    Chrono_Wrapper add_tp_with_dur(
        std::chrono::time_point<std::chrono::system_clock> tp_1,
        T dur)
    {
        if (!(std::is_same<T, std::chrono::minutes>::value ||
              std::is_same<T, std::chrono::hours>::value ||
              std::is_same<T, std::chrono::duration<int, std::ratio<86400>>>::value))
        {
            std::cout << "Wrong type\n";
            return Chrono_Wrapper{(std::chrono::time_point<std::chrono::system_clock>)0};
        }

        return Chrono_Wrapper{tp_1 + dur};
    }

    void Chrono_Wrapper::print(void)
    {
        std::time_t t_c = std::chrono::system_clock::to_time_t(main_time_point);
        std::cout << std::put_time(std::localtime(&t_c), "%F %T.");
    }

    std::chrono::time_point<std::chrono::system_clock> Chrono_Wrapper::tm_to_tp(tm rescheduled_time_point)
    {
        int temp;
        std::chrono::time_point<std::chrono::system_clock> triggered_time_point;

        /* Supposed to be only year, and other fields are zeros */
        triggered_time_point = std::chrono::floor<std::chrono::duration<int, std::ratio<31556952>>>(triggered_time_point);
        const std::time_t my_time_t = std::chrono::system_clock::to_time_t(triggered_time_point);
        tm *triggered_time_tm = std::localtime(&my_time_t);

        temp = rescheduled_time_point.tm_year - triggered_time_tm->tm_year;
        triggered_time_point = (triggered_time_point + (std::chrono::duration<int, std::ratio<31556952>>)temp);
        std::cout << "Difference in years is " << temp;

        temp = rescheduled_time_point.tm_mon - triggered_time_tm->tm_mon;
        triggered_time_point = triggered_time_point + (std::chrono::duration<int, std::ratio<2629746>>)temp;
        std::cout << ", Difference in months is " << temp;

        temp = rescheduled_time_point.tm_mday - triggered_time_tm->tm_mday;
        triggered_time_point = triggered_time_point + (std::chrono::duration<int, std::ratio<86400>>)temp;
        std::cout << ", Difference in days is " << temp;

        temp = rescheduled_time_point.tm_hour - triggered_time_tm->tm_hour;
        triggered_time_point = triggered_time_point + (std::chrono::duration<int, std::ratio<3600>>)temp;
        std::cout << ", Difference in hours is " << temp << "\n";

        return triggered_time_point;
    }

    tm Chrono_Wrapper::string_to_date(std::string string_dmy)
    {
        tm time_point_in_tm;
        int temp = 0;
        int str_len = string_dmy.size();
        char sign;
        for (int i = 0; i < str_len && string_dmy[i] != '\0'; ++i)
        {
            if (string_dmy[i] >= '0' && string_dmy[i] <= '9' && temp == 0)
            {
                temp = string_dmy[i] - '0';
                continue;
            }
            else if (string_dmy[i] >= '0' && string_dmy[i] <= '9' && temp != 0)
            {
                temp = (temp * 10) + string_dmy[i] - '0';
                continue;
            }
            else if (string_dmy[i] != '\0')
            {
                sign = string_dmy[i];
            }

            switch (sign)
            {
            case 'h':
            case 'H':
                time_point_in_tm.tm_hour = (temp - 4) % 24;
                break;
            case 'm':
            case 'M':
                time_point_in_tm.tm_mon = temp;
                break;
            case 'y':
            case 'Y':
                time_point_in_tm.tm_year = temp - 1900;
                break;
            case 'd':
            case 'D':
                time_point_in_tm.tm_mday = temp;
                break;
            default:
                break;
            }
            temp = 0;
        }
        std::cout << "Hour : " << time_point_in_tm.tm_hour << "Day : " << time_point_in_tm.tm_mday << " Month : " << time_point_in_tm.tm_mon << " Year : " << time_point_in_tm.tm_year << "\n";
        return time_point_in_tm;
    }

    std::chrono::minutes Chrono_Wrapper::string_to_duration(std::string string_dmy)
    {
        int temp  = 0, str_len = string_dmy.size() - 1;
        char sign;
        for (int i = 0; i < str_len && string_dmy[i] != '\0'; ++i)
        {
            if (string_dmy[i] >= '0' && string_dmy[i] <= '9' && temp == 0)
            {
                temp = string_dmy[i] - '0';
                continue;
            }
            else if (string_dmy[i] >= '0' && string_dmy[i] <= '9' && temp != 0)
            {
                temp = (temp * 10) + string_dmy[i] - '0';
                continue;
            }
            else if (string_dmy[i] != '\0')
            {
                sign = string_dmy[i];
            }

            switch (sign)
            {
            case 'h':
            case 'H':
                return (std::chrono::minutes)temp * 60;
            case 'm':
            case 'M':
                return (std::chrono::minutes)temp;
            case 'd':
            case 'D':
                return (std::chrono::minutes)temp * 60 * 24;
            default:
                break;
            }
        }
        return (std::chrono::minutes)0;
    }

}
