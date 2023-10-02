/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/02 15:44:52 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	end(t_data *hook)
{
	int	i;

	i = -1;
	mlx_destroy_window(hook->mlx, hook->win);
	while (++i < hook->map->r_cnt)
		free(hook->map->arr[i]);
	free(hook);
	exit(0);
	return (0);
}

int	keys_pressed(int keycode, t_data *hook)
{
	if (keycode == 53)
		end(hook);
	else if (keycode == 13)
		hook->pts->y_c -= 10;
	else if (keycode == 0)
		hook->pts->x_c -= 10;
	else if (keycode == 1)
		hook->pts->y_c += 10;
	else if (keycode == 2)
		hook->pts->x_c += 10;
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
