//
//  D.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main() {
    int x;
    int ans = -1;
    while (std::cin >> x){
        if (x == 0)
            break;
        else if (x % 2 == 0){
            if (ans == -1 || x > ans)
                ans = x;
        }
    }
    if (ans != -1)
        std::cout << ans << std::endl;
    else
        std::cout << '\n';
    return 0;
}
