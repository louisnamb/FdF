/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:04:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/25 14:26:12 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s)
		write(fd, &*s++, 1);
}
/*
int main()
{
	const char *a = "hello";
	int b = 1;
	printf("%c", ft_putstr_fd(a, b));
	return (0);
}*/