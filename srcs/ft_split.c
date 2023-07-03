/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:26:01 by lnambaji          #+#    #+#             */
/*   Updated: 2023/03/28 15:50:22 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	num_splits(const char *str, char c)
{
	int	j;
	int	index;

	index = 0;
	j = 0;
	while (str[index] && str)
	{
		if (str[index] != c)
		{
			j++;
			while (str[index] != c && str[index])
			{
				index++;
			}	
		}
		else
			index++;
	}
	return (j);
}

int	sz_wrd(char const *str, char c, int i)
{
	int			sz;

	sz = 0;
	while (str[i] && str[i] != c)
	{
		sz++;
		i++;
	}
	return (sz);
}

void	freearr(char **strs, int j)
{
	while (j-- > 0 && strs && strs[j])
	{
		free(strs[j]);
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**split;

	if (!s)
		return (0);
	j = -1;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (num_splits(s, c) + 1));
	if (!split)
		return (0);
	split[num_splits(s, c)] = 0;
	while (++j < num_splits(s, c))
	{
		while (s[i] == c)
			i++;
		split[j] = ft_substr(s, i, sz_wrd(s, c, i));
		if (!split[j])
		{
			freearr(split, j);
			return (0);
		}
		i += sz_wrd(s, c, i);
	}
	return (split);
}
/*
int main()
{
    int p = 0;
    
    char **str = ft_split("test split", ' ');
    if (str == NULL)
        return (1);
    while (str && str[p]) 
    {
        printf("real: %s\n", str[p]);
        p++;
    }
    printf("p = %d\n", p);
    freearr(str, p - 1);
    return (0);
}*/