// https://www.hackerrank.com/challenges/one-week-preparation-kit-time-conversion/problem?h_l=interview&isFullScreen=true&playlist_slugs%5B%5D%5B%5D=preparation-kits&playlist_slugs%5B%5D%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D%5B%5D=one-week-day-one
#include <iostream>
#include <string>
#include <assert.h>

std::string timeConversion(std::string time)
{
    std::string period = time.substr(time.size() - 2, time.size());
    std::string hour = time.substr(0, 2);
    std::string rest = time.substr(2, 6);
    if (period == "PM" && hour != "12")
    {
        int newHour = std::stoi(hour) + 12;
        hour = std::to_string(newHour);
    }
    if (period == "AM" && hour == "12")
    {
        hour = "00";
    }

    std::cout << "The new hour is: " << hour + rest << "\n";

    return hour + rest;
}

int main(int argc, char const *argv[])
{
    std::string time1 = "12:01:00PM";
    std::string time2 = "12:01:00AM";
    std::string time3 = "07:05:45PM";

    std::string result = timeConversion(time1);
    std::string result2 = timeConversion(time2);
    std::string result3 = timeConversion(time3);

    assert((result == "12:01:00") && "The answer should be: 12:0100");
    assert((result2 == "00:01:00") && "The answer should be: 00:01:00");
    assert((result3 == "19:05:45") && "The answer should be: 19:05:45");
}
