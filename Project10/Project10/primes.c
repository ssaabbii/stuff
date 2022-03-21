#include "primes.h"
#include<stdio.h>
#include<assert.h>

static int B[10000001];
static char initBoolean = 0;
static int sum[10000001];
static void Eratosthenes()
{
	int i, P;
	for (P = 2; P <= 10000000; P++) B[P] = 1;
	P = 2;
	while (P * P <= 10000000)
	{
		i = P * P;
		if (B[P])
			while (i <= 10000000)
			{
				B[i] = 0;
				i = i + P;
			}
		P = P + 1;
	}
	sum[0] = 0;
	for (int i = 1; i <= 10000000; i++) {
		
		sum[i] = sum[i - 1] +B[i-1];
	}
	B[0] = B[1] = 0;
}
#define EratosthenesInit() if (!initBoolean) { Eratosthenes(); initBoolean = 1; }

int isPrime(int x)
{
	EratosthenesInit();
	//assert(x <= 10000000);
	
	if (B[x] == 1)
		return 1;
	else
		return 0;
	//if (x < 2) return 0;
	//else if (x == 2) return 1;
	//else if (x % 2 == 0) return 0;
	//else return B[x];
}


//returns minimal prime number p such that p >= x
int findNextPrime(int x)
{
	//assert(x <= 10000000);
	EratosthenesInit();
	if (x > 9999991)
		return 10000019;
	else
	{
		for (int i = x; i <= 10000000; i++)
		{

			if (B[i] == 1)
			{
				return i;
				return 0;
			}

		}
	}
	return 0;
}

//returns the number of primes x such that l <= x < r
int getPrimesCount(int l, int r)
{
	//assert(l <= 10000000 && r <= 10000000 && l <= r);
	EratosthenesInit();
	int c;
	c = sum[r] - sum[l];
	
	//assert(c <= 10000000);
	return c;
	
}