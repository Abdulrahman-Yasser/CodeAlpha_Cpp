#include "../to-do_class/to-do.hpp"
#include <vector>
#include <string>

namespace to_do-app{
    class To_Do_App{
        private:
            class group_of_tasks{
                protected:
                    std::vector< std::vector < TO_DO_ELEMENT::To_Do_Element > > tasks_group;
                    std::string group_name;
            };

            static int group_counter ;
            static int Task_counter ;
            std::vector < TO_DO_ELEMENT::To_Do_Element > tasks;
        protected:
        public:
            To_Do_App(std::string group_name = "default", TO_DO_ELEMENT::To_Do_Element first_task):

            To_Do_App(std::string group_name = "default", std::vector< std::vector < TO_DO_ELEMENT::To_Do_Element > > tasks_group, TO_DO_ELEMENT::To_Do_Element first_task)

    };
}