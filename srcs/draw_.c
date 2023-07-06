/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/06 15:54:17 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_square(t_data *mlx, int x, int x_bound, int height)//, char which)
{
	int	thickness;
//	int x_original = x;
//	int y_original = x_bound;
	thickness = 5;

	while (thickness--)
	{
		while (x++ < x_bound)
			mlx_pixel_put(mlx->mlx, mlx->win, x, x_bound, 0x00FF0000);
	}
			//mmlx_put_pix(mlx, x, height, 0x00FF0000);
	while (thickness--)
	{
		while (x_bound++ < height)
			mlx_pixel_put(mlx->mlx, mlx->win, x, x_bound, 0x00FF0000);
	}
	//		mmlx_put_pix(mlx, x, x_bound, 0x00FF0000);
}
/*
Use mlx_pixel_put to avoid screen tears and seg faults. goal is to create a square
that you can use your wasd keys to move
*/
void	draw_point(t_data *mlx, int x, int y)
{
	mmlx_put_pix(mlx, x, y, 0x00FF0000);
}