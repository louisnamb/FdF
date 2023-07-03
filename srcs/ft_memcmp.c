/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:44:35 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 15:37:30 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem_s1;
	unsigned char	*mem_s2;
	size_t			i;

	mem_s1 = (unsigned char *)s1;
	mem_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (mem_s1[i] != mem_s2[i])
			return (mem_s1[i] - mem_s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char *arr = "louis";
    char *ok = "rsffr";
    int i = 4;
    printf("%d\n", memcmp(arr, ok, i));
    printf("%d\n", ft_memcmp(arr, ok, i));

    return (0);
}*/
