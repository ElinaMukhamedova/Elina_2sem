//
//  3.cpp
//  
//
//  Created by Elina Mukhamedova on 27.02.2022.
//

#include <random>
#include <iostream>
#include <fstream>

const int dim = 19;

bool reach_border(int x, int y) {
    if (x == 0 || y == 0 || x == dim - 1 || y == dim - 1)
        return true;
    else
        return false;
}

bool neighbours(int lattice[dim][dim], int x, int y) {
    if (x != 0 && y != 0 && x != dim - 1 || y != dim - 1) {
        if (lattice[x][y - 1] == 1 || lattice[x][y + 1] == 1 || lattice[x - 1][y] == 1 || lattice[x + 1][y] == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}

void show_lattice(int lattice[dim][dim]) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            std::cout << lattice[i][j] << " ";
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::ofstream file(argv[2], std::ofstream::out | std::ofstream::app);
    file << dim << "⨉" << dim << "\n";
    float ratio[dim * dim] = {0};
    int matr[100][dim * dim] = {0};
    int time = 0;
    int a = 0;
    for (int k = 1; k <= dim * dim; k++){
        ratio[k - 1] = k / (dim * dim);
        for (int seed = 1; seed <= 100; seed++) {
            std::mt19937 generator(seed);
            std::uniform_int_distribution<int> distr(1, 4);
            std::uniform_int_distribution<int> dis_locator(0, dim-1);
            int lattice[dim][dim] = {0};
            int counter = 0;
            while (counter < k) {
                int x = dis_locator(generator);
                int y = dis_locator(generator);
                if (lattice[x][y] == 0) {
                    lattice[x][y] = 1;
                    counter++;
                }
            }
            time = 0;
            while (counter > 0) {
                int mirror[dim][dim] = {};
                for (int i = 0; i < dim; i ++) {
                    for (int j = 0; j < dim; j++) {
                        if (lattice[i][j] == 1) {
                            if (reach_border(i, j) || neighbours(lattice, i, j))
                                counter--;
                            else {
                                a = distr(generator);
                                if (a == 1) {
                                    if (mirror[i - 1][j] == 0) {
                                        mirror[i - 1][j] = 1;
                                        lattice[i - 1][j] = 1;
                                        lattice[i][j] = 0;
                                    }
                                }
                                if (a == 2) {
                                    if (mirror[i + 1][j] == 0) {
                                        mirror[i + 1][j] = 1;
                                        lattice[i + 1][j] = 1;
                                        lattice[i][j] = 0;
                                    }
                                }
                                if (a == 3) {
                                    if (mirror[i][j + 1] == 0) {
                                        mirror[i][j + 1] = 1;
                                        lattice[i][j + 1] = 1;
                                        lattice[i][j] = 0;
                                    }
                                }
                                if (a == 4) {
                                    if (mirror[i][j - 1] == 0) {
                                        mirror[i][j - 1] = 1;
                                        lattice[i][j - 1] = 1;
                                        lattice[i][j] = 0;
                                    }
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
        for (int j = 0; j < dim * dim; j++) {
            file << matr[i][j] << "," << " ";
        }
        file << "\n";
    }
    file << "\n";
    //for (int i = 0; i < dim * dim; i++)
    //    file << ratio[i] << "," << " ";
    float res[dim * dim] = {0};
    float s = 0;
    for (int j = 0; j < dim * dim; j++) {
        s = 0;
        for (int i = 0; i < 100; i++)
            s += matr[i][j];
        res[j] = s / 100;
    }
    file << "\n";
    for (int i = 0; i < dim * dim; i++)
        file << res[i] << "," << " ";
    file.close();
    return 0;
}
