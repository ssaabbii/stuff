#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define int64_t long long
extern int N;
int64_t Sum(int l, int r);
int Query(int l, int64_t s)
{
    if (Sum(l, N) <= s) return N;
    int L = l, R = N;
    while (L < R)
    {
        int middle = R - (R - L) / 2;
        if (Sum(l, middle) > s) R = middle - 1;
        else  L = middle;
    }
    return R;
}