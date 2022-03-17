//
//  heapsort.cpp
//  
//
//  Created by Elina Mukhamedova on 15.03.2022.
//

#include <iostream>

void add(int a[], int n) {
    int i = n;
    int x = a[i];
    while (i > 1  && x > a[i / 2]) {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = x;
}

void remove(int a[], int n) {
    int x = a[1];
    a[1] = a[n];
    a[n] = x;
    int i = 1, j = 2;
    while (j < n - 1) {
        if (a[j + 1] > a[j])
            ++j;
        if (a[i] < a[j]) {
            x = a[i];
            a[i] = a[j];
            a[j] = x;
            i = j;
            j = j * 2;
        }
        else
            break;
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int *ptr = nullptr;
    ptr = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> ptr[i];
    
    int *a = new int[n + 1];
    a[0] = 0;
    for (int i = 1; i < n + 1; ++i)
        a[i] = ptr[i - 1];
    
    for (int i = 2; i < n + 1; ++i)
        add(a, i);
    
    for (int i = 1; i < n + 1; ++i)
        std::cout << *(a + i) << "\t";
    
    std::cout << std::endl;
    
    for (int i = n; i >= 1; --i)
        remove(a, i);
    
    std::cout << std::endl;
    
    for (int i = 1; i < n + 1; ++i)
        std::cout << *(a + i) << "\t";
    delete[] ptr;
    delete[] a;
    return 0;
}
