#define _CRT_SECURE_NO_WARNINGS
#include "func.h" 
#include<stdio.h>
#include<stdlib.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m; double x;
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lf\n", &x);
		double eps = 1E-8;
		double result;
		if (eps < x && x < 1 - eps)
			result = ((Function(x + eps) - Function(x - eps)) / 2) / eps;
		else if (eps >= x)
			result = (Function(x + eps) - Function(x)) / eps;
		else if (x >= 1 - eps)
			result = (Function(x) - Function(x - eps)) / eps;
		printf("%.15f\n", result);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}