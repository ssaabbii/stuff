#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define int64_t long long

extern int arr[100000], l, r;
extern long long pref[1000001];


void Init(const int* arr, int n)
{
    pref[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        pref[i] = pref[i - 1] + arr[i - 1];
    }

}

int64_t Sum(int l, int r)
{
     return pref[r] - pref[l];
 
}
/*1 1
0 5
4 11
4 12
4 13
10 100
9 0*/