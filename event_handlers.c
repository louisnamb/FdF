/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:04 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/28 11:48:43 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	insidewin(int keycode, t_data *hook)
{
	mlx_destroy_window(hook->mlx, hook->win);
	printf("keycode: %d\n", keycode);
	(void)keycode;
	exit(0);
	return (0);
}

int	xbutton(int button, int x, int y, t_data *hook)
{
	if ((x >= 0 && x <= 50) && (y >= 0 && y <= 50))// <= 1920) && (y >= 0 && y <= 1080))
		printf("button clicked\n");
	(void)hook;
	(void)button;
	return (0);
}