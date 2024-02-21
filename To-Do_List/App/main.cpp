#include "../DS/LinkedList.hpp"
#include "../ToDo_Element/to-do_Element.hpp"
#include <chrono>




int main(void)
{
    std::chrono::time_point<std::chrono::system_clock> the_time = std::chrono::system_clock::now();
    std::chrono::duration<long, std::ratio<1, 60>> exec ;
    TO_DO_ELEMENT::To_Do_Element first_ele("first_task", 1, the_time, exec);
    LinkedList my_ll();
    my_ll.insertNode(first_ele);
}