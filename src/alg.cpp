// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }

    double dat = 1.0;

    while (n > 0) {
        if (n & 1) {
            dat *= value;
        }

        value *= value;
        n >>= 1;
    }

    return dat;
}

uint64_t fact(uint16_t n) {
    if (n == 0)return 1;
    return fact(n - 1) * n;
}

double calcItem(double x, uint16_t n) {
    double res = x;
    return pown(res, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double dat = 1;
    while (count > 0) {
        dat += calcItem(x, count);
        --count;
    }
    return dat;
}

double sinn(double x, uint16_t count) {
    double result = 0;
    while (count > 0) {
        if(count%2==0)
        result -= calcItem(x, 2*count-1);
        else{
            result += calcItem(x, 2 * count - 1);
        }
        --count;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0;
    while (count > 0) {
        if (count % 2 == 0)
            result -= calcItem(x, 2 * count - 2);
        else {
            result += calcItem(x, 2 * count - 2);
        }
        --count;
    }
    return result;
}
