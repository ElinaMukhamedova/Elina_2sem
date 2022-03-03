//
//  4.cpp
//  
//
//  Created by Elina Mukhamedova on 03.03.2022.
//

#include <random>
#include <iostream>
#include <fstream>

const int num_dis = 1;

bool reach_border(int y, int dim) {
    if (y == 0 || y == dim - 1)
        return true;
    else
        return false;
}

int main(int argc, char* argv[]) {
    std::ofstream file(argv[2], std::ofstream::out | std::ofstream::app);
    int matr[100][50]={0};
    for (int seed = 1; seed <= 100; seed++) {
        std::mt19937 generator(seed);
        int res[50] = {0};
        
        for (int dim = 1; dim <= 50; dim++) {
            std::uniform_int_distribution<int> distr(1, 2);
            std::uniform_int_distribution<int> dis_locator(0, dim-1);
        
            int lattice[dim];
            memset(lattice, 0, dim*sizeof(int));
            int k = 0;
            while (k < num_dis) {
                int y = dis_locator(generator);
                if (lattice[y] == 0) {
                    lattice[y] = 1;
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
                for (int j = 0; j < dim; j++) {
                    if (lattice[j] == 1) {
                        if (reach_border(j, dim))
                            k--;
                        else {
                            a = distr(generator);
                            lattice[j] = 0;
                            if (a == 1)
                                lattice[j + 1] = 1;
                            if (a == 2)
                                lattice[j - 1] = 1;
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
