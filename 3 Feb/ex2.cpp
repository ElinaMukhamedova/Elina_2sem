//
//  main.cpp
//  упражнение 2
//
//  Created by Elina Mukhamedova on 03.02.2022.
//

#include <iostream>
#include <string>
#include <cmath>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    int D = b * b - 4 * a * c;
    if (D < 0)
        std::cout << '\n';
    else
        if (D == 0)
            std::cout << (-b / (2 * a));
        else{
            double sD = std::sqrt(D);
            double x1 = (-b - sD) / (2 * a);
            double x2 = (-b + sD) / (2 * a);
            std::cout << x1 << x2 << std::endl;
            }
    return 0;
}
