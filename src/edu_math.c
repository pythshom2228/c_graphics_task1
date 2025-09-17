#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
    return a + b;
}

int edu_sub(int a, int b) {
    return a - b;
}

int edu_mult(int a, int b) {
    return a * b;
}

int edu_div(int a, int b) {
    return a / b;
}

int edu_mod(int a, int b) {
    return a % b;
}

int edu_pow(int a, int b) {
    if(b == 0) return 1;
    return a * edu_pow(a,b-1);
}

int edu_abs(int a) {
    if(a < 0) {
        return -a;
    }
    return a;
}

int edu_gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    a = abs(a);
    b = abs(b);
    int res = 1;
    int m = res;
    int k;
    if(a <= b) k = a;
    else k = b;

    while(res <= k) {
        if(a % res == 0 && b % res == 0) {
            m = res;
        }
        res++;
    }
    return m;
}

int edu_lcm(int a, int b) {
    if(a == 0 || b == 0) return 0;
    int k;
    if(a >= b) k = a * 2;
    else k = b * 2;

    while(!(k % a == 0 && k % b == 0)) k++;
    return k;
}

int edu_int_sqrt(int a) {
    if(a == 0) return 0;
    if(a == 1) return 1;
    if(a < 0) return -1;

    int left = 1, right = a;

    while(left <= right) {
        int m = left + (right - left)/2;
        if(m*m == a)
            return m;
        else if(m*m < a) 
            left = m + 1;
        else 
            right = m - 1;
    }
    return right;
}

int edu_sgn(int a) {
    if(a > 0) return 1;
    if(a < 0) return -1;
    return 0;
}

int edu_fact(int a) {
    if(a == 0) return 1;
    return a * edu_fact(a-1);
}
