//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 21.04.2022.
//

#include <iostream>

int ev(int* arr, int* val, int n) {
    arr[0] = 0;
    arr[1] = val[1];
    arr[2] = val[2];
    arr[3] = val[3];
    int m = 0;
    for (int i = 4; i <= n; ++i) {
        m = std::min(arr[i - 1], std::min(arr[i - 2], arr[i - 3]));
        arr[i] = m + val[i];
    }
    return arr[n];
}

int main() {
    int n = 0;
    std::cin >> n;
    int *arr = nullptr;
    int *val = nullptr;
    arr = new int[n + 1];
    val = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
        std::cin >> val[i];
    }
    std::cout << ev(arr, val, n);
    delete[] arr;
    delete[] val;
    return 0;
}
