//
//  F.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    bool f = true;
    int d = 2;
    while (d * d <= n && f == true) {
        if (n % d == 0)
            f = false;
        d++;
    }
    if (f == true)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}
