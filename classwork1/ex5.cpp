//
//  ex5.cpp
//  
//
//  Created by Elina Mukhamedova on 03.02.2022.
//

#include <iostream>
#include <string>
#include <cmath>

int main() {
    int n = 0;
    int m = 0;
    int p = 0;
    int a = 0;
    int b = 0;
    std::cin >> n >> m;
    if (n >= m){
        a = n;
        b = m;
    }
    else{
        a = m;
        b = n;
    }
    p = a;
    while (p % b != 0)
        p += a;
    std::cout << p << std::endl;
    return 0;
}
