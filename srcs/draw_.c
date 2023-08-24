/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/24 16:00:26 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical(t_data *mlx, vec *start, vec *end, int color)
{
	int	y;
	int	x;

	(void)end->x;
	x = (int)start->x;
	y = (int)start->y;
	while (y >= end->y)
	{
		mmlx_put_pix(mlx, x, y, color);
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

void	swap_points(t_data *mlx, vec *start, vec *end, gradient *color)
{
	if (start->x == end->x)
		draw_vertical(mlx, start, end, color->colour);
	if (absolute(end->y - start->y) < absolute(end->x - start->x))
	{
		if (start->x > end->x)
			draw_bresenham_line_l(mlx, end, start, color);
		else
			draw_bresenham_line_l(mlx, start, end, color);
	}
	else
	{
		if (start->y > end->y)
			draw_bresenham_line_h(mlx, end, start, color);
		else
			draw_bresenham_line_h(mlx, start, end, color);
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

int	shader(gradient *color, int start, int end, int curr)
{
	double	greater;
	int		max;

	max = 0x1000FF;
	greater = 0.0;
	if (color->curr_z > color->prev_z)
		greater = color->curr_z;
	else
		greater = color->prev_z;
	if (!greater)
		return (0xFFFFFF);
	else if (color->curr_z == color->prev_z)
		return (max);//((greater / 100.0) * ((double)color->colour));
	else// if (((last - curr) % last) == 50)// || ((last - curr) % last) == 0)
		return (add_colour(color->colour, max, find_percent(start, end, curr)));
}

void		draw_bresenham_line_l(t_data *mlx, vec *start, vec *end, gradient *color)
{
	bresenham low;

	low.deltaX = end->x - start->x;
	low.deltaY = end->y - start->y;
	low.variable_i = 1;
	if (low.deltaY < 0)
	{
		low.variable_i = -1;
		low.deltaY = -low.deltaY;
	}
	low.diff = (2 * low.deltaY) - low.deltaX;
	low.y = (int)start->y;
	low.x = (int)start->x;
	while (low.x < end->x)
	{
		mmlx_put_pix(mlx, low.x, low.y , shader(color, start->x, end->x, low.x));
		if (low.diff > 0)
		{
			low.y = low.y + low.variable_i;
			low.diff = low.diff + (2 * (low.deltaY - low.deltaX));
		}
		else
			low.diff = low.diff + 2 * low.deltaY;
		low.x++;
	}
	return ;
}

void		draw_bresenham_line_h(t_data *mlx, vec *start, vec *end, gradient *color)
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
	high.y = (int)start->y;
	high.x = (int)start->x;
	high.diff = (2 * high.deltaX) - high.deltaY;
	while (high.y < end->y)
	{
		mmlx_put_pix(mlx, high.x, high.y, shader(color, start->y, end->y, high.y));
		if (high.diff > 0)
		{
			high.x = high.x + high.variable_i;
			high.diff = high.diff + (2 * (high.deltaX - high.deltaY));
		}
		else
			high.diff = high.diff + 2 * high.deltaX;
		high.y++;
	}
	return ;
}

vec	rz_xyz(vec matrix, float theta)
{
	vec	vector;

	vector.x = (matrix.x * cos(RADIANS(theta)) + -sin(RADIANS(theta)) * matrix.y + 0 * matrix.z);
	vector.y = (sin(RADIANS(theta)) * matrix.x + cos(RADIANS(theta)) * matrix.y + matrix.z * 0);
	vector.z = (matrix.x * 0 + matrix.y * 0 + matrix.z * 1);
	return (vector);
}

vec	rx_xyz(vec matrix, float theta)
{
	vec	vector;

	vector.x = (1 * matrix.x + 0 * matrix.y + matrix.z * 0);
	vector.y = (0 * matrix.x + cos(RADIANS(theta)) * matrix.y + -sin(RADIANS(theta)) * matrix.z);
	vector.z = (0 * matrix.x + matrix.y * sin(RADIANS(theta)) + matrix.z * cos(RADIANS(theta)));
	return (vector);
}

vec	ry_xyz(vec matrix, float theta)
{
	vec	vector;

	vector.x = (cos(RADIANS(theta)) * matrix.x + 0 * matrix.y + sin(RADIANS(theta)) * matrix.z);
	vector.y = (matrix.x * 0 + matrix.y * 1 + matrix.z * 0);
	vector.z = (-sin(RADIANS(theta)) * matrix.x + 0 * matrix.y + cos(RADIANS(theta)) * matrix.z);
	return (vector);
}

vec	r_xyz(vec new, angles theta)
{
	vec	matrix;

	matrix = new;
	matrix = rx_xyz(matrix, theta.x);
	matrix = rz_xyz(matrix, theta.z);
	matrix = ry_xyz(matrix, theta.y);
	return (matrix);
}


void	draw_grid(t_data *mlx, details *map)
{
	int	c;
	int	r;
	int	x_c;
	int add;
	int	y_c;
	int	z_addder;
	vec		before;
	vec		after;
	vec		past;
	angles	degrees;
	x_c = 620;
	degrees = (angles){45, 30, 25};
	y_c = 100;
	r = 0;
	z_addder = 5;
	add = 50;
	while (r + 1 <= map->rowcount)
	{
		c = 0;
		while (c + 1 < map->columncount)
		{
			before = r_xyz((vec){x_c, y_c, z_addder * map->arr[r][c]}, degrees);
			past = r_xyz((vec){x_c + add, y_c, z_addder * map->arr[r][c + 1]}, degrees);
			if (c <= map->columncount)
				swap_points(mlx, &before, &past, &(gradient){map->arr[r][c], map->arr[r][c + 1], x_c, 0xFF0000});//red horizontal 
			if (r)
			{
				after = r_xyz((vec){x_c, y_c - add, z_addder * map->arr[r - 1][c]}, degrees);
				swap_points(mlx, &before, &after, &(gradient){map->arr[r][c], map->arr[r - 1][c], x_c, 0xFF0000});//blue vertical good
			}
			c++;
			x_c += add;
		}
		if (c + 1 == map->columncount && r && r < map->rowcount)
		{
			before = r_xyz((vec){x_c, y_c, z_addder * map->arr[r][map->columncount - 1]}, degrees);
			after = r_xyz((vec){x_c, y_c - add, z_addder * map->arr[r - 1][map->columncount - 1]}, degrees);
			swap_points(mlx, &before, &after, &(gradient){map->arr[r][map->columncount - 1], map->arr[r - 1][map->columncount - 1], x_c, 0xFF0000});//red horizontal 
		}
		x_c = 620;
		y_c += 50;
		r++;
	}
	return ;
}

/*
Use wolfram alpha to condense/simplify calculations
*/