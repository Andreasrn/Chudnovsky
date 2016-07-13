/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Andrea
 * 
 * Created on 30 de junio de 2016, 20:23
 */

#include <cstdlib>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

//Tiene un gran problema. No tiene la precisión necesaria, por lo que en adelante probaré con GMP.

int factorial(int n) {
    if (n == 0) return 1;
    if (n != 1)
        return n * factorial(n - 1);
}



/**
 * @brief Calcula una aproximación al número Pi
 * @param k Por cada incremento de k se obtienen 14 decimales, empezando por 0.
 */


long double pi(int k) {

    long double sum = 0;
    long double termino = 0;
    for (int i = 0; i < k + 1; i++) {

        long double dividendo = pow(-1, i) * factorial(6.0 * i) * (13591409.0 + 545140134.0 * i);
        long double divisor = factorial(3 * i) * pow(factorial(i), 3.0) * pow(640320.0, (3.0 * i) + 3.0 / 2);
        long double total = (dividendo / divisor);

        sum += total;
    }

    sum *= 12.0;
    sum = 1 / sum;

    return sum;
}

int main(int argc, char** argv) {
    cout << setprecision(30) << pi(1) << endl;
    return 0;
}

