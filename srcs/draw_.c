/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/17 15:35:31 by lnambaji         ###   ########.fr       */
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

void	swap_points(t_data *mlx, vec *start, vec *end, int color)
{
	if (start->x == end->x)
		draw_vertical(mlx, start, end, color);
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

int	shader(double distance, double prev, int curr_x, int color)
{
	(void)curr_x;
	if (distance == 0.0 && prev == 0.0)
		return (0xFFFFFF);
	else if (distance == 0.0 && prev != 0.0)
		return ((prev / 100.0) * (double)color);
//	return ((x_c - 540 / 540) * (double)color); put this function in the draw_bresenham_line
		return ((distance / 100.0) * (double)color);
}

void		draw_bresenham_line_l(t_data *mlx, vec *start, vec *end, int color)
{
	int	x;
	int	y;
	int	deltaX;
	int deltaY;
	int	diff;
	int yi = 1;

	deltaX = end->x - start->x;
	deltaY = end->y - start->y;
	yi = 1;
	if (deltaY < 0)
	{
		yi = -1;
		deltaY = -deltaY;
	}
	diff = (2 * deltaY) - deltaX;
	y = (int)start->y;
	x = (int)start->x;
	while (x < end->x)
	{
		mmlx_put_pix(mlx, x, y, color);
		if (diff > 0)
		{
			y = y + yi;
			diff = diff + (2 * (deltaY - deltaX));
		}
		else
			diff = diff + 2 * deltaY;
		x++;
	}
	return ;
}

void		draw_bresenham_line_h(t_data *mlx, vec *start, vec *end, int color)
{
	int	x;
	int	y;
	int	deltaX;
	int deltaY;
	int	diff;
	int xi;

	deltaX = (int)(end->x - start->x);
	deltaY = (int)(end->y - start->y);
	xi = 1;
	if (deltaX < 0)
	{
		xi = -1;
		deltaX = -1 * deltaX;
	}
	y = (int)start->y;
	x = (int)start->x;
	diff = (2 * deltaX) - deltaY;
	while (y < end->y)
	{
		mmlx_put_pix(mlx, x, y, color);
		if (diff > 0)
		{
			x = x + xi;
			diff = diff + (2 * (deltaX - deltaY));
		}
		else
			diff = diff + 2 * deltaX;
		y++;
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
	int	y_c;
	vec	before;
	vec	after;
	vec	past;
	angles	degrees;
	x_c = 540;
	degrees = (angles){0, 20, 10};
	y_c = 0;
	r = 0;
	while (r + 1 <= map->rowcount)
	{
		c = 0;
		while (c + 1 < map->columncount)
		{
			before = r_xyz((vec){x_c, y_c, map->arr[r][c]}, degrees);
			past = r_xyz((vec){x_c + 50, y_c, map->arr[r][c + 1]}, degrees);
			if (c <= map->columncount)
				swap_points(mlx, &before, &past, shader(map->arr[r][c], map->arr[r][c + 1], x_c, 0xFF0000));//red horizontal 
			if (r)
			{
				after = r_xyz((vec){x_c, y_c - 50, map->arr[r - 1][c]}, degrees);
				swap_points(mlx, &before, &after, shader(map->arr[r][c], map->arr[r - 1][c], x_c, 0xFF0000));//blue vertical good
			}
			c++;
			x_c += 50;
		}
		if (c + 1 == map->columncount && r && r < map->rowcount)
		{
			before = r_xyz((vec){x_c, y_c, map->arr[r][map->columncount - 1]}, degrees);
			after = r_xyz((vec){x_c, y_c - 50, map->arr[r - 1][map->columncount - 1]}, degrees);
			swap_points(mlx, &before, &after, shader(map->arr[r][map->columncount - 1], map->arr[r - 1][map->columncount - 1], x_c, 0xFF0000));//red horizontal 
		}
		x_c = 540;
		y_c += 50;
		r++;
	}
	return ;
}

/*
Use wolfram alpha to condense/simplify calculations
*/