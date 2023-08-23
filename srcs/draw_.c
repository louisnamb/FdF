/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/23 17:07:26 by lnambaji         ###   ########.fr       */
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

// int	shader(gradient color, int start, int end)
// {
// 	(void)curr_x;
// 	if (color->curr_z == 0.0 && color->prev_z == 0.0)
// 		return (0xFFFFFF);
// 	else if (color->curr_z == 0.0 && color->prev_z != 0.0)
// 		return ((color->prev_z / 100.0) * (double)color);
// //	return ((x_c - 540 / 540) * (double)color); put this function in the draw_bresenham_line
// 		return ((color->curr_z / 100.0) * (double)color);
// }

int	shader(gradient *color, int curr, int end)
{
	double		greater;
	int			answer;
	static int	last;

	last = end;
	greater = 0.0;
	if (color->curr_z > color->prev_z)
		greater = color->curr_z;
	else
		greater = color->prev_z;
	if (!greater)
		return (0xFFFFFF);
	else if (color->curr_z == color->prev_z)
		return ((greater / 100.0) * ((double)color->colour));
	else if (((last - curr) % last) == 50)// || ((last - curr) % last) == 0)
	{
	//	answer = (((end - curr) / greater) * (double)color->colour);
		answer = (((double)curr / (double)(last - 1)) * (greater / 100.0));// * (double)color->colour);
		last = end;
		return (answer);
	}
	else
		return ((double)((last - ((last - curr) % last)) / (double)(end - 1)) * (greater / 100.0) * (double)color->colour);	
}

// int interpolate(rgb begin, rgb max)
// {
//     // Calculate the relative position of 'curr' between the start and end positions.
//     double t = (double)curr / (double)(end - 1);
    
//     // Ensure 't' is within the [0, 1] range.
//     t = fmax(0.0, fmin(1.0, t));
    
//     // Linearly interpolate the color components (R, G, B) based on 't'.
//     int red = (int)((1.0 - t) * begin->r + t * max->r);
//     int green = (int)((1.0 - t) * begin->g + t * max->g);
//     int blue = (int)((1.0 - t) * begin->b + t * max->b);
    
//     // Combine the interpolated color components into a single RGB color.
//     int interpolatedColor = (red << 16) | (green << 8) | blue;
    
//     return interpolatedColor;
// }

// int	fdgfg(gradient *color, int curr, int end)
// {
// 	double			greater;
// 	rgb				max;
// 	rgb				begin;
// 	int				max_colour;

// 	if (color->curr_z > color->prev_z)
// 		greater = color->curr_z;
// 	else
// 		greater = color->prev_z;
// 	max_colour = 0x800080;
// 	begin.r = (color->colour >> 16) & 0xFF;
// 	begin.g = (color->colour >> 8) & 0xFF;
// 	begin.b = (color->colour) & 0xFF;
// //	begin.a = (color->colour) & 0xFF;
// 	max.r = (max_colour >> 16) & 0xFF;
// 	max.g = (max_colour >> 8) & 0xFF; 
// 	max.b = (max_colour) & 0xFF;
// //	max.a = (max_colour) & 0xFF;
// 	if (!greater)
// 		return (0xFFFFFF);
// 	else if (color->curr_z == color->prev_z)
// 		return ((greater / 100.0) * (double)color->colour);
// 	else
// 		return (((end - start) / (greater)) * (double)color->colour);
// 	//	return (interpolate(begin, max));
// 		// return ((int)(begin.r + (max.r - begin.r) * (float)(curr / end)) |
// 		// (int)(begin.g + (max.g - begin.g) * (float)(curr / end)) |
// 		// (int)(begin.b + (max.b - begin.b) * (float)(curr / end))) | (max_colour));
// 	//	(begin.a + (max.a - begin.a) * (curr / end)) * (max_colour));
// }

void		draw_bresenham_line_l(t_data *mlx, vec *start, vec *end, gradient *color)
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
		mmlx_put_pix(mlx, x, y, shader(color, x, end->x));
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

void		draw_bresenham_line_h(t_data *mlx, vec *start, vec *end, gradient *color)
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
		mmlx_put_pix(mlx, x, y, shader(color, y, end->y));
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
				swap_points(mlx, &before, &past, &(gradient){map->arr[r][c], map->arr[r][c + 1], x_c, 0xFF0000});//red horizontal 
			if (r)
			{
				after = r_xyz((vec){x_c, y_c - 50, map->arr[r - 1][c]}, degrees);
				swap_points(mlx, &before, &after, &(gradient){map->arr[r][c], map->arr[r - 1][c], x_c, 0xFF0000});//blue vertical good
			}
			c++;
			x_c += 50;
		}
		if (c + 1 == map->columncount && r && r < map->rowcount)
		{
			before = r_xyz((vec){x_c, y_c, map->arr[r][map->columncount - 1]}, degrees);
			after = r_xyz((vec){x_c, y_c - 50, map->arr[r - 1][map->columncount - 1]}, degrees);
			swap_points(mlx, &before, &after, &(gradient){map->arr[r][map->columncount - 1], map->arr[r - 1][map->columncount - 1], x_c, 0xFF0000});//red horizontal 
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