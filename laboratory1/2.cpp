//
//  2.cpp
//  
//
//  Created by Elina Mukhamedova on 24.02.2022.
//

#include <random>
#include <iostream>
#include <fstream>

const int num_dis = 1;

bool reach_border(int x, int y, int dim_1, int dim_2) {
    if (x == 0 || y == 0 || x == dim_1 - 1 || y == dim_2 - 1)
        return true;
    else
        return false;
}

//bool neighbours(int lattice[dim_1][dim_2], int x, int y) {
//    if (x != 0 && y != 0 && x != dim_1 - 1 || y != dim_2 - 1) {
//        if (lattice[x][y - 1] == 1 || lattice[x][y + 1] == 1 || lattice[x - 1][y] == 1 || lattice[x + 1][y] == 1)
//            return true;
//        else
//            return false;
//    }
//    else
//        return false;
//}

//void show_lattice(int lattice[dim_1][dim_2]) {
//    for (int i = 0; i < dim_1; i++) {
//        for (int j = 0; j < dim_2; j++)
//            std::cout << lattice[i][j] << " ";
//        std::cout << "\n";
//    }
//}

int main(int argc, char* argv[]) {
    std::ofstream file(argv[2], std::ofstream::out | std::ofstream::app);
    int matr[100][50]={0};
    for (int seed = 1; seed <= 100; seed++) {
        std::mt19937 generator(seed);
        int res[50] = {0};
        
        for (int dim = 1; dim <= 50; dim++) {
            std::uniform_int_distribution<int> distr(1, 4);
            std::uniform_int_distribution<int> dis_locator(0, dim-1);
        
            int lattice[dim][dim];
            memset(lattice, 0, dim*dim*sizeof(int));
            int k = 0;
            while (k < num_dis) {
                int x = dis_locator(generator);
                int y = dis_locator(generator);
                if (lattice[x][y] == 0) {
                    lattice[x][y] = 1;
                    k++;
                }
            }
            //std::cout << "\n";
            //for (int i = 0; i < dim; i++) {
            //    for (int j = 0; j < dim; j++)
            //        std::cout << lattice[i][j] << " ";
            //    std::cout << "\n";
            //}
            //std::cout << "\n";
        
            int time = 0;
            int a = 0;
        
            while (k > 0) {
                for (int i = 0; i < dim; i ++) {
                    for (int j = 0; j < dim; j++) {
                        if (lattice[i][j] == 1) {
                            if (reach_border(i, j, dim, dim) || lattice[i][j - 1] == 1 || lattice[i][j + 1] == 1 || lattice[i - 1][j] == 1 ||lattice[i  + 1][j] == 1)
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
                            }
                        }
                    }
                }
                time++;
            }
            //for (int i = 0; i < dim; i++) {
            //    for (int j = 0; j < dim; j++)
            //        std::cout << lattice[i][j] << " ";
            //    std::cout << "\n";
            //}
            //std::cout << "\n";
            //std::cout << dim * dim << " " << time << "\n";
            res[dim - 1] = time;
            matr[seed - 1][dim - 1] = time;
            file << time << "," << " ";
        }
    file << std::endl;
    }
    float graph[50] = {0};
    for (int j = 0; j < 50; j++) {
        float s = 0;
        for (int i = 0; i < 100; i++) {
            s += matr[i][j];
        }
        s = s / 100;
        graph[j] = s;
    }
    file << "\n";
    for (int i = 0; i < 50; i++)
        file << graph[i] << "," << " ";
    file.close();
    return 0;
}
