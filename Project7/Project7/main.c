#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define int64_t long long

int Query(int l, int64_t sum);
void Init(const int* arr, int n);
int N;
int arr[100000];
long long pref[100000];

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int l, m;
	int64_t sum;
	scanf("%d %d\n", &n, &m);
	N = n;
	for (int i = 0; i < n; i++)
		scanf("%d\n", &arr[i]);

	Init(arr, n);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %lld\n", &l, &sum);
		printf("%d\n", Query(l, sum));

	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}