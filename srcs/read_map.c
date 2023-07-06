/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/06 13:46:14 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_columnlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

static int		ft_rowlen(char *path)
{
	int		rows;
	char	*result;
	int		fd;

	fd = open(path, O_RDWR);
	if (fd == -1) {
		perror("Couldn't open the file. Try again.");
		return (0);
	}
	result = get_next_line(fd);
	rows = 0;
	while (result)
	{
	    result = get_next_line(fd);
		rows++;
	}
	close(fd);
	return (rows);
}

details read_map(char *filename)
{
	char	**split_str;
	int		fd;
	char	*path;
	details *map;
	char	*eachline;

	path = ft_strjoin("/Users/lnambaji/Documents/Cursus/fdf/", filename);
	map = malloc(sizeof(details));
	fd = open(path, O_RDWR);
	if (fd == -1) {
		perror("Couldn't open the file. Try again.");
		return ((details){0, 0, 0, 0, NULL});//return (*map);
	}
	map->rowcount = ft_rowlen(path);
	eachline = get_next_line(fd);
	map->columncount = ft_columnlen(ft_split(eachline, ' '));
	map->arr = malloc(sizeof(int *) * map->rowcount);
	if (!map->arr || !map->rowcount || !map->columncount)
		return ((details){0, 0, 0, 0, NULL});//return (*map);
	while (map->r_pos < map->rowcount)
	{
		map->arr[map->r_pos] = malloc(sizeof(int) * map->columncount);
		split_str = ft_split(eachline, ' ');
		if (!map->arr[map->r_pos] || !split_str)
			return ((details){0, 0, 0, 0, NULL});//return (*map);
		map->c_pos = 0;
		while (map->c_pos < map->columncount)
		{
			map->arr[map->r_pos][map->c_pos] = ft_atoi(split_str[map->c_pos]);
			map->c_pos++;
		}
		free(split_str);
		split_str = NULL;
		eachline = get_next_line(fd);
		map->r_pos++;
	}
	close(fd);
	return (*map);
}