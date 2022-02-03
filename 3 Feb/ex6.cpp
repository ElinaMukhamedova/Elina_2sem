//
//  ex6.cpp
//  
//
//  Created by Elina Mukhamedova on 03.02.2022.
//

#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    int c = 0;
    while (a % b != 0) {
        c = a - b;
        if (b >= c) {
            a = b;
            b = c;
        }
        else {
            a = c;
        }
    }
    return b;
}

int lcm(int a, int b) {
    int res = a;
    while (res % b != 0) {
        res += a;
    }
    return res;
}

int main() {
    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    std::cin >> n >> m;
    if (n >= m){
        a = n;
        b = m;
    }
    else {
        a = m;
        b = n;
    }
    std::cout << "gcd = " << gcd(a, b) << ", lcm = " << lcm(a, b) << "\n";
    return 0;
}
