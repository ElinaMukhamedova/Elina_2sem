//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 14.04.2022.
//

#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int k7 = 0, k49 = 0, k98 = 0;
    while (k98 * 98 < n) {
        k98 ++;
    }
    k98--;
    n -= k98 * 98;
    while (k49 * 49 < n) {
        k49 ++;
    }
    k49--;
    n -= k49 * 49;
    while (k7 * 7 < n) {
        k7 ++;
    }
    k7--;
    n -= k7 * 7;
    int k = k7 + k98 + k49 + n;
    std::cout << k;
    return 0;
}
