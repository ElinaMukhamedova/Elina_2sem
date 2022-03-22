//
//  C.cpp
//  
//
//  Created by Elina Mukhamedova on 22.03.2022.
//

#include <iostream>
#include <cmath>
#include <numbers>

float mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.0;
    float c = 0.0;
    float y = 0.0;
    float t = 0.0;
    for (int i = 0; i < size; ++i) {
        y = psi[i] * pdf[i] * dv - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
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
        psi[i] = fabs(v);
    }
    std::cout << "APPROXIMATION : " << mean(psi, pdf, dv, n) << std::endl;
    std::cout << "FORMULA : " << sqrt(T / M_PI) << std::endl;
    delete[] psi;
    delete[] pdf;
    return 0;
}
