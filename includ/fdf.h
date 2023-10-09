/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/09 15:54:30 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

typedef struct map_info {
	int		r_cnt;
	int		c_cnt;
	int		r_pos;
	int		c_pos;
	int		**arr;
}	t_details;

typedef struct points {
	int		x_c;
	int		y_c;
	int		line_add;
	int		r;
	int		c;
	int		add;
}	t_pts_info;

typedef struct shorten
{
	double	z;
	double	c_p;
	double	r_m;
	double	c_m;
	double	b_m;
}	t_shorten;

typedef struct window_info {
	void			*mlx;
	void			*img;
	void			*win;
	void			*addr;
	int				bbp;
	int				llen;
	int				end;
	int				width;
	int				h;
	struct map_info	*map;
	struct points	*pts;
}	t_data;

typedef struct read {
	int		fd;
	char	**split;
	char	*path;
	char	*eachline;
}	t_read_utils;

typedef struct bresenham {
	int	deltax;
	int	deltay;
	int	diff;
	int	x;
	int	y;
	int	variable_i;
}	t_bresenham;

typedef struct color {
	double	curr_z;
	double	next_z;
	int		x;
	int		vert;
}	t_fade;

typedef struct rgb {
	unsigned char	r;
	unsigned char	b;
	unsigned char	g;
	unsigned char	a;
}	t_rgb;

typedef struct vector {
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct degrees {
	float	x;
	float	y;
	float	z;
}	t_angles;

int			absolute(int result);
void		colorise(t_data *data, int x, int y, int colour);
void		draw_b_l(t_data *mlx, t_vec *start, t_vec *end, t_fade *color);
void		draw_b_h(t_data *mlx, t_vec *start, t_vec *end, t_fade *color);
void		draw_vertical(t_data *mlx, t_vec *start, t_vec *end, int color);
void		draw_grid(t_data *mlx);
int			end(t_data *hook);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		initialisation(t_data *mlx, char *filepath);
int			key_hook(int keycode, t_data *hook);
int			keys_pressed(int keycode, t_data *hook);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
int			mouse_move(int button, int x, int y, t_data *hook);
t_details	*read_map(char *filename);
t_vec		r_xyz(t_vec *new, t_angles theta);
t_vec		rx_xyz(t_vec mat, float theta);
t_vec		ry_xyz(t_vec mat, float theta);
t_vec		rz_xyz(t_vec mat, float theta);
int			shader(t_fade *color, int start, int end, int curr);
void		swap_points(t_data *mlx, t_vec *start, t_vec *end, t_fade *color);