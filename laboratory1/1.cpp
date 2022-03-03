//
//  1.cpp
//  
//
//  Created by Elina Mukhamedova on 17.02.2022.
//

#include <random>
#include <iostream>
#include <fstream>

const int num_dis = 1, dim_1 = 13, dim_2 = 17;

bool reach_border(int x, int y) {
    if (x == 0 || y == 0 || x == dim_1 - 1 || y == dim_2 - 1)
        return true;
    else
        return false;
}

bool neighbours(int lattice[dim_1][dim_2], int x, int y) {
    if (x != 0 && y != 0 && x != dim_1 - 1 || y != dim_2 - 1) {
        if (lattice[x][y - 1] == 1 || lattice[x][y + 1] == 1 || lattice[x - 1][y] == 1 || lattice[x + 1][y] == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}

void show_lattice(int lattice[dim_1][dim_2]) {
    for (int i = 0; i < dim_1; i++) {
        for (int j = 0; j < dim_2; j++)
            std::cout << lattice[i][j] << " ";
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    
    int seed = std::stoi(argv[1]);

    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distr(1, 4);
    std::uniform_int_distribution<int> dis_locator_1(0, dim_1-1);
    std::uniform_int_distribution<int> dis_locator_2(0, dim_2-1);
    
    int lattice[dim_1][dim_2] = {0};
    int k = 0;
    while (k < num_dis) {
        int x = dis_locator_1(generator);
        int y = dis_locator_2(generator);
        if (lattice[x][y] == 0) {
            lattice[x][y] = 1;
            k++;
        }
    }
    show_lattice(lattice);
    
    int time = 0;
    int a = 0;
    std::ofstream file(argv[2]);
    
    while (k > 0) {
        for (int i = 0; i < dim_1; i ++) {
            for (int j = 0; j < dim_2; j++) {
                if (lattice[i][j] == 1) {
                    if (reach_border(i, j) || neighbours(lattice, i, j))
                        k--;
                    else {
                        a = distr(generator);
                        lattice[i][j] = 0;
                        if (a == 1)
                            lattice[i - 1][j] = 1;
                        if (a == 2)
                            lattice[i + 1][j] = 1;
                        if (a == 3)
                            lattice[i][j + 1] = 1;
                        if (a == 4)
                            lattice[i][j - 1] = 1;
                        std::cout << "\n";
                        show_lattice(lattice);
                        std::cout << "\n";
                    }
                }
            }
        }
        time++;
    }
    file << time << std::endl;
    std::cout << time << "\n";
    
    return 0;
}
