#ifndef CHRONO_WRAPPER
#define CHRONO_WRAPPER

#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>

namespace CHRONO_WR_NS
{
    class Chrono_Wrapper
    {
    private:
        std::chrono::time_point<std::chrono::system_clock> main_time_point;
        tm string_to_date(std::string string_dmy);
        std::chrono::time_point<std::chrono::system_clock> tm_to_tp(tm rescheduled_time_point);
        std::chrono::minutes string_to_duration(std::string string_dmy);

    public:
        Chrono_Wrapper(std::chrono::time_point<std::chrono::system_clock> tp = std::chrono::system_clock::now());
        void change_tp(std::chrono::time_point<std::chrono::system_clock> tp);
        void change_tp(Chrono_Wrapper tp);
        void change_tp(std::string tp);

        template <typename T>
        void add_tp_duration(T the_duration);

        void add_tp_duration(std::string the_duration);

        void print(void);

        std::chrono::time_point<std::chrono::system_clock> read_tp(void);

        static std::chrono::minutes subtract_two_tp(   std::chrono::time_point<std::chrono::system_clock> tp_1, 
                                    std::chrono::time_point<std::chrono::system_clock> tp_2);

        static std::chrono::minutes subtract_two_tp(   Chrono_Wrapper tp_1, 
                                    std::chrono::time_point<std::chrono::system_clock> tp_2);

        static std::chrono::minutes subtract_two_tp(   std::chrono::time_point<std::chrono::system_clock> tp_1, 
                                    Chrono_Wrapper tp_2);

        static std::chrono::minutes subtract_two_tp(Chrono_Wrapper tp_1,
                                                                Chrono_Wrapper tp_2);

        template <typename T>
        static std::chrono::time_point<std::chrono::system_clock> add_tp_with_dur(   
                    std::chrono::time_point<std::chrono::system_clock> tp_1, 
                    T dur);
        
    };
}

#endif