//
//  I.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

bool is_prime(int a) {
    bool f = true;
    int d = 2;
    while (d * d <= a && f == true) {
        if (a % d == 0)
            f = false;
        d++;
    }
    return f;
}

int main() {
    int n;
    bool f = false;
    std::cin >> n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0)
            if (is_prime(i) == true){
                if (f == false) {
                    std::cout << i;
                    f = true;
                }
                else
                    std::cout << ' ' << i;
            }
    }
    std::cout << '\n';
    return 0;
}
