//
//  X.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

double sum_int(int n) {
    double res = 0;
    for (int i = 1; i <= n; i++)
        res += 1 / (i * i);
    return res;
}

double sum_float(float n) {
    double res = 0;
    for (float i = 1; i <= n; i++)
        res += 1 / (i * i);
    return res;
}

double sum_double(double n) {
    double res = 0;
    for (double i = 1; i <= n; i++)
        res += 1 / (i * i);
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << "sum_int = " << sum_int(n) << std::endl;
    std::cout << "sum_float = " << sum_float(n) << std::endl;
    std::cout << "sum_double = " << sum_double(n) << std::endl;
    return 0;
}
