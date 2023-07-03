/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:07:31 by lnambaji          #+#    #+#             */
/*   Updated: 2022/02/25 15:12:33 by lnamabji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	while (i < size * count)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
/*
int main()
{
	int *allocated_with_ft_calloc = ft_calloc(5, sizeof(int));
	int *allocated_with_calloc = calloc(5, sizeof(int));

	printf("Values of allocated_with_calloc: ");
	for (size_t i = 0; i < 5; ++i) {
		printf("%d ", allocated_with_calloc[i]); 
		printf("%d ", allocated_with_ft_calloc[i]);

	free(allocated_with_ft_calloc);
	free(allocated_with_calloc);
	return (0);
}
*/