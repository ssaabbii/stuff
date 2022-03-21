#include <stdio.h>
#include <assert.h>

int main()
{
#if defined(_MSC_VER) && !defined(__clang__)
	printf("Compiler: MSVC\n");
#elif  defined(__TINYC__)
	printf("Compiler: TCC\n");
#elif  defined(__GNUC__) && !defined(__clang__)
	printf("Compiler: GCC\n");
#elif  defined(__clang__) && !defined(_MSC_VER_) && !defined(__GNUC__)
	printf("Compiler: clang\n");
#endif


#if defined(_WIN64) || defined(__LP64__) || defined(_LP64) || defined(__amd64) || defined (CONFIG_WIN64)
		printf("Bitness: 64\n");
#else 
		printf("Bitness: 32\n");
#endif



#ifdef NDEBUG
	printf("Asserts: disabled\n");
#else 
	printf("Asserts: enabled\n");
#endif
	return 0;
}