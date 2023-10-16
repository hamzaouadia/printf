#include "main.h"

/**
 *	ft_write_string - function that print a string
 *	@str: string.
 *	@len: integer.
 *	Return: nothing.
*/

void ft_write_string(char *str, int *len)
{
	while (*str)
	{
		write(1, &*str, 1);
		*len += 1;
		str++;
	}
}

/**
 *	ft_write - function that print a charachter
 *	@c: character.
 *	@len: integer.
 *	Return: nothing.
*/

void ft_write(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

/**
 *	ft_specifiers - function that check the specifiers.
 *	@ptr: a struct.
 *	@c: character.
 *	@len: integer.
 *	Return: nothing.
*/

void ft_specifiers(va_list ptr, char c, int *len)
{
	if (c == 'c')
		ft_write(va_arg(ptr, int), len);
	else if (c == 's')
		ft_write_string(va_arg(ptr, char *), len);
	else
		ft_write(c, len);
}

/**
 *	_printf - function that produces output according to a format.
 *	@format: a character string.
 *	Return: the number of characters printed. 
*/

int _printf(const char *format, ...)
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format != '%')
			ft_write(*format, &len);
		else
		{
			if (*format + 1 == '\0')
				break;
			ft_specifiers(ptr, *format + 1, &len);
			format++;
		}
		format++;
	}
	va_end(ptr);
	return (len);
}
