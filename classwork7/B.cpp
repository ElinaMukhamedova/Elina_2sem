//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 21.03.2022.
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
    
    bool operator< (const Students& other) const {
        if (score < other.score)
            return true;
        else if (score > other.score)
            return false;
        else {
            if (std::strcmp(name, other.name) < 0)
                return true;
            else
                return false;
        }
    }
};

void bubble (Students a[], int n) {
    int i = 1;
    int j = 2;
    Students c = Students("Undefined", -1);
    while (i < n) {
        if (a[i - 1] < a[i]) {
            i = j;
            j++;
        }
        else {
            c = a[i - 1];
            a[i - 1] = a[i];
            a[i] = c;
            i = i - 1;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    Students *group = new Students[n];
    unsigned int t_score = -1;
    for (int i = 0; i < n; ++i) {
        char t_name[20] = "";
        std::cin >> t_name >> t_score;
        *(group + i) = Students(t_name, t_score);
    }
    unsigned int m = -1;
    std::cin >> m;
    bubble(group, n);
    for (int i = 0; i < n; ++i) {
        if ((*(group + i)).score >= m) {
            std::cout << (*(group + i)).name << " ";
        }
    }
    std::cout << std::endl;
    // delete[] t_name;
    delete[] group;
}
