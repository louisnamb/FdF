/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/29 15:39:31 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void read_map(char *filename)
{
	int		fd;
	int		i;
	char	*result;
	char	**split_str;
	char	*path;
	i = 1;

	printf("filename: %s", filename);
	path = ft_strjoin("/Users/stevenblessingngezahayo/Documents/louis/", filename + 1);
	printf("path : %s\n", path);
	fd = open(path, O_RDWR);
	if (fd == -1) {
		perror("Couldn't open the file. Try again.");
		return ;
	}
	printf("it worked!\n");
	map details = {0, 0};
	result = get_next_line(fd);
	printf("here\n");
	while (result)
	{
		printf("inside loop\n");
		details.rowcount++;
		result = get_next_line(fd);
		printf("result: '%s\n", result);
		split_str = ft_split(result, ' ');
		printf("split worked!\n");
		while (split_str[details.columncount])
			details.columncount++;
		free(split_str);
		split_str = NULL;
		if (i == 1)
			free (result);
		i++;
	}
	printf("here1\n");
	close(fd);
	printf("rowcount: %d: %d\n", details.rowcount, details.columncount);

	return ;
}
