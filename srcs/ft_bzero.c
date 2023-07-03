/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:37:10 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 15:13:02 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
#include <strings.h>
int main()
{
	unsigned char s[] = "hello";
	int p = 5;
	printf("%s", bzero(s, p));
	printf("%s", ft_bzero(s, p));
	return (0);
}*/
