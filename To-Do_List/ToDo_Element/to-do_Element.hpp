#include <string.h>
#include <chrono>
#include <stdbool.h>


namespace TO_DO_ELEMENT
{
class To_Do_Element{
private:
    enum class To_Do_state{
        waiting,
        running,
        paused,
        done
    };
protected:
    std::string          name;
    To_Do_state     status = To_Do_state::waiting;
    int id;
    std::chrono::time_point<std::chrono::system_clock> starting_time;
    std::chrono::time_point<std::chrono::system_clock> ending_time;
    std::chrono::duration<long, std::ratio<1, 60>>             Execution_Time;
    bool            periodeic;
public:
    To_Do_Element(std::string the_name = "not_defined", int id = -1, std::chrono::time_point<std::chrono::system_clock> start = std::chrono::time_point<std::chrono::system_clock>(), std::chrono::duration<long, std::ratio<1, 60>> exec );

    /* Copy constructor */
    To_Do_Element(const To_Do_Element& data);

    /* Move constructor */
    To_Do_Element(To_Do_Element&& data);
    void delay_taskElement(std::chrono::duration<long, std::ratio<1, 60>>);
    void expand_taskElement(std::chrono::duration<long, std::ratio<1, 60>>);
    void start_taskElement(void);
    void pause_taskElement(void);
    void end_taskElement(void);
};

}
