/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexchars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:18:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/25 14:27:51 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned int	ft_uputnbr_fd(unsigned int n, int fd, int total, int *sum)
{
	if (n < 0)
	{
		total += ft_putchar_fd('-', fd);
		ft_uputnbr_fd(-n, fd, total, sum);
	}
	else if (n >= 10)
	{
		total++;
		ft_uputnbr_fd(n / 10, fd, total, sum);
		total += ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		*sum = total;
		total += ft_putchar_fd(n + '0', fd);
	}
	return (*sum + 1);
}

int	ft_hputstr(char *s, int fd, int length, int ptr)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	(void)ptr;
	if (!s)
		return (0);
	while (length >= 1)
	{
		sum += write(fd, &s[length - 1], 1);
		length--;
	}
	return (sum);
}

int	ft_hexlen(unsigned long long int num, int base)
{
	int	length;
	int	add;

	length = 0;
	add = 0;
	while (num != 0)
	{
		num /= base;
		length++;
	}
	return (length);
}

char	*ptrmkr(char *ptr, unsigned long long num)
{
	char	*dummy_ptr;

	dummy_ptr = ptr;
	dummy_ptr[0] = 48;
	dummy_ptr[1] = 120;
	if (num == 0)
		dummy_ptr[2] = '0';
	return (ptr);
}

int	ft_convert(unsigned long long num, int base, int low, int ptr)
{
	char			*uphexi;
	char			*p_str;
	unsigned long	dummy;
	int				sum;
	int				i;

	sum = 0;
	dummy = num;
	i = 0;
	uphexi = "0123456789ABCDEF0123456789abcdef";
	p_str = malloc(sizeof(char) * (ft_hexlen(num, base) + 2));
	if (!p_str)
		return (0);
	if (num == 0)
		ptrmkr(p_str, num);
	i += (num == 0 && p_str[2] == 48);
	while (dummy != 0)
	{
		p_str[i++] = uphexi[(dummy % base) + low];
		dummy /= base;
	}
	p_str[i] = 0;
	sum += ft_hputstr(p_str, 1, i, ptr);
	free(p_str);
	return (sum);
}
