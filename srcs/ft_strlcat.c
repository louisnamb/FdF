/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:28:30 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 17:53:13 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_sz;
	size_t	src_sz;
	size_t	i;

	i = 0;
	dst_sz = ft_strlen(dst);
	src_sz = ft_strlen(src);
	if (size <= dst_sz)
		return (src_sz + size);
	while (src[i] && i < (size - dst_sz - 1))
	{
		dst[dst_sz + i] = src[i];
		i++;
	}
	dst[dst_sz + i] = '\0';
	return (src_sz + dst_sz);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    printf("</-----------------------------------------/>\n");
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int size = 64;
    char buffer[size];

    strcpy(buffer,first);
    int r = strlcat(buffer,last,size);
    puts(buffer);
    printf("Value returned: %d\n",r);
    if(r > size )
        puts("String truncated");
    else
        puts("String was fully copied");
    printf("</------------------------------------------/>\n");
    char source[] = "This is ";
    char destination[] = "a potentially long string";
    size = 64;
    char len[size];

    strcpy(len,source);
    r = ft_strlcat(len,destination,size);
    puts(len);
    printf("Value returned: %d\n",r);
    if(r > size )
        puts("String truncated");
    else
        puts("String was fully copied");
    
    return (0);
}*/
