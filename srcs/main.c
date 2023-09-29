/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/09/29 15:50:32 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_color(t_data *data, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->linelen + x * (data->bitsperpix / 8));
	*(unsigned int *)dst = colour;
}

void	adfgearg(t_data *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->addr;
	buffer[(y * mlx->linelen / 4) + x] = color;
}

void	initialisation(t_data *mlx, char *filepath)
{
	mlx->mlx = mlx_init();
	mlx->width = 1920;
	mlx->height = 1080;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bitsperpix, &mlx->linelen, &mlx->endian);
	mlx->pts = malloc(sizeof(pts_info));
	mlx->map = malloc(sizeof(details));
	if (!mlx->pts || !mlx->map)
		return ;
	mlx->map = read_map(filepath);
	mlx_hook(mlx->win, 17, 0, xbutton, mlx);
	mlx_hook(mlx->win, 2, 1L<<0, keys_pressed, mlx);
	return ;
}

int main(int argc, char **argv)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx || argc != 2)
	{
		write(1, "Error: Invalid arguments\n", 25);
		exit(1);
		return (1);
	}
	else
		initialisation(mlx, argv[1]);
	draw_grid(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}