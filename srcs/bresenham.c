/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/02 15:53:18 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vertical(t_data *mlx, vec *start, vec *end, int color)
{
	int	y;
	int	x;

	x = (int)start->x;
	y = (int)start->y;
	while (y >= end->y)
	{
		colorise(mlx, x, y, color);
		y--;
	}
	return ;
}

void	draw_bresenham_line_l(t_data *mlx, vec *start, vec *end, fade *color)
{
	bresenham	low;

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
		colorise(mlx, low.x, low.y, shader(color, start->x, end->x, low.x));
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

void	draw_bresenham_line_h(t_data *mlx, vec *start, vec *end, fade *color)
{
	bresenham	high;

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
		colorise(mlx, high.x, high.y, shader(color, start->y, end->y, high.y));
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

void	swap_points(t_data *mlx, vec *start, vec *end, fade *color)
{
	if (start->x == end->x)
		draw_vertical(mlx, start, end, 0xFF0000);
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
