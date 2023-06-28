/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/28 11:55:39 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_put_pix(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bitsperpix / 8));//iterates over every line
	//iterate over each pixel 0 + 4 * (desiredpix)
	*(unsigned int *)dst = colour;
}

int main(void)
{
	t_data	mlx;
	int		i;
	int		j;

	i = 935;
	j = 5;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "fdf");

	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bitsperpix, &mlx.linelen, &mlx.endian);
	draw_square(&mlx, 935, 1035, 100, 'x');
	draw_square(&mlx, 935, 1035, 200, 'x');
	draw_square(&mlx, 935, 100, 200, 'y');
	draw_square(&mlx, 1035, 100, 200, 'y');
	mlx_put_pix(&mlx, 80, 8, 0x000000FF);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, insidewin, &mlx);
	mlx_hook(mlx.win, 4, 1L<<2, xbutton, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
/*
-	Draw a line
-	Get ESC button to quit program
*/