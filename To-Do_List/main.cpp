#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
int main(){
    std::chrono::time_point<std::chrono::system_clock> p{};
    std::chrono::time_point<std::chrono::system_clock> pw = std::chrono::system_clock::now();
    auto now_timet = std::chrono::system_clock::to_time_t(p);
    auto now_local = localtime(&now_timet);
    std::cout << "Local Time " << std::put_time(now_local, "%c") << std::endl;
    const auto time { std::chrono::floor<std::chrono::hours>(p) } ; 
    auto another_timet = std::chrono::system_clock::to_time_t(time);
    auto another_local = localtime(&another_timet);
    std::cout << "Local Time " << std::put_time(another_local, "%c") << std::endl;
    // std::cout << p << pw;
}