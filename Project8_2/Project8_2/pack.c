#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "pack.h"
#include <stdarg.h>
#include <string.h>
#include "stdio.h"

int pack(char* buffer, const char* format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    int len = 0;
    int flag = (buffer != NULL);
    for (int i = 0; i < strlen(format); i++) 
    {
        if (format[i] == '%')
            continue;
        if (format[i] == 's')
        {
            char* s = va_arg(argptr, char*);
            int size = strlen(s);
            if (flag)
                strcpy(&buffer[len], s);
            len += (size + 1);
        }
        if (format[i] == 'd')
        {
            int d = va_arg(argptr, int);
            if (flag) 
            {
                for (int i = 0; i < 4; i++)
                {
                    buffer[len + i] = ((char*)&d)[i];
                }
            }
            len += 4;
        }
        if (format[i] == 'l')
        {
            i++;
            double a = va_arg(argptr, double);
            if (flag) 
            {
                for (int i = 0; i < 8; i++)
                {
                    buffer[len + i] = ((char*)&a)[i];
                }
            }
            len += 8;
        }
    }
    return len;
}