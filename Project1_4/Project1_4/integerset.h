#pragma once
#include <stdlib.h>

/*#ifdef DYNAMICLIBRARY_EXPORTS
#define IMPORTEXPORT dllexport
#else
#pragma comment(lib, "DynamicLibrary.lib")
#define IMPORTEXPORT dllimport
#endif*/

struct  IntegerSet
{
	int size;
	int* val;
};
typedef struct  IntegerSet  IntegerSet;


IntegerSet* CreateSet(int*, int);


int  IsInSet(IntegerSet*, int);

/*__declspec(IMPORTEXPORT) int multiply(int, int);
__declspec(IMPORTEXPORT)intSet* Create(int, int*);
__declspec(IMPORTEXPORT) int IsConatin(const intSet*, int);*/

