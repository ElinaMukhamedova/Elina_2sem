//
//  quicksort.cpp
//  
//
//  Created by Elina Mukhamedova on 15.03.2022.
//

#include <iostream>

int partition(int *A, int n, int lo, int hi) {
    int pivot = -1;
    if ((lo + hi) % 2 == 0)
        pivot = A[(lo + hi) / 2];
    else
        pivot = A[(lo + hi - 1) / 2];
    int i = lo - 1;
    int j = hi + 1;
    while (true) {
        //bool flag = false;
        //if (A[i] <= pivot)
        //    flag = true;
        //while (i < n - 1 && flag) {
        //    ++i;
        //    if (i >= n)
        //        flag = false;
        //    else
        //        if (A[i] > pivot)
        //            flag = false;
        //}
        //flag = false;
        //while (j > 0 && flag) {
        //    --j;
        //    if (j < 0)
        //        flag = false;
        //    else
        //        if (A[j] < pivot)
        //            flag = false;
        //}
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            --j;
        if (i >= j)
            return j;
        int c = A[i];
        A[i] = A[j];
        A[j] = c;
    }
}

void quicksort(int *A, int n, int lo, int hi) {
    if (lo >= 0 && hi >= 0 && lo < hi) {
        int p = partition(A, n, lo, hi);
        quicksort(A, p - lo + 1, lo, p);
        quicksort(A, hi - p, p + 1, hi);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int *ptr = nullptr;
    ptr = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> ptr[i];
    quicksort(ptr, n, 0, n - 1);
    for (int i = 0; i < n; ++i)
        std::cout << *(ptr + i) << "\t";
    delete[] ptr;
    return 0;
}
