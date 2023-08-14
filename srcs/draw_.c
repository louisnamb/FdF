/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/14 16:54:51 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Use mlx_pixel_put to avoid screen tears and seg faults. goal is to create a square
that you can use your wasd keys to move
*/

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
			y = y + yi;//= direction;
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

double	rx_x(int x , int y, int z)
{
	return (x * cos(45) + -sin(45) * y + 0 * z);
}

double	rx_y(int x, int y, int z)
{
	return (sin(45) * x + cos(45) * y + z);
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

	x_c = 1;
	y_c = 1;
	r = 0;
	while (r + 1 < map->rowcount)
	{
		c = 0;
		while (c + 1 < map->columncount)
		{
			if (c < map->columncount)
				swap_points(mlx, 
				(int)rx_x(x_c, y_c, map->arr[r][c]), 
				(int)rx_y(x_c, y_c, map->arr[r][c]), 
				(int)rx_x(x_c + 25, y_c, map->arr[r][c + 1]), 
				(int)rx_y(x_c + 25, y_c, map->arr[r][c + 1]), shader(map->arr[r][c + 1], 0xFFFFFF));//red horizontal 
			if (r)
				swap_points(mlx, 
				(int)rx_x(x_c, y_c, map->arr[r][c]), 
				(int)rx_y(x_c, y_c, map->arr[r][c]),
				(int)rx_x(x_c, y_c - 25, map->arr[r - 1][c]),
				(int)rx_y(x_c, y_c - 25, map->arr[r - 1][c]), shader(map->arr[r - 1][c], 0xFFFFFF));//blue vertical good
			c++;
			x_c += 25;
		}
		x_c = 15;
		y_c += 25;
		r++;
	}
	return ;
}

/* DELETE
int		encode_colors(double red, double green, double blue)
{
	int	color;

	color = 0;
	color |= (int)(red >> 16) * 255;
	color |= (int)(green >> 8) * 255;
	color |= (int)(blue * 255);
	return (color);
}

int		extract_colors(int color)
{
	double	red;
	double	green;
	double	blue;

	red = (color >> 16) & 255;
	green = (color >> 8) & 255;
	blue = (color & 255);
}
*/