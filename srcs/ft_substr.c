/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:14:25 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/21 14:44:08 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (0);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char	str[] = "i just want this part #############";
	char	src[] = "i just want this part #############";
	size_t	size = 20;
	unsigned int j = 10;
	if (ssubstr(src, j, size) == ft_substr(str, j, size))
		printf("%s", ssubstr(str, j, size));
	else
		printf("%s", ssubstr(str, j, size));
    return 0;
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		p;
	int		i;

	i = 0;
	p = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	while (s1[p])
	{
		s2[p] = s1[p];
		p++;
	}
	s2[p] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

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

char	*ssubstr(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
*/
