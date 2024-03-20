#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>

void change_unit(unsigned char value, std::chrono::time_point<std::chrono::system_clock> &the_time, int type);

// int main()
// {
//     // Reduce verbosity but let you know what is in what namespace
//     namespace C = std::chrono;
//     namespace D = date;
//     namespace S = std;

//     auto tp = C::system_clock::now(); // tp is a C::system_clock::time_point
//     {
//         // Need to reach into namespace date for this streaming operator
//         using namespace date;
//         S::cout << tp << '\n';
//     }
//     auto dp = D::floor<D::days>(tp);  // dp is a sys_days, which is a
//                                       // type alias for a C::time_point
//     auto ymd = D::year_month_day{dp};
//     auto time = D::make_time(C::duration_cast<C::milliseconds>(tp-dp));
//     S::cout << "year        = " << ymd.year() << '\n';
//     S::cout << "month       = " << ymd.month() << '\n';
//     S::cout << "day         = " << ymd.day() << '\n';
//     S::cout << "hour        = " << time.hours().count() << "h\n";
//     S::cout << "minute      = " << time.minutes().count() << "min\n";
//     S::cout << "second      = " << time.seconds().count() << "s\n";
//     S::cout << "millisecond = " << time.subseconds().count() << "ms\n";
// }

int main()
{
    using namespace std::literals;
    std::chrono::time_point<std::chrono::system_clock> first_time = std::chrono::system_clock::now();

    first_time = std::chrono::floor<std::chrono::duration<int, std::ratio<31556952>>>(first_time);


    // const std::time_t t_c = std::chrono::system_clock::to_time_t(first_time + 7h);
    // change_unit(2, first_time, 1);
    // change_unit(2, first_time, 2);
    // change_unit(2, first_time, 3);
    // change_unit(2, first_time, 4);
    // change_unit(2, first_time, 5);
    // change_unit(2, first_time, 6);
    // std::cout << "in minutes, the time was "
    //           << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    const std::time_t t_c = std::chrono::system_clock::to_time_t(first_time);
    // std::cout << "in years, the time was "
    //         << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;

    auto q = std::localtime(&t_c);
    std::cout << q->tm_year << std::endl;
    std::cout << q->tm_mday << std::endl;
    std::cout << q->tm_mon << std::endl;
    std::cout << q->tm_hour << std::endl;
}

void change_unit(unsigned char value, std::chrono::time_point<std::chrono::system_clock> &the_time, int type)
{
    // std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
    // std::time_t now_local = localtime(&now_timet);

    // std::chrono::duration<int, std::ratio<31556952>> years_value;
    switch (type)
    {
    case 1:
    {
        the_time = the_time + (std::chrono::duration<int, std::ratio<31556952>>)value;
        const std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
        std::cout << "in years, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    }
    break;

    case 2:
    {
        the_time = the_time + (std::chrono::duration<int, std::ratio<2629746>>)value;
        const std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
        std::cout << "in months, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    }
    break;

    case 3:
    {
        the_time = the_time + (std::chrono::duration<int, std::ratio<604800>>)value;
        const std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
        std::cout << "in weeks, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    }
    break;

    case 4:
    {
        the_time = the_time + (std::chrono::duration<int, std::ratio<86400>>)value;
        const std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
        std::cout << "in days, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    }
    break;

    case 5:
    {
        the_time = the_time + (std::chrono::duration<int, std::ratio<3600>>)value;
        const std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
        std::cout << "in hours, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    }
    break;

    case 6:
    {
        the_time = the_time + (std::chrono::duration<int, std::ratio<60>>)value;
        const std::time_t t_c = std::chrono::system_clock::to_time_t(the_time);
        std::cout << "in minutes, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::endl;
    }
    break;
    default:
        break;
    }

    // now_local->tm_hour = hour;
    // the_time = std::chrono::system_clock::from_time_t(now_local);
}
