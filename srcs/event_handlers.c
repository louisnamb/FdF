/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/23 13:08:42 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	end(t_data *hook)
{
	int	i;

	i = -1;
	mlx_destroy_window(hook->mlx, hook->win);
	mlx_destroy_image(hook->mlx, hook->img);
	while (++i < hook->map->r_cnt)
		free(hook->map->arr[i]);
	free(hook->fin->after);
	free(hook->fin->faded);
	free(hook->fin->before);
	free(hook->degrees);
	free(hook->map);
	free(hook->pts);
	free(hook);
	exit(0);
	return (0);
}

int	keys_pressed(int keycode, t_data *hook)
{
	if (keycode == 53)
		end(hook);
	else if (keycode == 13) //W
		hook->pts->move_y += -20;
	else if (keycode == 0) // A
		hook->pts->move_x += -20;
	else if (keycode == 1) // S
		hook->pts->move_y += 20;
	else if (keycode == 2) // D
		hook->pts->move_x += 20;
	draw_grid(hook);
	return (0);
}

int	key_hook(int keycode, t_data *hook)
{
	(void)keycode;
	(void)hook;
	return (0);
}

int	mouse_move(int button, int x, int y, t_data *hook)
{
	if ((x >= 0 && x <= 50) && (y >= 0 && y <= 50))
		printf("button clicked\n");
	(void)hook;
	(void)button;
	return (0);
}
