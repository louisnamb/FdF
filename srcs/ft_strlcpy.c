/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:06:21 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/24 15:45:39 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dst++ = *src++;
		++i;
	}
	if (i < size)
		*dst = 0;
	while (*src++)
		++i;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
 	char *str = "helloworld !";
 	char buff2[0xF00];
	printf("%zu", ft_strlcpy(buff2, str, 1));
	printf("\n%zu", strlcpy(buff2, str, 1));
	return (0);
}*/
