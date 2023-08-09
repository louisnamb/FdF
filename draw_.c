/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/09 12:27:02 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_square(t_data *mlx, int bX, int bY, int fX, int fY, int color)
{
//	draw_bresenham_line(&mlx, 920, 540, 970, 590, 0xF00000);
//	draw_bresenham_line(&mlx, 990, 540, 1040, 590, 0xF00000);
//	draw_bresenham_line(&mlx, 920, 540, 990, 540, 0xF00000);
//	draw_bresenham_line(&mlx, 970, 565, 1040, 565, 0xF00000);
	draw_bresenham_line(mlx, bX, bY, fX, fY, 0xFFFFFF);//white
	draw_bresenham_line(mlx, bX + 70, bY, fX + 50, fY, 0x0000FF); //blue
	draw_bresenham_line(mlx, bX, bY, bX + 70, bY, 0xFFFF00); //yellow
	draw_bresenham_line(mlx, fX, bX + 25, fX + 70, bX, color);//red
	return ;
}
/*
Use mlx_pixel_put to avoid screen tears and seg faults. goal is to create a square
that you can use your wasd keys to move
*/

void		draw_vertical(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	int	y;
	int	x;
	if (startY < endY)
		return (draw_vertical(mlx, endX, endY, startX, startY, color));
	x = startX;
	y = startY;
	while (y >= endY)
	{
		mmlx_put_pix(mlx, x, y, color);
		y--;
	}
	return ;
}

void		draw_bresenham_line(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	int	x;
	int	y;
	int	deltaX;
	int deltaY;
	int	diff;

	if (startX == endX)
		return (draw_vertical(mlx, startX, startY, endX, endY, color));
	else if (startX > endX && startY >= endY)
		return (draw_bresenham_line(mlx, endX, endY, startX, startY, color));
	deltaX = endX - startX;
	deltaY = endY - startY;
	if (deltaY < 0)
		deltaY = deltaY * -1;
	y = startY;
	x = startX;
	diff = 2 * deltaY - deltaX;
	while (x < endX)
	{
		mmlx_put_pix(mlx, x, y, color);
		if (diff > 0)
		{
			y++;
			diff = diff - 2 * deltaX;
		}
		else
			diff = diff + 2 * deltaY;
		x++;
	}
	return ;
}

double	rotation_x(int x , int y, int z)
{
	return ((1 * x + 0 * x + x * 0) + (0 * y + y * cos(45) + y * -sin(45)) + (0 * z + z * sin(45) + z * cos(45)));
}

double	rotation_y(int x, int y, int z)
{
	return ((cos(45) * x + 0 * x + sin(45) * x) + (0 * y + 1 * y + 0 * y) + (-sin(45) * z + 0 * z + cos(45) * z));
}

void	draw_grid(t_data *mlx, details *map)
{
	int	columns;
	int	rows;
	int	default_x;
	int	y_coor;

	default_x = 660;
	y_coor = 330;
	rows = 0;
	while (rows <= map->rowcount)
	{
		columns = 0;
		while (columns <= map->columncount)
		{

			if (columns < map->columncount)
			//draw_bresenham_line(mlx, default_x, y_coor, default_x + 70, y_coor, 0xF00000);//red horizontal 
				draw_bresenham_line(mlx, 
				(int)rotation_x(default_x, y_coor, map->arr[rows][columns]), 
				(int)rotation_y(default_x, y_coor, map->arr[rows][columns]), 
				(int)rotation_x(default_x + 70, y_coor, map->arr[rows + 1][columns]), 
				(int)rotation_y(default_x, y_coor, map->arr[rows + 1][columns]), 0xF00000);//red horizontal 
			if (rows != 0)
				draw_bresenham_line(mlx, 
				(int)rotation_x(default_x, y_coor, map->arr[rows][columns]), 
				(int)rotation_y(default_x, y_coor, map->arr[rows][columns]),
				(int)rotation_x(default_x, y_coor, map->arr[rows][columns]),
				(int)rotation_y(default_x, y_coor - 70, map->arr[rows + 1][columns]), 0x0000FF);//blue vertical good
			columns++;
			default_x += 70;
		}
		default_x = 660;
		y_coor += 70;
		rows++;
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