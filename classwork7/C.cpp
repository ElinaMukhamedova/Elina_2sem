//
//  C.cpp
//  
//
//  Created by Elina Mukhamedova on 21.03.2022.
//

#include <iostream>

struct Time {
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(unsigned int t_hours, unsigned int t_minutes, unsigned int t_seconds) {
        hours = t_hours;
        minutes = t_minutes;
        seconds = t_seconds;
    }
    
    Time operator+ (const Time& other) const {
        int unitary1 = seconds + 60 * minutes + 3600 * hours;
        int unitary2 = other.seconds + 60 * other.minutes + 3600 * other.hours;
        int unitary = (unitary1 + unitary2) % (3600 * 24);
        unsigned int h = unitary / 3600;
        unsigned int m = (unitary - h * 3600) / 60;
        unsigned int s = unitary - h * 3600 - m * 60;
        Time sum = Time(h, m, s);
        return sum;
    }
    
    friend std::ostream& operator<<(std::ostream &output, const Time & other) {
        output << other.hours << ":" << other.minutes << ":" << other.seconds;
        return output;
    }
};

int main() {
    int h1 = 0, m1 = 0, s1 = 0, h2 = 0, m2 = 0, s2 = 0;
    std::cin >> h1 >> m1 >> s1;
    std::cin >> h2 >> m2 >> s2;
    Time now = Time(h1, m1, s1);
    Time plus = Time(h2, m2, s2);
    Time result = now + plus;
    //std::cout << result.hours << result.minutes << result.seconds << std::endl;
    std::cout << result << std::endl;
}
