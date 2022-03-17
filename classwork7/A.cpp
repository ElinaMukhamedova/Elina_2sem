//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 17.03.2022.
//

#include <iostream>

struct Students {
    char name[20];
    unsigned int score;
    
    Students() {
        strcpy(name, "Undefined");
        score = -1;
    }

    Students(const char *t_name, unsigned int t_score) {
        strcpy(name, t_name);
        // for(int i = 0; *(t_name + i) != '\0'; ++i) {
        //     name[i] = *(t_name + i);
        // }
        score = t_score;
    }
};

int main() {
    Students *group = new Students[10];
    unsigned int t_score = -1;
    for (int i = 0; i < 10; ++i) {
        char t_name[20] = "";
        std::cin >> t_name >> t_score;
        *(group + i) = Students(t_name, t_score);
    }
    unsigned int m = -1;
    std::cin >> m;
    for (int i = 0; i < 10; ++i) {
        if ((*(group + i)).score >= m) {
            std::cout << (*(group + i)).name << std::endl;
        }
    }
    // delete[] t_name;
    delete[] group;
}
