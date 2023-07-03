/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:01 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/24 16:00:06 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*n_dst;
	const unsigned char	*n_src;

	n_dst = (unsigned char *)dst;
	n_src = (const unsigned char *)src;
	if (n_dst == n_src)
		return (dst);
	if (n_src < n_dst && n_dst < n_src + len)
	{
		n_dst += len;
		n_src += len;
		while (len--)
			*--(n_dst) = *--(n_src);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
int     main(void)
{
	char	*src = "this is a good nyancat !\r\n";
	char	dst1[0xF0]
	char	dst2[0xF0];
	size_t  len = 5;
	int     off = 0;
	printf("src: %s\n", src);
	printf("dst1: %s\n", dst1);
	printf("dst2: %s\n", dst2);
	// Using standard memmove()
	//while ()
	memmove(dst1 + off, src, len);
	printf("dst1 (after std memmove()): %s\n", dst1);
	// Using your implementation of memmove()
	ft_memmove(dst2 + off, src, len);
	printf("dst2 (after ft_memmove()):  %s\n", dst2);
	return (0);
}
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;


	if (dst == src)
		return (dst);
	if (src < dst && dst < src + len)
	{
		i = len;
		while (i-- > 0)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}*/
