#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>

int main() {
	//FILE* input = fopen("input.txt", "r");
	//FILE* output = fopen("output.txt", "w");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	size_t N, M;
	scanf("%u %u", &N, &M);
	std::vector < std::vector<size_t> > E(N);	//size_t** E
	size_t* Ein = (size_t*)malloc(N * sizeof(size_t));
	size_t* result = (size_t*)malloc(N * sizeof(size_t));
	size_t nextIndex = 1;

	for (size_t i = 0; i < N; ++i)
	{
		Ein[i] = 0;
	}
	for (size_t i = 0; i < M; ++i)
	{
		size_t a, b;
		scanf("%u %u", &a, &b);	//a<b
		E[a].push_back(b);
		Ein[b] += 1;
	}


	std::queue<size_t> Q;

	for (size_t i = 0; i < N; i++)
	{
		if (Ein[i] == 0)
		{
			Q.push(i);
		}
	}
	while (!Q.empty())	//O(N)
	{
		size_t i;
		i = Q.front();
		Q.pop();
		result[i] = nextIndex;
		nextIndex += 1;
		for (size_t j = 0; j < E[i].size(); j++)	//O(E[i])
		{
			size_t b = E[i][j];
			Ein[b] -= 1;
			if (Ein[b] == 0)
			{
				Q.push(b);
			}
		}
	}	//O(N + M)
	if (nextIndex == N + 1)
	{
		printf("YES\n");
		for (size_t i = 0; i < N; ++i)
		{
			printf("%u %u\n", i, result[i]);
		}
	}
	else
	{
		printf("NO\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}