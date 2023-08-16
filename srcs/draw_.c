/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/16 17:18:31 by lnambaji         ###   ########.fr       */
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

int	absolute(int result)
{
	if (result < 0)
		return (result * -1);
	return (result);
}

void	swap_points(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	if (startX == endX)
		draw_vertical(mlx, startX, startY, endX, endY, color);
	if (absolute(endY - startY) < absolute(endX - startX))
	{
		if (startX > endX)
			draw_bresenham_line_l(mlx, endX, endY, startX, startY,  color);
		else
			draw_bresenham_line_l(mlx, startX, startY, endX, endY, color);
	}
	else
	{
		if (startY > endY)
			draw_bresenham_line_h(mlx, endX, endY, startX, startY, color);
		else
			draw_bresenham_line_h(mlx, startX, startY,  endX, endY, color);
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
		deltaX = -1 * deltaX;
	}
	y = startY;
	x = startX;
	diff = (2 * deltaX) - deltaY;
	while (y < endY)
	{
		mmlx_put_pix(mlx, x, y, color);
		if (diff > 0)
		{
			x = x + xi;//= direction;
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
	matrix = rz_xyz(matrix, theta.z);
	matrix = ry_xyz(matrix, theta.y);
	matrix = rx_xyz(matrix, theta.x);
	return (matrix);
}

int	shader(double distance, int color)
{
	if (distance == 0.0)
		return (0xFFFFFF);
	return ((distance / 100.0) * (double)color);
}

void draw_circle(t_data *mlx)
{
	int offsetX = 300;
	int offsetY = 300;

	float angle = 0;
	vec one = {100, 0, 0};

	draw_bresenham_line_h(mlx, 0, 30, 0, 80, 0xFF00FF);
	draw_bresenham_line_h(mlx, 0 + offsetX, 0 + offsetY, -2 + offsetX, 13 + offsetY, 0xFF00FF);
	swap_points(mlx, 0 + offsetX, 0 + offsetY, -2 + offsetX, 13 + offsetY, 0xFF00FF);
	while (angle < 360)
	{
		vec first = rz_xyz(one, angle);
		vec second = rz_xyz(one, angle + 10);
		swap_points(mlx, first.x + offsetX, first.y + offsetY, second.x + offsetX, second.y + offsetY, 0x00FF00);
		mmlx_put_pix(mlx, first.x + offsetX, first.y + offsetY, 0xFF0000);
		mmlx_put_pix(mlx, first.x + 1 + offsetX, first.y + offsetY, 0xFF0000);
		mmlx_put_pix(mlx, first.x  + offsetX, 1 + first.y + offsetY, 0xFF0000);
		mmlx_put_pix(mlx, first.x + offsetX + 1, 1 + first.y + offsetY, 0xFF0000);

	//	mmlx_put_pix(mlx, second.x + offsetX - 10, first.y + offsetY - 10, 0x00FF00);
//		mmlx_put_pix(mlx, second.x + 1 + offsetX - 10, first.y + offsetY - 10, 0x00FF00);
	//	mmlx_put_pix(mlx, second.x + offsetX - 10, + 1 + first.y + offsetY - 10, 0x00FF00);
	//	mmlx_put_pix(mlx, second.x + 1 +offsetX - 10, + 1 +first.y + offsetY - 10, 0x00FF00);
		angle += 10;
	}
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
	x_c = 450;
	degrees = (angles){33, 0, 33};
	y_c = 0;
	r = 0;
	
//	before = r_xyz((vec){x_c, y_c, map->arr[r][0]}, degrees);
//	future = before;
	while (r + 1 < map->rowcount)
	{
		c = 0;
		while (c + 1 < map->columncount)
		{
			before = r_xyz((vec){x_c, y_c, map->arr[r][c]}, degrees);
			past = r_xyz((vec){x_c + 50, y_c, map->arr[r][c + 1]}, degrees);
			if (c < map->columncount)
				swap_points(mlx, before.x, before.y, past.x, past.y, 
				shader(map->arr[r][c + 1], 0xFFFFFF));//red horizontal 
			if (r)
			{
				after = r_xyz((vec){x_c, y_c - 50, map->arr[r - 1][c]}, degrees);
				swap_points(mlx, before.x, before.y, after.x, after.y,
				shader(map->arr[r - 1][c], 0xFFFFFF));//blue vertical good
			}
			c++;
		//	before = past;
			//c = (c + 1) % map->columncount;
			x_c += 50;
		}
		x_c = 450;
		y_c += 50;
		r++;
	}
	return ;
}

/*
Use wolfram alpha to condense/simplify calculations
*/