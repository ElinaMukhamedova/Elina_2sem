//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 10.02.2022.
//

#include <iostream>

int main(){
    int x;
    int k = 0;
    while (std::cin >> x) {
        if (x == 0)
            break;
        else if (x % 2 == 0)
            k++;
    }
    std::cout << k << std::endl;
    return 0;
}
