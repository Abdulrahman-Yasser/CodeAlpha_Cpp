#include <string.h>
#include <chrono>
#include <stdbool.h>


namespace TO_DO_ELEMENT
{
    class To_Do_Element{
        private:
            class enum To_Do_state{
                waitig,
                pending,
                doing,
                paused,
                done
            };
            static counter = 0;
        protected:
            string          name;
            To_Do_state     status = waiting;
            int id;
            std::time_point starting_time;.
            std::time_point ending_time;
            duration<long, ratio<60>>             Execution_Time = 0;
            bool            periodeic;
        public:
            bool Element_Run();
            bool Element_Finished();
            bool Element_waiting();
    };

}
