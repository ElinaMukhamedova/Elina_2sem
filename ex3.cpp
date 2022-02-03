//
//  ex3.cpp
//  
//
//  Created by Elina Mukhamedova on 03.02.2022.
//

#include <iostream>
#include <string>
#include <cmath>

int main() {
    int n = 0;
    std::cin >> n;
    int ans = 1;
    while (n > 0){
        ans *= n;
        n -= 1;
    }
    std::cout << ans << std::endl;
    return 0;
}

