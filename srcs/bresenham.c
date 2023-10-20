/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:28 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/09 15:47:53 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/fdf.h"

void	draw_vertical(t_data *mlx, t_vec *start, t_vec *end, int color)
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

void	draw_b_l(t_data *mlx, t_vec *start, t_vec *end, t_fade *color)
{
	t_bresenham	low;

	low.deltax = (int)end->x - start->x;
	low.deltay = (int)end->y - start->y;
	low.variable_i = 1;
	if (low.deltay < 0)
	{
		low.variable_i = -1;
		low.deltay = -low.deltay;
	}
	low.diff = (2 * low.deltay) - low.deltax;
	low.y = (int)start->y;
	low.x = (int)start->x - 1;
	while (++low.x < end->x)
	{
		colorise(mlx, low.x, low.y, shader(color, start->x, end->x, low.x));
		if (low.diff > 0)
		{
			low.y = low.y + low.variable_i;
			low.diff = low.diff + (2 * (low.deltay - low.deltax));
		}
		else
			low.diff = low.diff + 2 * low.deltay;
	}
	return ;
}

void	draw_b_h(t_data *mlx, t_vec *start, t_vec *end, t_fade *color)
{
	t_bresenham	high;

	high.deltax = (int)(end->x - start->x);
	high.deltay = (int)(end->y - start->y);
	high.variable_i = 1;
	if (high.deltax < 0)
	{
		high.variable_i = -1;
		high.deltax = -1 * high.deltax;
	}
	high.y = (int)start->y - 1;
	high.x = (int)start->x;
	high.diff = (2 * high.deltax) - high.deltay;
	while (++high.y < end->y)
	{
		colorise(mlx, high.x, high.y, shader(color, start->y, end->y, high.y));
		if (high.diff > 0)
		{
			high.x = high.x + high.variable_i;
			high.diff = high.diff + (2 * (high.deltax - high.deltay));
		}
		else
			high.diff = high.diff + 2 * high.deltax;
	}
	return ;
}

void	swap_points(t_data *mlx, t_vec *start, t_vec *end, t_fade *color)
{
	if (start->x == end->x)
		draw_vertical(mlx, start, end, 0xFF0000);
	if (absolute(end->y - start->y) < absolute(end->x - start->x))
	{
		if (start->x > end->x)
			draw_b_l(mlx, end, start, color);
		else
			draw_b_l(mlx, start, end, color);
	}
	else
	{
		if (start->y > end->y)
			draw_b_h(mlx, end, start, color);
		else
			draw_b_h(mlx, start, end, color);
	}
	return ;
}
