#include <stdio.h>
#include "computepi.h"

int main(int argc, char const *argv[])
{
    __attribute__((unused)) int N = 400000000;
    double pi = 0.0;

#if defined(BASELINE)
    pi = compute_pi_baseline(N);
#endif

#if defined(OPENMP)
    // TODO: Modify here to get better performance, examining the best value by yourself!
    int thread = 2;
    printf("Thread = %d\n", thread);
    pi = compute_pi_openmp(N, thread);
#endif
    printf("N = %d , pi = %lf\n", N, pi);

    return 0;
}
