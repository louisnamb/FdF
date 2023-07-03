/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:37:37 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/24 15:43:36 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	charcmp(char c1, char c2)
{
	if ((unsigned char)c1 != (unsigned char)c2)
		return ((unsigned char)c1 - (unsigned char)c2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (charcmp(s1[i], s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
int	ft_print_result(int n)
{
	if (n > 0)
		n = 1;
	else if (n < 0)
		n = -1;
	else
		n = 0;
	return (n);
}

#include <stdio.h>
#include <string.h>
int main()
{
	unsigned char str1[10] = "test\200";
	unsigned char str2[10] = "test\0";
	size_t n = 7;
	if (ft_print_result(ft_strncmp((char *)str1, 
	(char *)str2, n)) == ft_print_result(strncmp((char *)str1, 
	(char *)str2, n)))
		printf("CORRECT) Expected: %d got: %d", 
		strncmp((char *)str1, (char *)str2, n), 
		ft_strncmp((char *)str1, (char *)str2, n));
	else
		printf("INCORRECT) Expected: %d got: %d", 
		strncmp((char *)str1, (char *)str2, n), 
		ft_strncmp((char *)str1, (char *)str2, n));
	
	return (0);
}
*/
