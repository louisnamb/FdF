/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/27 16:18:09 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct	window_info {
	void	*img;
	char	*addr;
	int		bitsperpix;
	int		linelen;
	int		endian;
}				t_data;

void	mlx_put_pix(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bitsperpix / 8));//iterates over every line
	//iterate over each pixel 0 + 4 * (desiredpix)
	*(unsigned int *)dst = colour;
}

int main(void)
{
	void	*mlx_ptr;
	t_data	img;
	int		offset;
	void	*mlx_win;
	int		x;

	x = 540;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bitsperpix, &img.linelen, &img.endian);
	mlx_put_pix(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 960, x);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 960, 600);
	mlx_loop(mlx_ptr);
	return (0);
}