//
//  C.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main() {
    int x;
    std::cin >> x;
    int n = x;
    bool f = true;
    while (f == true) {
        if (n % 2 != 0)
            f = false;
        else
            n /= 2;
    }
    if (n == 1)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}
