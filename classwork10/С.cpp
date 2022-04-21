//
//  С.cpp
//  
//
//  Created by Elina Mukhamedova on 21.04.2022.
//

#include <iostream>

int subseq(int* arr, int* val, int n) {
    arr[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (val[i] > val[i - 1]) {
            arr[i] = arr[i - 1] + 1;
        }
        else {
            arr[i] = arr[i - 1];
        }
    }
    return arr[n - 1];
}

int main() {
    int n = 0;
    std::cin >> n;
    int *arr = nullptr;
    int *val = nullptr;
    arr = new int[n];
    val = new int[n];
    for (int i = 1; i < n; ++i) {
        std::cin >> val[i];
    }
    std::cout << subseq(arr, val, n);
    delete[] arr;
    delete[] val;
    return 0;
}
