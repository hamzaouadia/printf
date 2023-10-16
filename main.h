#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
void ft_specifiers(va_list ptr, char c, int *len);
void ft_write(char c, int *len);
void ft_write_string(char *str, int *len);

#endif
