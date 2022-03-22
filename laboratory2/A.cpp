//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 22.03.2022.
//

#include <iostream>
#include <cmath>
#include <numbers>

float mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    if (size == 1)
        return psi[0] * pdf[0] * dv;
    else
        return mean(psi, pdf, dv, size / 2) + mean(&(psi[size / 2]), &(pdf[size / 2]), dv, size / 2);
}

int main() {
    int n = 10000;
    float *psi = new float[n];
    float *pdf = new float[n];
    float begin = -1000, end = 1000;
    float dv = (end - begin) / n;
    float v = begin;
    float T = 300; //normal conditions
    for (int i = 0; i < n; i++) {
        v += dv;
        pdf[i] = exp(-(v * v) / T) / sqrt(T * M_PI);
        psi[i] = sqrt(v * v);
    }
    std::cout << "APPROXIMATION : " << mean(psi, pdf, dv, n) << std::endl;
    std::cout << "FORMULA : " << sqrt(T / M_PI) << std::endl;
    delete[] psi;
    delete[] pdf;
    return 0;
}
