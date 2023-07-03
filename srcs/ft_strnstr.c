/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:25:33 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 16:44:06 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lim;
	size_t	j;

	j = 0;
	lim = 0;
	if (!needle[0])
		return ((char *) haystack);
	while (lim < len && haystack[lim])
	{
		j = 0;
		while (haystack[lim + j] == needle[j] && needle[j] && lim + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + lim);
			}
			j++;
		}
		lim++;
	}
	return (0);
}
/*

#include <string.h>
#include <stdio.h>
int main()
{
    const char *largestring = "FddgzGHaz";
    const char *smallstring = "ddgz";
    int i = 0;
    while (i < 12)
    {
        printf("real: %s |", strnstr(largestring, smallstring, i));
        printf("| ft: %s\n", ft_strnstr(largestring, smallstring, i));
        i++;
    }
}*/
