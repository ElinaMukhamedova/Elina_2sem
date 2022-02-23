//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 17.02.2022.
//

#include <iostream>

int main() {
    int const n = 5;
    int a[n] = {0};
    for (int k = 0; k < n; k++)
        std::cin >> a[k];
    int i = 1;
    int j = 2;
    int c = 0;
    while (i < n) {
        if (a[i - 1] > a[i]) {
            i = j;
            j++;
        }
        else {
            c = a[i - 1];
            a[i - 1] = a[i];
            a[i] = c;
            i = i - 1;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
    for (int k = 0; k < n; k++)
        std::cout << a[k] << ' ';
}
