//
//  5.cpp
//  
//
//  Created by Elina Mukhamedova on 03.03.2022.
//

#include <random>
#include <iostream>
#include <fstream>

const int dim = 500;

bool reach_border(int x) {
    if (x == 0 || x == dim - 1)
        return true;
    else
        return false;
}

bool neighbours(int lattice[dim], int x) {
    if (x != 0 && x != dim - 1) {
        if (lattice[x - 1] == 1 || lattice[x + 1] == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}

void show_lattice(int lattice[dim]) {
    for (int i = 0; i < dim; i++)
        std::cout << lattice[i] << " ";
    std::cout << "\n";
}

int main(int argc, char* argv[]) {
    std::ofstream file(argv[2], std::ofstream::out | std::ofstream::app);
    file << 1 << "⨉" << dim << "\n";
    float ratio[dim] = {0};
    int matr[100][dim] = {0};
    int time = 0;
    int a = 0;
    for (int k = 1; k <= dim; k++){
        ratio[k - 1] = k / dim;
        for (int seed = 1; seed <= 100; seed++) {
            std::mt19937 generator(seed);
            std::uniform_int_distribution<int> distr(1, 2);
            std::uniform_int_distribution<int> dis_locator(0, dim-1);
            int lattice[dim] = {0};
            int counter = 0;
            while (counter < k) {
                int x = dis_locator(generator);
                if (lattice[x] == 0) {
                    lattice[x] = 1;
                    counter++;
                }
            }
            time = 0;
            while (counter > 0) {
                int mirror[dim] = {0};
                for (int i = 0; i < dim; i++) {
                    if (lattice[i] == 1) {
                        if (reach_border(i) || neighbours(lattice, i))
                            counter--;
                        else {
                            a = distr(generator);
                            if (a == 1) {
                                if (mirror[i - 1] == 0) {
                                    mirror[i - 1] = 1;
                                    lattice[i - 1] = 1;
                                    lattice[i] = 0;
                                }
                            }
                            if (a == 2) {
                                if (mirror[i + 1] == 0) {
                                    mirror[i + 1]= 1;
                                    lattice[i + 1] = 1;
                                    lattice[i] = 0;
                                }
                            }
                        }
                    }
                }
                time++;
            }
            matr[seed - 1][k - 1] = time;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < dim; j++) {
            file << matr[i][j] << "," << " ";
        }
        file << "\n";
    }
    file << "\n";
    //for (int i = 0; i < dim * dim; i++)
    //    file << ratio[i] << "," << " ";
    float res[dim] = {0};
    float s = 0;
    for (int j = 0; j < dim; j++) {
        s = 0;
        for (int i = 0; i < 100; i++)
            s += matr[i][j];
        res[j] = s / 100;
    }
    file << "\n";
    for (int i = 0; i < dim; i++)
        file << res[i] << "," << " ";
    file.close();
    return 0;
}
