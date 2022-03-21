#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <cmath>


int main()
{
	int n = 10000000;
	double* arr = (double*)malloc(sizeof(double) * n);
	double sum = 0;


	for (int i = 0; i < n; i++) {
		arr[i] = sin(i * 2 * M_PI / (double)n);
	}

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	printf("%lf\n", sum);

	return 0;
}