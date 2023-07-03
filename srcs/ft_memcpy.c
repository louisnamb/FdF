/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:17:28 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 17:08:09 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
/*
int main()
{
    const char src[50] = "http://www.tutorialspoint.com";
    char dest[50];
	strcpy(dest,"Heloooo!!");
    printf("Before memcpy dest = %s\n", dest);
    ft_memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest);
  
    return 0;
}*/
