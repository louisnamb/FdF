/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:43:45 by lnambaji          #+#    #+#             */
/*   Updated: 2023/04/11 12:29:05 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	whichspecifier(const char c, va_list var)
{
	int	s;

	s = 0;
	if (c == 'd' || c == 'i')
		s = ft_putnbr_fd((int)va_arg(var, int), 1, s, &s);
	else if (c == 's')
		s = ft_putstr_fd((char *)va_arg(var, char *), 1);
	else if (c == 'c')
		s = ft_putchar_fd((char)va_arg(var, int), 1);
	else if (c == '%')
		s = write(1, &c, 1);
	else if (c == 'x')
		s = ft_convert((unsigned long)va_arg(var, unsigned int), 16, 16, 0);
	else if (c == 'X')
		s = ft_convert((unsigned long)va_arg(var, unsigned int), 16, 0, 0);
	else if (c == 'u')
		s = ft_uputnbr_fd((unsigned int)va_arg(var, unsigned int), 1, s, &s);
	else if (c == 'p')
	{
		s += write(1, "0x", 2);
		s += ft_convert((unsigned long)va_arg(var, unsigned long), 16, 16, 1);
	}
	return (s);
}

int	ft_printf(const char *format, ...)
{
	va_list	input;
	int		sum;

	sum = 0;
	va_start(input, format);
	while (*format)
	{
		if (*format == '%')
		{
			sum += whichspecifier(*(format + 1), input);
			format++;
		}
		else if (*format == 10)
		{
			write(1, "\n", 1);
			sum++;
		}
		else
			sum += write(1, format, 1);
		++format;
	}
	va_end(input);
	return (sum);
}
/*
int	main(void)
{
	long long	num = 5241465;
	int len1, len2;
	void *s = &num;
	len1 = 0;
	len2 = 0;
	len1 = ft_printf("%p");
	ft_printf("\n");
	len2 = printf("%p", s);
	if (len1 == len2)
		printf("\n\033[0;32mCORRECT\033[0m");
	else
		printf("\033[0;31m\nINCORRECT GOT: %d EXP: %d\n\033[0m", len1, len2);
	return 0;
}

Printf KNOWLEDGE:
	- The format parameter is in charge of the string part of the 
	input. i.e., its in charge of the flags and specifiers of the 
	input.
Printf FYI:
	- Have a checker counts the number of times "%" appears in 
	the first arguments string, this will give you an estimate 
	as to the number of variables inputted
*/