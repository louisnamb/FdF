/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:50:12 by lnambaji          #+#    #+#             */
/*   Updated: 2022/01/17 12:25:32 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
   int ch;

   for (ch = 0x7c; ch <= 0x82; ch++) {
      printf("%#04x    ", ch);
      if (isascii(ch))
         printf("The character is %c\n", ch);
      else
         printf("Cannot be represented by an ASCII character\n");
   }
   int ft_ch;

   for (ft_ch = 0x7c; ft_ch <= 0x82; ft_ch++) {
      printf("%#04x    ", ft_ch);
      if (ft_isascii(ft_ch))
         printf("ft: The character is %c\n", ft_ch);
      else
         printf("ft: Cannot be represented by an ASCII character\n");
   }
   return 0;
}*/
