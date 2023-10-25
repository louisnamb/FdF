/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/25 14:31:23 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_menu(t_data *param)
{
	char	*menu;

	menu = "press W-A-S-D to move";
	mlx_string_put(param->mlx, param->win, 20, 115, 0xffffff, menu);
	menu = "press ESC or RED-X to exit";
	mlx_string_put(param->mlx, param->win, 20, 140, 0xffffff, menu);
	menu = "press R to reset the map";
	mlx_string_put(param->mlx, param->win, 20, 175, 0xffffff, menu);
	return ;
}

void	colorise(t_data *data, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->h)
		return ;
	dst = data->addr + (y * data->llen + x * (data->bbp / 8));
	*(unsigned int *)dst = colour;
}

void	initialisation(t_data *mlx, char *filepath)
{
	mlx->mlx = mlx_init();
	mlx->width = 1920;
	mlx->h = 1080;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->h, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->h);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bbp, &mlx->llen, &mlx->end);
	mlx->pts = malloc(sizeof(t_pts_info));
	mlx->map = malloc(sizeof(t_details));
	mlx->degrees = malloc(sizeof(t_angles));
	mlx->fin = malloc(sizeof(t_fin));
	if (!mlx->pts || !mlx->map || !mlx->degrees || !mlx->fin)
		return ;
	mlx->pts->mx = 0;
	mlx->pts->my = 0;
	mlx->map = read_map(filepath);
	mlx->min = find_min(mlx->map->arr, 1, mlx->map->r_cnt, mlx->map->c_cnt);
	mlx_hook(mlx->win, 17, 0, end, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, keys_pressed, mlx);
	return ;
}

int	main(int argc, char **argv)
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
	draw_menu(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
