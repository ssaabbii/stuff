#include <stdio.h>

int main()
{

#if defined(_MSC_VER) && !defined(__clang__)
	printf("Compiler: MSVC\n");
#elif defined(__TINYC__)
	printf("Compiler: TCC\n");
#elif defined(__GNUC__) && !defined(__clang__)
	printf("Compiler: GCC\n");
#elif defined(__clang__) && !defined(_MSC_VER_) && !defined(__GNUC__)
	printf("Compiler: clang\n");
#endif


#ifdef _WIN64
	printf("Bitness: 64\n");
#else 
	printf("Bitness: 32\n");
#endif


#ifdef _DEBUG
	printf("Asserts: disabled\n");
#else 
	printf("Asserts: enabled\n");
#endif
	return 0;
}
