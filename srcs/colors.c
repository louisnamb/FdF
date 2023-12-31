/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:15:33 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/25 14:40:58 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	absolute(int result)
{
	if (result < 0)
		return (result * -1);
	return (result);
}

static int	get_tint(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double	find_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	if (current == start)
		return (0.0);
	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	add_colour(int start, int end, double percentage)
{
	int	red;
	int	green;
	int	blue;

	red = get_tint((start >> 16) & 0xFF, (end >> 16) & 0xFF, percentage);
	green = get_tint((start >> 8) & 0xFF, (end >> 8) & 0xFF, percentage);
	blue = get_tint(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	shader(t_data *m, int start, int end, int curr)
{
	double	greater;
	int		max;
	int		low;

	max = 0xFF0000;
	low = 0xFFFFFF;
	greater = m->min;
	if (m->fin->faded->curr_z > m->fin->faded->next_z && m->fin->faded->vert)
	{
		greater = m->fin->faded->curr_z;
		return (add_colour(max, low, find_percent(start, end, curr)));
	}
	else
		greater = m->fin->faded->next_z;
	if (greater == m->min)
		return (low);
	else if (m->fin->faded->curr_z == m->fin->faded->next_z)
		return (max);
	else
		return (add_colour(low, max, find_percent(start, end, curr)));
}
