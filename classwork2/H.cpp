//
//  H.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main() {
    int n;
    //std::cin >> n;
    //int a = 0;
    //int mult = 1;
    //int inp = -1;
    //for (int i = 1; i <= n; i++) {
    //    std::cin >> inp;
    //    a += mult * inp;
    //    mult *= 10;
    //}
    int a;
    std::cin >> n >> a;
    int copy = a;
    int inp;
    mult = 1;
    int b = 0;
    for (int i = 1; i <= n; i++) {
        inp = copy % 10;
        copy = (copy - inp) / 10;
        b += mult * inp;
        mult *= 10;
    }
    std::cout << b << std::endl;
    return 0;
}
