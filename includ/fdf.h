/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/28 12:50:05 by lnambaji         ###   ########.fr       */
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
	void	*addr;
	int		bitsperpix;
	int		linelen;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef	struct bresenham {
	int deltaX;
	int deltaY;
	int	diff;
	int x;
	int y;
	int	variable_i;
} bresenham;

typedef struct	map_info {
	int		rowcount;
	int		columncount;
	int		r_pos;
	int		c_pos;
	int		**arr;
}	details;

typedef	struct	points {
	int x_c;
	int y_c;
	int	line_add;
	int	r;
	int	c;
	int add;
}	points_info;

typedef	struct color {
	double curr_z;
	double prev_z;
	int x;
	int colour;
}	gradient;

typedef	struct rgb {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
} rgb;

typedef	struct vector {
	float	x;
	float	y;
	float	z;
} vec;

typedef	struct	degrees {
	float	x;
	float	y;
	float	z;
}	angles;

#define RADIANS(degrees) (degrees * M_PI) / 180.0

void		initialisation(t_data *mlx);

int			esc(int keycode, t_data *hook);

int			mouse_move(int button, int x, int y, t_data *hook);

int			xbutton(t_data *hook);// int x, int y, t_data *hook);

int			key_hook(int keycode, t_data *hook);

int			mouse_hook(int keycode, int button, int x, int y, t_data *hook);

int			controls(int keycode, t_data *hook);

details		*read_map(char *filename);

char		**ft_split(char const *s, char c);

char		*get_next_line(int fd);

char		*ft_strjoin(char const *s1, char const *s2);

int			ft_atoi(const char *str);

int			ft_isdigit(int c);

void		mmlx_put_pix(t_data *data, int x, int y, int colour);

void		draw_bresenham_line_l(t_data *mlx, vec *start, vec *end, gradient *color);

void		draw_bresenham_line_h(t_data *mlx, vec *start, vec *end, gradient *color);

void 		draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);

void		draw_vertical(t_data *mlx, vec *start, vec *end, int color);

void		draw_grid(t_data *mlx, details *map);