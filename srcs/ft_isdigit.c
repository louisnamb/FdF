/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:51:35 by lnambaji          #+#    #+#             */
/*   Updated: 2022/01/17 10:41:05 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main()
{
    char c;
    c='5';
    printf("Result when numeric character is passed: %d\n", isdigit(c));
    printf("ft: Result when numeric character is passed: %d", ft_isdigit(c));

    c='+';

    printf("\n\nResult when non-numeric character is passed: %d\n", isdigit(c));
    printf("ft: Result when numeric character is passed: %d", ft_isdigit(c));

    return 0;
}*/
