/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:14:10 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/27 10:11:57 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	if (ft_tolower(65) == tolower(65))
		printf("TRUE\n");
	else
		printf("FALSE\n");
	char a[] = {'B', 'U', 'M', 'P', 'y', 's', 't', 'q', ')'};
	int i = 0;
	while (i < 256)
	{
		if (ft_tolower(i) == tolower(i))
			printf("TRUE\n");
		else
			printf("FALSE\n");
		i++;
	}
	return (0);
}*/