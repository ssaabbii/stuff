#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double h = 0.0001;

double F(double *x)
{
	return pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2);
}

double dF1(double *x, int n)
{
	int n = n;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			if (j == i)
			{
				temp[j] = x[j] + h;
				temp2[j] = x[j] - h;
			}
			else
			{
				temp[j] = x[j];
				temp2[j] = x[j];
			}
		}
		j = 0;
		res[i] = (F(temp) - F(temp2)) / (2 * h);
	}
	return res;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d\n", &n);

	fclose(stdin);
	fclose(stdout);
	return 0;
}