/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:49:08 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/29 12:08:55 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_setchkr(char c, char const *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *find)
{
	size_t	start;
	size_t	end;
	char	*substring;

	if (!str || !find)
		return (0);
	start = 0;
	end = ft_strlen(str);
	while (str[start] && ft_setchkr(str[start], find))
		start++;
	while (end > start && ft_setchkr(str[end - 1], find))
		end--;
	substring = ft_substr(str, start, end - start);
	return (substring);
}
/*
int main()
{
    char *p1 = "   xxxtripouille";
    char *p2 = " x";
    printf("ft:%s\n", ft_strtrim(p1, p2));
	return  (0);
}
*/