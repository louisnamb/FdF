/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:53:00 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/29 12:37:17 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		--i;
	}
	if (!c)
		return (&str[i]);
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main () {
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "";
	char	*src = "abbbbbbbb";

	if (ft_strrchr("teste", 'e') == strrchr("teste", 'e'))
		printf("correct\n");
	else
		printf("1. incorrect: expected: %s got: %s\n", strrchr("teste", 1024),
		 ft_strrchr("teste", 1024));
	
	if (ft_strrchr("teste", '\0') == strrchr("teste", '\0'))
		printf("correct\n");
	else
		printf("2. incorrect: expected: %s\n", strrchr("teste", 1024));
	
	if (ft_strrchr("xteste", 'x') == ft_strrchr("xteste", 'x'))
		printf("correct\n");
	else
		printf("3. incorrect\n");

	if (strrchr("teste", 'x') == ft_strrchr("teste", 'x'))
		printf("correct\n");
	else
		printf("4. incorrect\n");
		 
	if (strrchr("teste", 1024 + 'e') == ft_strrchr("teste", 1024 + 'e'))
		printf("correct\n");
	else
		printf("5. incorrect | Expected: %s\n", strrchr("teste", 1024 + 'e'));

	if (strrchr("teste", 1024) == ft_strrchr("teste", 1024))
		printf("correct\n");
	else
		printf("6. incorrect %s\n", strrchr("teste", 1024));

	if (strrchr("pepe y cparlos", 'c') == ft_strrchr("pepe y cparlos", 'c'))
		printf("correct\n");
	else
		printf("7. incorrect: expected: %s\n", strrchr("pepe y cparlos", 'c'));
	return(0);
}
*/