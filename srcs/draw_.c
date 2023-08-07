/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/07 15:45:42 by lnambaji         ###   ########.fr       */
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

void		draw_bresenham_line(t_data *mlx, int startX, int startY, int endX, int endY, int color)
{
	int	x;
	int	y;
	int	deltaX;
	int deltaY;
	int	diff;

	if (startX > endX && startY > endY)
		draw_bresenham_line(mlx, endX, endY, startX, startY, color);
	deltaX = endX - startX;
	deltaY = endY - startY;
	height = 1;
	if (deltaY < 0)
	{
		height = -1;
		deltaY = deltaY * -1;
	}
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