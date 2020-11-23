#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#define mul_mod(a,b,m) fmod( (double) a * (double) b, m)

namespace Fabrice_PI{
    int get_pi_digits(int n);
    int inv_mod(int x, int y);
    int pow_mod(int a, int b, int m);
    int is_prime(int n);
    int next_prime(int n);
    inline int mul_mod(int a, int b, int m);
};
