/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/29 15:36:08 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mmlx_put_pix(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bitsperpix / 8));
	/*
pixels are just an array of pixel addresses. to index pixels on specific lines you use the above notation.
y is the line (row) of the pixel. y * data->linelen is the linelen-th pixel
x is the left most pixel. one pixel requires 4 bytes in memory
	*/
	//iterates over every line
	//iterate over each pixel 0 + 4 * (desiredpix)
	*(unsigned int *)dst = colour;
}

int main(int argc, char **argv)
{
//	t_data	mlx;
	int		i;
	int		j;

	i = 935;
	j = 5;
	printf("expecting argv: '%s'\n", argv[1]);
	if (argc == 2)
	{
		read_map(argv[1]);
	}
	else
		write(1, "Error: Invalid arguments", 27);
	return (1);
	// mlx.mlx = mlx_init();
	// mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "fdf");
	// mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	// mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bitsperpix, &mlx.linelen, &mlx.endian);
	// draw_square(&mlx, 935, 1035, 100, 'x');
	// draw_square(&mlx, 935, 1035, 200, 'x');
	// draw_square(&mlx, 935, 100, 200, 'y');
	// draw_square(&mlx, 1035, 100, 200, 'y');
	// mmlx_put_pix(&mlx, 80, 8, 0x000000FF);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	// mlx_hook(mlx.win, 2, 1L<<0, insidewin, &mlx);
	// mlx_hook(mlx.win, 4, 1L<<2, xbutton, &mlx);
	// mlx_loop(mlx.mlx);
//	return (0);
}
/*
-	Draw a line
-	Get ESC button to quit program
*/
