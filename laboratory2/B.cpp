//
//  B.cpp
//  
//
//  Created by Elina Mukhamedova on 22.03.2022.
//

#include <iostream>
#include <cmath>
#include <numbers>

float mean(float const psi[], float const pdf[], float m[], float const dv, unsigned size) {
    int step = 2;
    int i = -1;
    while (step < size) {
        i = 0;
        while (i + step / 2 < size) {
            m[i] = m[i] + m[i + step / 2];
            i += step;
        }
        step = step * 2;
    }
    return m[0] * dv;
}

int main() {
    int n = 10000;
    float *psi = new float[n];
    float *pdf = new float[n];
    float *m = new float[n];
    float begin = -1000, end = 1000;
    float dv = (end - begin) / n;
    float v = begin;
    float T = 300; //normal conditions
    for (int i = 0; i < n; i++) {
        v += dv;
        pdf[i] = exp(-(v * v) / T) / sqrt(T * M_PI);
        psi[i] = fabs(v);
        m[i] = pdf[i] * psi[i];
    }
    std::cout << "APPROXIMATION : " << mean(psi, pdf, m, dv, n) << std::endl;
    std::cout << "FORMULA : " << sqrt(T / M_PI) << std::endl;
    delete[] psi;
    delete[] pdf;
    return 0;
}
