#include "integerset.h"
#include <stdlib.h>
IntegerSet* CreateSet(int* arr, int n)
{
	
	IntegerSet* result = (IntegerSet*)malloc((n*2)*sizeof(IntegerSet));
	result->size = n;
	//TODO
	int c = 0;
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] == arr[j])
				c++;
		}
			
	}
	for (int i = 0; i < n; i++)
	{
		result[i].val = arr[i];
		
	}
	if (c == 0)
		return result;
	else
	{
		result = 0;
		return 0;
	}
		


}

int  IsInSet(IntegerSet* set, int x)
{
	if (set == 0)
		return 0;
	else
	{

		int c = 0;

		for (int i = 0; i < set->size; i++)
		{
			if (x == set[i].val)
			{
				c++;
			}

		}

		if (c != 0)
			return 1;
		else
			return 0;
	}

	

}
