/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/14 10:33:13 by lnambaji         ###   ########.fr       */
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

int xbutton(t_data *hook)
{
	mlx_destroy_window(hook->mlx, hook->win);
	exit(0);
	return (0);
}

int	mouse_hook(int keycode, int button, int x, int y, t_data *hook)
{
	(void)x;
	(void)y;
	(void)button;
	(void)keycode;
	mlx_destroy_window(hook->mlx, hook->win);
	exit(0);
	return (0);
}

int		controls(int keycode, t_data *hook)
{
	int	x;
	int y;
	x = 935;
	y = 1035;
/*
Keycode for controls
	W: 13
	A: 0
	S: 1
	D: 2
*/
	// int z = 100;
	// draw_square(hook, x, y, z, 'x');
	// z = 200;
	// draw_square(hook, x, y, z, 'x');
	// y = 100;
	// draw_square(hook, x, y, z, 'y');
	// x = 1035;
	// draw_square(hook, x, y, z, 'y');
	printf("keycode: %d\n", keycode);
//	if (keycode == 13) // W (y goes up)
//	{
//		y++;
//		draw_square(hook, x, y, z, 'x');//, 'x');
//	}
//	else if (keycode == 0) // A (x goes down)
//		x++;
//	else if (keycode == 1) // S (y goes down)
//		y--;
//	else if (keycode == 2) // D (x goes up)
//		x++;
//	x = 935;
//	y = 1035;
//	z = 200;
//	draw_square(hook, x, y, z, 'x');
//	y = 100;
//	draw_square(hook, x, y, z, 'y');
//	x = 1035;
//	draw_square(hook, x, y, z, 'y');
	mlx_put_image_to_window(hook->mlx, hook->win, hook->img, x, y);
	return (0);
}
