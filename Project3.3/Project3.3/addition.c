#include "functions.h"

numType *add(numType *addend1, numType *addend2)
{
	/*Initialize result structure*/
	numType *result = NULL;
	int max_len = (addend1->digits>addend2->digits)?(addend1->digits+1):(addend2->digits+1);
	result = malloc(sizeof(numType));
	check_ptr(result);
	result->digits = max_len;		//Store the max number of the sum's digits
	result->sign = 1;	//Default sign
	result->number = NULL;
	result->number = calloc(max_len, sizeof(char));
	check_ptr(result->number);
	//Done initialization

	//Consider different cases of the two number
	if (addend1->sign == -1 && addend2->sign == -1)
		result->sign = -1;	//Only decide the sign and make the normal addition later
	else if (addend1->sign == 1 && addend2->sign == -1)
	{
		addend2->sign = 1;
		return substract(addend1, addend2);
	} else if (addend1->sign == -1 && addend2->sign == 1)
	{
		addend1->sign = 1;
		return substract(addend2, addend1);
	}

	int i, j, k, carry_up = 0;	//Indices for addend 1, addend 2 and the sum with the "carry" variable
	k = -1; while(k++ < max_len) result->number[k] = 0;
	i = addend1->digits - 1; j = addend2->digits - 1; k = max_len - 1;

	for (; k >= 0; i--, j--, k--)	//Sum each pair of digits from right to left
	{
		result->number[k] += carry_up; //Do the carry phase

		if (i < 0 && j >= 0)		//When only addend2's digits are left
			result->number[k] += addend2->number[j];
		else if (j < 0 && i >= 0)	//When only addend1's digits are left
			result->number[k] += addend1->number[i];
		else if (i >= 0 && j >= 0)	//When both digits are left
			result->number[k] += addend1->number[i] + addend2->number[j];
		else		//Addition done
			break;

		carry_up = result->number[k] / 10;	//Make "carry" variable
		result->number[k] %= 10;			//Store only last digit of the calculated sum
	}

	//Remove redundant 0s at the left of the sum
	while (result->number[0] == 0)
	{
		result->number++;
		result->digits--;
	}

	return result;
}

#include<stdio.h>
#include <math.h>

double f(double c0, double c1, double c2, double c3, double t, double l) {
	return (c0 + c1 * (t - l) + c2 * ((t - l) * (t - l)) + c3 * ((t - l) * (t - l) * (t - l)));
}



int main()
{
	double res = 0;
	int n; double a, b, c0, c1, c2, c3, x, integral, sum = 0;;
	scanf("%d\n", &n);
	double eps = 0.000001;
	double s1, s;
	int q = 1; //начальное число шагов
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf\n", &a, &b);
		double h = (b - a) / n;
		for (int k = 0; k < 3; k++)
		{
			scanf("%lf %lf %lf %lf\n", &c0, &c1, &c2, &c3);
			x = a + (i + 1) * h;
			if (i % 2 == 0)
			{
				sum = sum + 2 * f(x);
			}
			else sum = sum + 4 * f(x);
		}
		integral = h / 3.0 * (f(a) + sum + f(b));
	}
	printf("%0.20g\n", res);
}
#include<stdio.h>
#include <math.h>

double f(double c0, double c1, double c2, double c3, double t, double l) {
	return (c0 + c1 * (t - l) + c2 * ((t - l) * (t - l)) + c3 * ((t - l) * (t - l) * (t - l)));
}

double simpson_integral(double c0, double c1, double c2, double c3, double a, double b, int n) {
	const double h = (b - a) / n;
	double k1 = 0, k2 = 0;
	for (int i = 1; i < n; i += 2) {
		k1 += f(c0, c1, c2, c3, (a + i * h), a);
		k2 += f(c0, c1, c2, c3, (a + (i + 1) * h), a);
	}
	return h / 3 * (f(c0, c1, c2, c3, a, a) + 4 * k1 + 2 * k2);
}

int main()
{
	double res = 0;
	int n; double a, b, c0, c1, c2, c3, r = 0;
	scanf("%d\n", &n);
	double eps = 0.000001;
	double s1, s;
	int q = 1; //начальное число шагов
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf\n", &a, &b);

		for (int k = 0; k < 3; k++)
		{
			scanf("%lf %lf %lf %lf\n", &c0, &c1, &c2, &c3);
			//double f = f(c[4], )
			s1 = simpson_integral(c0, c1, c2, c3, a, b, q); //первое приближение для интеграла
			do {
				s = s1;     //второе приближение
				q = q * 2;  //увеличение числа шагов в два раза,
							//т.е. уменьшение значения шага в два раза
				s1 = simpson_integral(c0, c1, c2, c3, a, b, q);
			}             while (fabs(s1 - s) > eps);
			res += s1;
			s1 = 0; s = 0;
		}

		r += res;
	}
	printf("%0.20g\n", r);
}