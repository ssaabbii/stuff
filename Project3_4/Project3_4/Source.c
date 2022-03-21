#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>

double f(double* x, double* y, double* z, double t, double l)
{
	double X = (x[0] + x[1] * (t - l) + x[2] * (t - l) * (t - l) + x[3] * (t - l) * (t - l) * (t - l)) * (x[0] + x[1] * (t - l) + x[2] * (t - l) * (t - l) + x[3] * (t - l) * (t - l) * (t - l));
	double Y = (x[0] + x[1] * (t - l) + x[2] * (t - l) * (t - l) + x[3] * (t - l) * (t - l) * (t - l)) * (x[0] + x[1] * (t - l) + x[2] * (t - l) * (t - l) + x[3] * (t - l) * (t - l) * (t - l));
	double Z = (x[0] + x[1] * (t - l) + x[2] * (t - l) * (t - l) + x[3] * (t - l) * (t - l) * (t - l)) * (x[0] + x[1] * (t - l) + x[2] * (t - l) * (t - l) + x[3] * (t - l) * (t - l) * (t - l));
	return sqrt(X + Y + Z);
}


double simpson_integral(double* x, double* y, double* z, double a, double b, int n) {
	const double h = (b - a) / n;
	double k1 = 0, k2 = 0;
	for (int i = 1; i < n; i += 2) {
		k1 += f(x, y, z, (a + i * h), a);
		k2 += f(x, y, z, (a + (i + 1) * h), a);
	}
	return h / 3 * (f(x, y, z, a, a) + 4 * k1 + 2 * k2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double res = 0;
	int n; double a, b, r = 0;
	double x[4], y[4], z[4];
	scanf("%d\n", &n);
	double eps = 0.00000001;
	double s1, s;
	int q = 1; //начальное число шагов
	for (int i = 0; i < n; i++)
	{
		
			scanf("%lf %lf\n", &a, &b);

			scanf("%lf %lf %lf %lf\n", &x[0], &x[1], &x[2], &x[3]);
			scanf("%lf %lf %lf %lf\n", &y[0], &y[1], &y[2], &y[3]);
			scanf("%lf %lf %lf %lf\n", &z[0], &z[1], &z[2], &z[3]);

			s1 = simpson_integral(x, y, z, a, b, q); //первое приближение для интеграла
			do {
				s = s1;     //второе приближение
				q = q * 2;  //увеличение числа шагов в два раза,
							//т.е. уменьшение значения шага в два раза
				s1 = simpson_integral(x, y, z, a, b, q);
			} while (fabs(s1 - s) > eps);
			res += s1;
			s1 = 0; s = 0;

		
		//r += res;
	}
	printf("%0.20g\n", sqrt(res));
	fclose(stdin);
	fclose(stdout);
	return 0;
}