//
//  G.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main(){
    int n;
    bool f = false;
    std::cin >> n;
    for (int i = 2; 2 * i <= n; i++){
        if (n % i == 0) {
            if (f == true)
                std::cout << ' ' << n / i;
            else {
                std::cout << n / i;
                f = true;
            }
        }
    }
    std::cout << '\n';
    return 0;
}
