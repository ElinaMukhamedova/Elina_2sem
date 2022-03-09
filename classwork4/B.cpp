//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 24.02.2022.
//

# include <iostream>

void print_array(int *arr, int n){
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << "\t";
}
void counter_print_array(int *arr, int n){
    for (int i = n - 1; i >= 0; --i)
        std::cout << arr[i] << "\t";
}

int main() {
    int n = 0;
    std::cin >> n;
    int *ptr = nullptr;
    ptr = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> ptr[i];
    for (int i = 0; i < n; ++i)
        std::cout << *(ptr + i) << "\t";
    std::cout << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << *(ptr + n - 1 - i) << "\t";
    delete[] ptr;
    return 0;
}
