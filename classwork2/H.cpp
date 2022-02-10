//
//  H.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int power(int a, int b) {
    int res = 1;
    for (int i = 1; i <= b; i++)
        res *= a;
    return res;
}

int main() {
    int n;
    std::cin >> n;
    int a;
    std::cin >> a;
    int copy = a;
    int inp;
    int b = 0;
    for (int i = 1; i <= n; i++) {
        inp = copy % 10;
        copy = (copy - inp) / 10;
        b = b * 10 + inp;
    }
    if (b == a)
        std::cout << 1 << std::endl;
    else
        std::cout << b << std::endl;
    return 0;
}
