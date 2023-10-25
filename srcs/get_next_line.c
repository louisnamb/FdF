/* ************************************************************************** */
/*																		      */
/*														:::	  ::::::::        */
/*   get_next_line.c									:+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: lnambaji <lnambaji@student.42.fr>		  +#+  +:+	   +#+		      */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2023/04/13 15:49:10 by lnambaji		  #+#	#+#			      */
/*   Updated: 2023/04/27 14:27:50 by lnambaji		 ###   ########.fr	      */
/*																			  */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/fdf.h"

char	*ft_free(char **data, char *new)
{
	free(*data);
	*data = NULL;
	return (new);
}

char	*read_file(int fd, char *buffer, char **nbuff)
{
	int		next;

	next = 1;
	while (next != 0)
	{
		next = read(fd, buffer, BUFFER_SIZE);
		if (next <= -1 || (next == 0 && *nbuff[0] == '\0'))
			return (ft_free(nbuff, NULL));
		else if (next == 0)
			break ;
		buffer[next] = '\0';
		*nbuff = ft_free(nbuff, ft_strjoin(*nbuff, buffer));
		if (ft_strchr(*nbuff, '\n'))
			break ;
	}
	return (*nbuff);
}

char	*get_currline(int fd, char *buffer, char **nbuff, char *rval)
{
	int		character;

	character = 1;
	read_file(fd, buffer, nbuff);
	if (ft_strchr(*nbuff, '\n'))
		rval = ft_substr(*nbuff, 0, ft_strchr(*nbuff, '\n') - *nbuff + 1);
	else if (ft_strchr(*nbuff, '\0'))
	{
		rval = ft_strdup(*nbuff);
		character = 0;
	}
	else
		return (NULL);
	if (character)
		*nbuff = ft_free(nbuff, ft_strdup(ft_strchr(*nbuff, '\n') + 1));
	else
	{
		*nbuff = ft_free(nbuff, ft_strdup(ft_strchr(*nbuff, '\0')));
	}
	return (rval);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*rval;
	static char	*nbuff;
	size_t		j;

	j = 0;
	rval = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (ft_free(&nbuff, NULL));
	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	while (j < BUFFER_SIZE + 1)
		buffer[j++] = 0;
	if (nbuff == NULL)
		nbuff = ft_strdup("");
	rval = get_currline(fd, buffer, &nbuff, rval);
	free(buffer);
	buffer = NULL;
	if (!rval)
	{
		ft_free(&nbuff, NULL);
		ft_free(&rval, NULL);
		return (NULL);
	}
	return (rval);
}
