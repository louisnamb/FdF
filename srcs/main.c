/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/06 15:53:36 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mmlx_put_pix(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bitsperpix / 8));
	*(unsigned int *)dst = colour;
}

int main(int argc, char **argv)
{
	t_data	mlx;
	details	display;

	if (argc == 2)
		display = read_map(argv[1]);
	else
	{
		write(1, "Error: Invalid arguments", 27);
		exit(1);
		return (1);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "fdf");
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bitsperpix, &mlx.linelen, &mlx.endian);
//	mmlx_put_pix(&mlx, 80, 8, 0x000000FF);
//	draw_point(mlx);
	draw_square(&mlx, 935, 1035, 100);//, 'x');
	draw_square(&mlx, 935, 1035, 200);//, 'x');
	draw_square(&mlx, 935, 100, 200);//, 'y');
	draw_square(&mlx, 1035, 100, 200);//, 'y');
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_mouse_hook(mlx.win, mouse_hook, mlx.mlx);
	mlx_hook(mlx.win, 17, 1L<<5, xbutton, &mlx.img);
	mlx_hook(mlx.win, 2, 1L<<0, esc, &mlx.img);
	mlx_key_hook(mlx.win, controls, &mlx.img);
//	mlx_loop_hook(mlx.mlx, render_next_frame, mlx)
	mlx_loop(mlx.mlx);
	return (0);
}