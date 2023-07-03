/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:06:38 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 15:33:08 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*
#include <stdlib.h>
#inlcude <stdio.h>

int main()
{
    t_list *head = malloc(sizeof(t_list));
    t_list *second = malloc(sizeof(t_list));
    t_list *third = malloc(sizeof(t_list));

    head->content = 1;
    head->next = second;
    second->content = 2;
    second->next = third;
    third->content = 3;
    third->next = NULL;

    printf("len: %d", ft_lstsize(head));
   // Remember to make "void *content" to "int content"
    return (0);
}*/
