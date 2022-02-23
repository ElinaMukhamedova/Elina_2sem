//
//  1.cpp
//  
//
//  Created by Elina Mukhamedova on 17.02.2022.
//

# include <random>
# include <iostream>

const int num_dis = 7, dim_1 = 13, dim_2 = 17;

bool reach_border(int x, int y) {
    if (x == 0 || y == 0 || x == dim_1 - 1 || y == dim_2 - 1)
        return true;
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
    return 0;
}
