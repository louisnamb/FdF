/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:15:33 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/02 13:50:28 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	shader(fade *color, int start, int end, int curr)
{
	double	greater;
	int		max;
	int		low;
	int		tmp;

	max = 0xFF0000;
	low = 0x9900FF;
	greater = 0.0;
	if (color->curr_z > color->next_z && color->vert)
	{
		greater = color->curr_z;
		tmp = max;
		max = low;
		low = tmp;
	}
	else
		greater = color->next_z;
	if (greater == 0.0)
		return (low);
	else if (color->curr_z == color->next_z)
		return (max);
	else
		return (add_colour(low, max, find_percent(start, end, curr)));
}
