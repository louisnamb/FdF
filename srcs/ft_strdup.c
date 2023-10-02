/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:06:48 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/02 15:59:28 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		p;

	p = 0;
	s2 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	while (s1[p])
	{
		s2[p] = s1[p];
		p++;
	}
	s2[p] = 0;
	return (s2);
}
