/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/20 12:50:05 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_columnlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

static int	ft_rowlen(char *path)
{
	int		rows;
	char	*result;
	int		fd;

	fd = open(path, O_RDWR);
	if (fd == -1)
	{
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

int	read_initialisation(t_read_utils *read, t_details *map, char *filename)
{
	read->path = ft_strjoin("/Users/lnambaji/Documents/Cursus/fdf/", filename);
	read->fd = open(read->path, O_RDWR);
	if (read->fd == -1)
	{
		perror("Couldn't open the file. Try again.");
		return (1);
	}
	map->r_pos = -1;
	map->r_cnt = ft_rowlen(read->path);
	read->eachline = get_next_line(read->fd);
	map->c_cnt = ft_columnlen(ft_split(read->eachline, ' '));
	map->arr = malloc(sizeof(int *) * map->r_cnt);
	if (!map->arr || !map->r_cnt || !map->c_cnt)
		return (1);
	return (0);
}

t_details	*read_map(char *filename)
{
	t_details		*map;
	t_read_utils	*read;

	map = malloc(sizeof(t_details));
	read = malloc(sizeof(t_read_utils));
	if (!map || !read || read_initialisation(read, map, filename))
		return (&(t_details){0, 0, 0, 0, NULL});
	while (++map->r_pos < map->r_cnt)
	{
		map->arr[map->r_pos] = malloc(sizeof(int) * map->c_cnt);
		read->split = ft_split(read->eachline, ' ');
		if (!map->arr[map->r_pos] || !read->split)
			return (&(t_details){0, 0, 0, 0, NULL});
		map->c_pos = -1;
		while (++map->c_pos < map->c_cnt)
			map->arr[map->r_pos][map->c_pos] = ft_atoi(read->split[map->c_pos]);
		free(read->split);
		read->split = NULL;
		read->eachline = get_next_line(read->fd);
	}
	close(read->fd);
	return (map);
}
