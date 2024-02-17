#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
 
int main()
{
    auto current = std::chrono::system_clock::now();

    auto now_timet = std::chrono::system_clock::to_time_t(current);
    auto now_local = std::localtime(&now_timet);
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl; 
    now_local->tm_hour = 4;
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl; 
    now_local->tm_mday = 4;
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl; 
    now_local->tm_mon = 4;
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl; 
    now_local->tm_year = 123;
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl; 
    now_local->tm_wday = 0;
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl; 


}