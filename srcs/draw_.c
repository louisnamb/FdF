/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/09/29 17:01:12 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical(t_data *mlx, vec *start, vec *end, int color)
{
	int	y;
	int	x;

	x = (int)start->x;
	y = (int)start->y;
	while (y >= end->y)
	{
		add_color(mlx, x, y, color);
		y--;
	}
	return ;
}

int	absolute(int result)
{
	if (result < 0)
		return (result * -1);
	return (result);
}

void	swap_points(t_data *mlx, vec *start, vec *end, gradient *color, int vert)
{
	if (start->x == end->x)
		draw_vertical(mlx, start, end, color->colour);
	if (absolute(end->y - start->y) < absolute(end->x - start->x))
	{
		if (start->x > end->x)
			draw_bresenham_line_l(mlx, end, start, color, vert);
		else
			draw_bresenham_line_l(mlx, start, end, color, vert);
	}
	else
	{
		if (start->y > end->y)
			draw_bresenham_line_h(mlx, end, start, color, vert);
		else
			draw_bresenham_line_h(mlx, start, end, color, vert);
	}
	return ;
}

static int	get_tint(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double	find_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	if (current == start)
		return (0.0);
	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	add_colour(int start, int end, double percentage)
{
	int	red;
	int	green;
	int	blue;

	red = get_tint((start >> 16) & 0xFF, (end >> 16) & 0xFF, percentage);
	green = get_tint((start >> 8) & 0xFF, (end >> 8) & 0xFF, percentage);
	blue = get_tint(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	shader(gradient *color, int start, int end, int curr, int vert)
{
	double	greater;
	int		max;
	int		low;
	int		tmp;

	max = 0xFF0000;
	low = 0x9900FF;
	greater = 0.0;
	if (color->curr_z > color->next_z && vert)
	{
		greater = color->curr_z;
		tmp = max;
		max = low;
		low = tmp;
	}
	else
		greater = color->next_z;
	if (greater == 0.0)
		return (low);
	else if (color->curr_z == color->next_z)
		return (max);
	else
		return (add_colour(low, max, find_percent(start, end, curr)));
}

void	draw_bresenham_line_l(t_data *mlx, vec *start, vec *end, gradient *color, int vert)
{
	bresenham low;

	low.deltaX = (int)end->x - start->x;
	low.deltaY = (int)end->y - start->y;
	low.variable_i = 1;
	if (low.deltaY < 0)
	{
		low.variable_i = -1;
		low.deltaY = -low.deltaY;
	}
	low.diff = (2 * low.deltaY) - low.deltaX;
	low.y = (int)start->y;
	low.x = (int)start->x - 1;
	while (++low.x < end->x)
	{
		add_color(mlx, low.x, low.y, shader(color, start->x, end->x, low.x, vert));
		if (low.diff > 0)
		{
			low.y = low.y + low.variable_i;
			low.diff = low.diff + (2 * (low.deltaY - low.deltaX));
		}
		else
			low.diff = low.diff + 2 * low.deltaY;
	}
	return ;
}

void	draw_bresenham_line_h(t_data *mlx, vec *start, vec *end, gradient *color, int vert)
{
	bresenham high;

	high.deltaX = (int)(end->x - start->x);
	high.deltaY = (int)(end->y - start->y);
	high.variable_i = 1;
	if (high.deltaX < 0)
	{
		high.variable_i = -1;
		high.deltaX = -1 * high.deltaX;
	}
	high.y = (int)start->y - 1;
	high.x = (int)start->x;
	high.diff = (2 * high.deltaX) - high.deltaY;
	while (++high.y < end->y)
	{
		add_color(mlx, high.x, high.y, shader(color, start->y, end->y, high.y, vert));
		if (high.diff > 0)
		{
			high.x = high.x + high.variable_i;
			high.diff = high.diff + (2 * (high.deltaX - high.deltaY));
		}
		else
			high.diff = high.diff + 2 * high.deltaX;
	}
	return ;
}

float	radians(float degrees)
{
	return ((degrees * M_PI) / 180.0);
}

vec	rz_xyz(vec mat, float theta)
{
	float	cosTheta;
	float	nsinTheta;
	vec		vec;

	cosTheta = cos(radians(theta));
	nsinTheta = -sin(radians(theta));
	vec.x = ((mat.x * cosTheta) + (nsinTheta * mat.y) + (0.0 * mat.z));
	vec.y = (((nsinTheta * -1) * mat.x) + (cosTheta * mat.y) + (mat.z * 0.0));
	vec.z = ((mat.x * 0.0) + (mat.y * 0.0) + (mat.z * 1.0));
	return (vec);
}

vec	rx_xyz(vec mat, float theta)
{
	float	cosTheta;
	float	nsinTheta;
	vec		vec;

	cosTheta = cos(radians(theta));
	nsinTheta = -sin(radians(theta));
	vec.x = ((1.0 * mat.x) + (0.0 * mat.y) + (mat.z * 0));
	vec.y = ((0.0 * mat.x) + (cosTheta * mat.y) + (nsinTheta * mat.z));
	vec.z = ((0.0 * mat.x) + (mat.y * (nsinTheta * -1)) + (mat.z * cosTheta));
	return (vec);
}

vec	ry_xyz(vec mat, float theta)
{
	float	cosTheta;
	float	nsinTheta;
	vec		vec;

	cosTheta = cos(radians(theta));
	nsinTheta = -sin(radians(theta));
	vec.x = ((cosTheta * (mat.x)) + (0.0 * mat.y) + ((nsinTheta * -1) * mat.z));
	vec.y = ((mat.x * 0.0) + (mat.y * 1.0) + (mat.z * 0.0));
	vec.z = ((nsinTheta * mat.x) + (0.0 * mat.y) + (cosTheta * mat.z));
	return (vec);
}

vec	r_xyz(vec *new, angles theta)
{
	vec	*matrix;

	matrix = new;
	*matrix = ry_xyz(*matrix, theta.y);
	*matrix = rz_xyz(*matrix, theta.z);
	*matrix = rx_xyz(*matrix, theta.x);
	return (*matrix);
}

void	initialiser(angles *degrees, pts_info *pts)
{
	pts->x_c = 620;
	pts->y_c = 100;
	pts->line_add = 5;
	pts->r = 0;
	pts->c = 0;
	pts->add = 50.0;
	degrees->x = 25.0;
	degrees->y = 15.0;
	degrees->z = 5.0;
	return ;
}
void	draw_grid(t_data *m)
{
	vec			before;
	vec			after;
	vec			past;
	angles		*degrees;

	degrees = malloc(sizeof(angles));
	if (!m->pts || !degrees)
		return ;
	initialiser(degrees, m->pts);
	while (m->pts->r + 1 <= m->map->r_cnt)
	{
		m->pts->c = 0;
		while (m->pts->c + 1 < m->map->c_cnt)
		{
			before = r_xyz(&((vec){m->pts->x_c, m->pts->y_c, m->pts->line_add * m->map->arr[m->pts->r][m->pts->c]}), *degrees);
			past = r_xyz(&((vec){m->pts->x_c + m->pts->add, m->pts->y_c, m->pts->line_add * m->map->arr[m->pts->r][m->pts->c + 1]}), *degrees);
			if (m->pts->c <= m->map->c_cnt)
				swap_points(m, &before, &past, &(gradient){m->map->arr[m->pts->r][m->pts->c], 
				m->map->arr[m->pts->r][m->pts->c + 1], m->pts->x_c, 0xFF0000, 0x9900FF}, 1);//red horizontal 
			if (m->pts->r)
			{
				after = r_xyz(&((vec){m->pts->x_c, m->pts->y_c - m->pts->add, m->pts->line_add * m->map->arr[m->pts->r - 1][m->pts->c]}), *degrees);
				swap_points(m, &before, &after, &(gradient){m->map->arr[m->pts->r - 1][m->pts->c], 
				m->map->arr[m->pts->r][m->pts->c], m->pts->x_c, 0xFF0000, 0x9900FF}, 1);//blue vert good
			}
			m->pts->c++;
			m->pts->x_c += m->pts->add;
		}
		if (m->pts->c + 1 == m->map->c_cnt && m->pts->r && m->pts->r < m->map->r_cnt)
		{
			before = r_xyz(&((vec){m->pts->x_c, m->pts->y_c, m->pts->line_add * m->map->arr[m->pts->r][m->map->c_cnt - 1]}), *degrees);
			after = r_xyz(&((vec){m->pts->x_c, m->pts->y_c - m->pts->add, m->pts->line_add * m->map->arr[m->pts->r - 1][m->map->c_cnt - 1]}), *degrees);
			swap_points(m, &before, &after, &(gradient){m->map->arr[m->pts->r][m->map->c_cnt - 1], 
			m->map->arr[m->pts->r - 1][m->map->c_cnt - 1], m->pts->x_c, 0x9900FF, 0xFF0000}, 0);//red horizontal 
		}
		m->pts->x_c = 620;
		m->pts->y_c += m->pts->add;
		m->pts->r++;
	}
	return ;
}