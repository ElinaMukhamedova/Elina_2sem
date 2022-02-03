//
//  ex4.cpp
//  
//
//  Created by Elina Mukhamedova on 03.02.2022.
//

#include <iostream>
#include <string>
#include <cmath>

int main() {
    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> n >> m;
    if (n >= m){
        a = n;
        b = m;
    }
    else {
        a = m;
        b = n;
    }
    while (a % b != 0){
        c = a - b;
        if (c > b){
            a = c;
        }
        else{
            a = b;
            b = c;
        }
    }
    std::cout << b << std::endl;
    return 0;
}
