/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:28:28 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/07 17:28:31 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
Adds the element ’new’ at the beginning of the
list.

** (2) the pointer to the next element of 'new' (new->next) points to the
** previous first element of '*lst'
** (3) pointer to the first link of a list '*lst' then points to the 'new'
** element which has been added to the front of the list.
*/
/* My explanation
(1) The address pointed to by new in the linked list is the first 
    element of lst
(2) That first element gets updated to become the value of new
    and then it repeats.
*/
