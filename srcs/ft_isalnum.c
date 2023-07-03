/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:43:56 by lnambaji          #+#    #+#             */
/*   Updated: 2022/01/17 11:49:53 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1);
	}
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main()
{
	char c;
    int result;

    c = '8';
    result = isalnum(c);
    printf("When %c is passed, return value is %d\n", c, result);
    printf("ft: When %c is passed, return value is %d\n\n", c, ft_isalnum(c));

    c = 'F';
    result = isalnum(c);
    printf("When %c is passed, return value is %d\n", c, result);
    printf("ft: When %c is passed, return value is %d\n\n", c, ft_isalnum(c));

    c = 'z';
    result = isalnum(c);
    printf("When %c is passed, return value is %d\n", c, result);
    printf("ft: When %c is passed, return value is %d\n\n", c, ft_isalnum(c));

    c = '/';
    result = isalnum(c);
    printf("When %c is passed, return value is %d\n", c, result);
    printf("ft: When %c is passed, return value is %d\n\n", c, ft_isalnum(c));

    return 0;
}*/
