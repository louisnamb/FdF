/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:08:12 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/09 11:28:55 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*func_lst;
	t_list	*new_node;

	if (!lst || !del || !f)
		return (NULL);
	func_lst = ft_lstnew(f(lst->content));
	if (!(func_lst))
		return (NULL);
	new_node = func_lst;
	lst = lst->next;
	while (lst)
	{
		func_lst->next = ft_lstnew(f(lst->content));
		if (!(func_lst->next))
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		func_lst = func_lst->next;
		lst = lst->next;
	}
	func_lst->next = NULL;
	return (new_node);
}
/*
#include <stdlib.h>

void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	int *n;

	n = (int*)content;
	*n += 1;
	return (n);
}

void	print_int_list(t_list *list)
{
	while (list)
	{
		printf("%d ", *((int*)list->content));
		list = list->next;
	}
	printf("\n");
}
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst || !lst || !*del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
ll	del(lst->content);
	free(lst);
	lst = NULL;
}

t_list *ft_lstnew(void *content)
{
	t_list	*node;
	
	
	node = (t_list*)malloc(sizeof(t_list));
	if (!(node))
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_list;

	if (!lst)
		return ;
	if (*lst)
	{
		new_list = *lst;
		while (new_list->next)
			new_list = new_list->next;
		new_list->next = new;
	}
	else
		*lst = new;
}

int	main(void)
{
	t_list	*list;
	t_list	*new_list;
	int		*data;
	int		i;

	list = NULL;
	for (i = 0; i < 10; i++)
	{
		data = (int*)malloc(sizeof(int));
		*data = i;
		ft_lstadd_back(&list, ft_lstnew(data));
	}

	printf("Original list: ");
	print_int_list(list);

	new_list = ft_lstmap(list, f, del);
	printf("Modified list: ");
	print_int_list(new_list);

	ft_lstclear(&list, del);
	ft_lstclear(&new_list, del);

	return (0);
}*/