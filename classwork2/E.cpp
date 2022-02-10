//
//  E.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main(){
    int x;
    int k = 0;
    int m = -1;
    while (std::cin >> x) {
        if (x == 0)
            break;
        else {
            if (m == -1 || x > m) {
                m = x;
                k = 1;
            }
            else if (x == m)
                k++;
        }
    }
    std::cout << k << std::endl;
    return 0;
}
