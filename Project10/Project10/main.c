#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
	
	int x = 5;
	assert(x >= 0 && x <= 10000000);
	assert(isPrime(x) == 1);
	x = 10;
	assert(isPrime(x) == 0);
	x = 10000000;
	assert(isPrime(x) == 0);
	x = 1;
	assert(isPrime(x) == 0);
	assert(isPrime(10000000) == 0);
	assert(isPrime(9999999) == 0);
	x = 999983;
	assert(isPrime(x) == 1);
	assert(isPrime(9999991) == 1);
	assert(x <= 10000000);
	x = 2;
	assert(findNextPrime(x) == 2);
	x = 3;
	assert(findNextPrime(x) == 3);
	x = 999979;
	assert(findNextPrime(x) == x);
	x = 999980;
	assert(findNextPrime(x) == 999983);
	assert(findNextPrime(9999991) == 9999991);
	int l, r;
	l = 0; r = 10;
	assert(findNextPrime(10000000) == 10000019);
	assert(getPrimesCount(l, r) == 4);
	l = 995009; r = 995173;
	assert(l >= 0 && l <= 10000000 && l <= r);
	assert(r >= 0 && r <= 10000000 && l <= r);
	assert(getPrimesCount(l, r) == 9);

	l = 1; r = 2;

	assert(getPrimesCount(l, r) == 0);
	l = 0;  r = 1;

	assert(getPrimesCount(l, r) == 0);
	
	assert(x <= 9999991);
	l = 14; r = 17;
	assert(getPrimesCount(l, r) == 0);
	l = 3; r = 3;
	assert(getPrimesCount(l, r) == 0);
	assert(getPrimesCount(100, 100) == 0);
	assert(getPrimesCount(0, 10000000) == 664579 && getPrimesCount(0, 10000000) <= 10000000);
	assert(getPrimesCount(0, 10000000) <= 10000000);
	assert(getPrimesCount(9999999, 10000000) == 0);
	assert(getPrimesCount(10000000, 10000000) == 0 && getPrimesCount(10000000, 10000000) <= 10000000);
	assert(getPrimesCount(9999901, 10000000) == 9);
	assert(getPrimesCount(9999991, 10000000) == 1);
	assert(getPrimesCount(9999991, 9999992) == 1);
	assert(getPrimesCount(9999991, 9999991) == 0);
	return 0;
}