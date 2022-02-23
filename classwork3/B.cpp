//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 17.02.2022.
//

#include <iostream>

int main() {
    int const n = 10;
    int m[n] = {0};
    for (int k = 0; k < n; k++)
        std::cin >> m[k];
    int z = 0;
    std::cin >> z;
    int a = 0;
    int b = n - 1;
    int h = n / 2;
    int ans = -1;
    bool f = false;
    while (m[a] <= z && m[b] >= z && b - a > 1 && f == false) {
        if (m[a] == z) {
            f = true;
            ans = a;
        }
        else if (m[b] == z) {
            f = true;
            ans = b;
            }
            else {
                h = (a + b) / 2;
                if (m[h] <= z) {
                    a = h;
                }
                else {
                    b = h;
                }
            }
    }
    if (f == true)
        std::cout << ans + 1 << std::endl;
    else
        std::cout << "NO" << std::endl;
}
