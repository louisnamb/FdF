/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/29 15:16:45 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <math.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>

typedef struct	window_info {
	void	*mlx;
	void	*img;
	char	*addr;
	int		bitsperpix;
	int		linelen;
	int		endian;
	void	*win;
}	t_data;

typedef struct	map_info {
	int		rowcount;
	int		columncount;
}	map;

void	mmlx_put_pix(t_data *data, int x, int y, int colour);

int	insidewin(int keycode, t_data *hook);

void	draw_square(t_data *mlx, int x, int x_bound, int height, char which);

int	xbutton(int button, int x, int y, t_data *hook);

void read_map(char *filename);

char		**ft_split(char const *s, char c);

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);