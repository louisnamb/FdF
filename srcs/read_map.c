/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/06 11:08:28 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

details read_map(char *filename)
{
	char	*result;
	char	**split_str;
	int		fd;
	char	*path;
	int		i;
	i = 0;
	char	*tmp;
	char	*eachline;
	int	column = 0;
	int row = 0;
	int	j = 0;
	int p = 0;

	path = ft_strjoin("/Users/lnambaji/Documents/Cursus/fdf/", filename);
	details *map = malloc(sizeof(details));
	map->rowcount = 0;
	map->columncount = 0;
	map->arr = NULL;
	fd = open(path, O_RDWR);
	if (fd == -1) {
		perror("Couldn't open the file. Try again.");
		return (*map);
	}
	result = get_next_line(fd);
    while (result)
	{
		map->rowcount++;
		tmp = result;
	    result = get_next_line(fd);
	}
	split_str = ft_split(tmp, ' ');
	while (split_str[map->columncount])
		map->columncount++;
	close(fd);
	fd = open(path, O_RDWR);
	eachline = get_next_line(fd);
	map->arr = malloc(sizeof(int *) * map->rowcount * map->columncount);
	if (!map->arr)
		return (*map);
	while (eachline && row <= map->rowcount && column <= map->columncount)
	{
		printf("inside loop row: %d columncount: %d\n", row, map->columncount);
		map->arr[row] = malloc(sizeof(int) * map->columncount);
		split_str = ft_split(eachline, ' ');
		if (!map->arr[row] || !split_str)
			return (*map);
		column = 0;
		printf("louis: %d ft_isdigit: %d\n", ft_isdigit(split_str[column][0]), split_str[column][0]);
		while (ft_isdigit(split_str[column][0]))
		{
			printf("gfsdfdsdfgdfg: %d ", map->arr[row][column]);
			map->arr[row][column] = ft_atoi(split_str[column]);
			column++;
		}
		printf("df\n");
		free(split_str);
		split_str = NULL;
		eachline = get_next_line(fd);
		row++;
	}	
	//if (i == 1)
	//	free(result);
	//i++;
	close(fd);
	while (j < map->rowcount)
	{
		printf("j: %d map->rowcount: %d p: %d columncount: %d\n", j, map->rowcount, p, map->columncount);
		while (p < map->columncount)
		{
			printf("out\n");
			printf("%d", map->arr[j][p]);
			p++;
		}
		printf("\n");
		j++;
	}
	return (*map);
}
