/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:01:02 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/24 15:43:28 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int main() {
	int c = 'c';
	int d = 5;
	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
	printf("%c\n", ft_toupper(d));
	printf("%c\n", toupper(d));
}*/
