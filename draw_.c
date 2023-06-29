/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/29 12:41:24 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_square(t_data *mlx, int x, int x_bound, int height, char which)
{
	int	thickness;

	thickness = 5;
	if (which == 'x')
	{
		while (thickness--)
		{
			while (x++ < x_bound)
				mmlx_put_pix(mlx, x, height, 0x00FF0000);
		}
	}
	else
	{
		while (thickness--)
		{
			while (x_bound++ < height)
				mmlx_put_pix(mlx, x, x_bound, 0x00FF0000);
		}
	}
}