//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 21.04.2022.
//

#include <iostream>

int ev(int* arr, int n) {
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}

int main() {
    int n = 0;
    std::cin >> n;
    int *arr = nullptr;
    arr = new int[n + 1];
    std::cout << ev(arr, n);
    delete[] arr;
    return 0;
}
