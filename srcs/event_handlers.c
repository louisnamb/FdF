/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/07/06 13:22:53 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc(int keycode, t_data *hook)
{
	if (keycode == 53)
	{
		mlx_destroy_window(hook->mlx, hook->win);
		exit(0);
	}
	(void)keycode;
	return (0);
}

int key_hook(int keycode, t_data *hook)
{
	(void)hook;
	printf("keycode: %d", keycode);
	return (0);
}

int	xbutton(int button, int x, int y, t_data *hook)
{
	if ((x >= 0 && x <= 50) && (y >= 0 && y <= 50))
		printf("button clicked\n");
	(void)hook;
	(void)button;
	return (0);
}

int mouse_move(int x, int y, t_data *hook)
{
	if ((x >= 7 && x <= 20) && (y >= -19 && y <= -5))//find which X11 mask it is
	{
		mlx_destroy_window(hook->mlx, hook->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int keycode, int button, int x, int y, t_data *hook)
{
	printf("keycode: %d button: %d x: %d y: %d", keycode, button, x, y);
//	printf("param:%d\n", (int)param);
	mlx_destroy_window(hook->mlx, hook->win);
	exit(0);
	return (0);
}
