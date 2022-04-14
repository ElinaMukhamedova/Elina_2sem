//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 14.04.2022.
//

#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int *ptr = nullptr;
    ptr = new int[n * 2];
    for (int i = 0; i < n; ++i)
        std::cin >> ptr[i * 2] >> ptr[i * 2 + 1];
    int k = 1;
    int pointA = 0;
    int pointB = 1;
    while (pointB < 2 * n - 1) {
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (ptr[2 * i] >= ptr[pointB] && flag == false) {
                flag = true;
                pointA = 2 * i;
                pointB = 2 * i + 1;
                k ++;
            }
        }
    }
    std::cout << k;
    delete[] ptr;
    return 0;
}
