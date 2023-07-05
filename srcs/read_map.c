/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/05 11:41:02 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

map read_map(char *filename)
{
	char	*result;
	char	**split_str;
	int		fd;
	char	*path;
	int		i;
	i = 0;
	char	*tmp;
	char	*eachline;
	int	columns = 0;
	int row = 0;
	int	j = 0;
	int p = 0;

	path = ft_strjoin("/Users/lnambaji/Documents/Cursus/fdf/", filename);
	map details = {0, 0, NULL};
	fd = open(path, O_RDWR);
	if (fd == -1) {
		perror("Couldn't open the file. Try again.");
		return (details);
	}
	result = get_next_line(fd);
    while (result)
	{
		details.rowcount++;
		tmp = result;

		break_down(result);
	    result = get_next_line(fd);
	}
	split_str = ft_split(tmp, ' ');
	while (split_str[details.columncount])
		details.columncount++;
	eachline = get_next_line(fd);
	printf("rowcount: %d: column: %d\n", details.rowcount, details.columncount);
	printf("eachline: %s\n", eachline);
	details.arr = malloc(sizeof(int) * details.rowcount * details.columncount);
	while (eachline)
	{
		split_str = ft_split(eachline, ' ');
		columns = 0;
		while (split_str[columns])
		{
			details.arr[row][columns] = ft_atoi(split_str[columns]);
			columns++;
		}
		free(split_str);
		split_str = NULL;
		eachline = get_next_line(fd);
		row++;
	}	
	//if (i == 1)
	//	free(result);
	//i++;
	close(fd);
	free(result);
	free(eachline);
	while (j < details.rowcount)
	{
		while (p < details.columncount)
		{
			printf("%d", details.arr[j][p]);
			p++;
		}
		printf("\n");
		j++;
	}
	return (details);
}
