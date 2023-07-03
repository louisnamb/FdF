/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:22:03 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/28 16:53:30 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		if (*(unsigned char *)(s + j) == (unsigned char)c)
			return ((void *)(s + j));
		j++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main () {

	//char *src = NULL;
 	int size = 0x20;

 //	if (memchr(NULL, '\0', size) == ft_memchr(NULL, '\0', size))
	printf("%s", ft_memchr(NULL, '\0', size));
 	//else
	 //	printf("incorrect");
	return(0);
}
*/