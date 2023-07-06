/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/06 15:53:10 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>

typedef struct	window_info {
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bitsperpix;
	int		linelen;
	int		endian;
}	t_data;

typedef struct	map_info {
	int		rowcount;
	int		columncount;
	int		r_pos;
	int		c_pos;
	int		**arr;
}	details;

void		mmlx_put_pix(t_data *data, int x, int y, int colour);

int			esc(int keycode, t_data *hook);

void		draw_square(t_data *mlx, int x, int x_bound, int height);

void		draw_point(t_data *mlx, int x, int y);

int			mouse_move(int button, int x, int y, t_data *hook);

details		read_map(char *filename);

char		**ft_split(char const *s, char c);

char		*get_next_line(int fd);

char		*ft_strjoin(char const *s1, char const *s2);

int			ft_atoi(const char *str);

int			key_hook(int keycode, t_data *hook);

int			ft_isdigit(int c);

int			xbutton(t_data *hook);// int x, int y, t_data *hook);

int			mouse_hook(int keycode, int button, int x, int y, t_data *hook);

int			controls(int keycode, t_data *hook);