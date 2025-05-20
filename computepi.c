#include "computepi.h"
#include <math.h>
#include <omp.h>
#include <stdio.h>

double compute_pi_baseline(size_t N)
{
    double pi = 0.0;
    double dt = 1.0 / N;  // dt = (b-a)/N, b = 1, a = 0
    for (size_t i = 0; i < N; i++) {
        double x = (double) i / N;  // x = ti = a+(b-a)*i/N = i/N
        pi += dt / (1.0 + x * x);   // integrate 1/(1+x^2), i = 0....N
    }
    return pi * 4.0;
}

double compute_pi_openmp(size_t N, int threads)
{
    double pi = 0.0;
    double dt = 1.0 / N;
    double x;
// TODO: Add OpenMP stuff here to create a parallel environment
    {
// TODO: Add proper OpenMP for the parameter to speed up the for iteration and prevent data racing
        for (size_t i = 0; i < N; i++) {
            x = (double) i / N;
            pi += dt / (1.0 + x * x);
        }
    }
    return pi * 4.0;
}
