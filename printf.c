#include "main.h"

/**
 *	ft_write_string - function that print a string
 *	@str: string.
 *	@len: integer.
 *	Return: nothing.
*/

void ft_write_string(char *str, int *len)
{
	if (!str)
	{
		ft_write_string("(null)", len);
		return;
	}
	while (*str)
	{
		write(1, &*str, 1);
		(*len)++;
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
	(*len)++;
}

/**
 *	ft_putnbr - function that print an integer
 *	@nbr: integer.
 *	@len: integer.
 *	Return: nothing.
*/

void ft_putnbr(int nbr, int *len)
{
	long long int n = nbr;

	if (n < 0)
	{
		ft_write('-', len);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_write(n + '0', len);
}

/**
 *	ft_specifiers - function that check the specifiers.
 *	@ptr: a struct.
 *	@str: string of characters.
 *	@len: integer.
 *	Return: nothing.
*/

void ft_specifiers(va_list ptr, char *str, int *len)
{
	if (*(str + 1) == 'c')
		ft_write(va_arg(ptr, int), len);
	else if (*(str + 1) == 's')
		ft_write_string(va_arg(ptr, char *), len);
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		ft_putnbr(va_arg(ptr, int), len);
	else if (*(str + 1) == '%')
		ft_write('%', len);
	else
	{
		ft_write(*str, len);
		ft_write(*(str + 1), len);
	}
}

/**
 *	_printf - function that produces output according to a format.
 *	@format: a character string.
 *	Return: the number of characters printed.
*/

int _printf(const char *format, ...)
{
	int len = 0;
	int i = 0;
	va_list ptr;

	va_start(ptr, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			ft_write(format[i], &len);
		else if (format[i] == '%')
		{
			if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
					i++;
			}
			if (format[i + 1] == '\0')
				return (-1);
			ft_specifiers(ptr, (char *)format + i, &len);
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
