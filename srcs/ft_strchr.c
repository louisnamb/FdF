/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:26:14 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/28 16:43:37 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*str && str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main() {
	char *str = NULL;
	int c = '\0';
	//if (ft_strchr(str, c) == strchr(str, c))
//		printf("TRUE");
//	else
//		printf("FALSE");
	printf("%s", ft_strchr(str, c));
	return (0);
}
*/