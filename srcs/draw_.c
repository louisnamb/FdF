/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/15 16:57:10 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	int	y;
	int	x;

	(void)endX;
	x = startX;
	y = startY;
	while (y >= endY)
	{
		mmlx_put_pix(mlx, x, y, color);
		y--;
	}
	return ;
}

void	swap_points(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	if (startX == endX)
		draw_vertical(mlx, startX, startY, endX, endY, color);
	if (endX > startX)
	{
		if (endY > startY)
			draw_bresenham_line_h(mlx, startX, startY, endX, endY, color);
		else
			draw_bresenham_line_l(mlx, startX, startY, endX, endY, color);
	}
	else
	{
		if (endY > startY)
			draw_bresenham_line_h(mlx, endX, endY, startX, startY, color);
		else
			draw_bresenham_line_l(mlx, endX, endY, startX, startY, color);
	}
	return ;
}

void		draw_bresenham_line_l(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	int	x;
	int	y;
	int	deltaX;
	int deltaY;
	int	diff;
	int yi = 1;
	deltaX = endX - startX;
	deltaY = endY - startY;
	yi = 1;
	if (deltaY < 0)
	{
		yi = -1;
		deltaY = -deltaY;
	}
	diff = (2 * deltaY) - deltaX;
	y = startY;
	x = startX;
	while (x < endX)
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

void		draw_bresenham_line_h(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	int	x;
	int	y;
	int	deltaX;
	int deltaY;
	int	diff;
	int xi;

	deltaX = endX - startX;
	deltaY = endY - startY;
	xi = 1;
	if (deltaX < 0)
	{
		xi = -1;
		deltaX = -deltaX;
	}
	y = startY;
	x = startX;
	diff = 2 * deltaY - deltaX;
	while (y < endY)
	{
		mmlx_put_pix(mlx, x, y, color);
		if (diff > 0)
		{
			x = x + xi;//= direction;
			diff = diff + (2 * (deltaX - deltaY));
		}
		else
			diff = diff + 2 * deltaY;
		y++;
	}
	return ;
}

vec	rz_xyz(vec matrix, angle theta)
{
	vec	vector;

	vector.x = (matrix.x * cos(RADIANS(theta.x)) + -sin(RADIANS(theta.x)) * matrix.y + 0 * z);
	vector.y = (sin(RADIANS(theta.y)) * matrix.x + cos(RADIANS(theta.y)) * matrix.y + matrix.z * 0);
	vector.z = (x * 0 + matrix.y * 0 + matrix.z * 1);
	return (vector);
}

input_point 
rx_x
rx_y
rx_z
output_point

output_point
ry_x
ry_y
ry_z
output_point

output_point
rz_x
rz_y
rz_z
output_point

vec	ry_xyz(vec matrix, angle theta)
{
	vec	vector;

	vector.x = (1 * matrix.x + 0 * matrix.y + matrix.z * 0);
	vector.y = (0 * matrix.x + cos(RADIANS(theta.y) * matrix.y + -sin(RADIANS(theta.y) * z)));
	vector.z = (0 * matrix.x + matrix.y * sin(RADIANS(theta.z)) + matrix.z * cos(RADIANS(theta.z)));
	return (vector);
}

vec r_xyz(vec matrix, angle theta)
{
	matrix = rx_xyz(matrix, theata.x);
	matrix = ry_xyz(matrix, theta.y);
	matrix = rz_xyz(matrix, theta.z)
	return (matrix);
}

vec3 p1;
vec3 p2;

p1 = rx_xyz(insert);
p1 = ry_xyz(p1);
p1 = rz_xyz(p1);

p2 = rx_xyz(insert);
p2 = ry_xyz(insert);
p2 = rz_xyz(insert);
plot (p1.x, p1.y , p2.x, p2.y);

vec	ry_xyz(vec matrix, int angle)
{
	vec	vector;

	vector.x = (cos(RADIANS(theta.x)) * matrix.x + 0 * matrix.y + sin(RADIANS(theta.x)) * z);
	vector.y = (cos(RADIANS(theta.y)) * 0 + matrix.y * 1 + matrix.z * 0);
	vector.z = (-sin(RADIANS(theta.z)) * matrix.x + 0 * matrix.y + cos(RADIANS(theta.z)) * z);
	return (vector);
}

int	shader(double distance, int color)
{
	if (distance == 0.0)
		return (0xFFFFFF);
	return ((distance / 100.0) * (double)color);
}

void	draw_grid(t_data *mlx, details *map)
{
	int	c;
	int	r;
	int	x_c;
	int	y_c;
	int add;

	int xR = 45;
	x_c = 450;
	y_c = 1;
	r = 0;
	add = 25;
	while (r + 1 < map->rowcount)
	{
		c = 0;
		while (c + 1 < map->columncount)
		{
			vec	before;
			vec	after;

			before = rx_xyz({x_c, y_c, map->arr[r][c]}, 45);
			before = ry_xyz(before, 60);
			before = rz_xyz(before, 75);

			after = rx_xyz({x_c, y_c - add, map->arr[r][c]}, 34);
			after = ry_xyz(after, 53);
			after = rz_xyz(after, 60);
			if (c < map->columncount)
				swap_points(mlx, before.x, before.y, after.x, after.y, 
				shader(map->arr[r][c + 1], 0xFFFFFF));//red horizontal 
			if (r)
				before = {x_c, y_c, map->arr[r][c]};
				after = {x_c, y_c, map->arr[r - 1][c]};
				swap_points(mlx, before.x, before.y, after.x, after.y,
				shader(map->arr[r - 1][c], 0xFFFFFF));//blue vertical good
			c++;
			x_c += add;
		}
		x_c = 450;
		y_c += add;
		r++;
	}
	return ;
}

/*
Use wolfram alpha to condense/simplify calculations
*/