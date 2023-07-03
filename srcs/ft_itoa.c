/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:29:07 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/24 15:42:44 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lennum(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	i;

	i = n;
	len = lennum(i);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = 48;
	if (i < 0)
	{
		str[0] = '-';
		i = i * -1;
	}
	while (i > 0)
	{
		str[len--] = 48 + (i % 10);
		i = i / 10;
	}
	return (str);
}
/*
#include <stdio.h>
nt main()
{
	int i = 0;
	char *p;
	char outputs[11][12] = {"0","9", "-9", "10", "-10", "8124", 
	"-9874", "543000", "-2147483648","2147483647"};
	long inputs[11] = {0, 9, -9, 10, -10, 8124, -9874, 
	543000, 2147483648LL, 2147483647};
	while (i < 11)
	{
		printf("%d-", strcmp(ft_itoa(inputs[i]), outputs[i]));
		i++;
	}
	
	printf("%d", strcmp(ft_itoa(0), "0"));
//	printf("p: %s\n\n", p);
    return (0);
}*/
