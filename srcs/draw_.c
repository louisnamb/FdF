/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/02 16:35:42 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialiser(angles *degrees, pts_info *pts)
{
	pts->x_c = 620;
	pts->y_c = 100;
	pts->line_add = 5;
	pts->r = -1;
	pts->c = -1;
	pts->add = 50.0;
	degrees->x = 25.0;
	degrees->y = 15.0;
	degrees->z = 5.0;
	return ;
}

vec	store(t_data *m, int which, angles *degrees)
{
	int	x_c;
	int	add;
	int	y_c;

	x_c = m->pts->x_c;
	y_c = m->pts->y_c;
	add = m->pts->line_add
	if (which == 1)
		return (r_xyz(&((vec){m->pts->x_c, m->pts->y_c, m->pts->line_add * m->map->arr[m->pts->r][m->pts->c]}), *degrees));
	else if (which == 2)
		return (r_xyz(&((vec){m->pts->x_c + m->pts->add, m->pts->y_c, m->pts->line_add * m->map->arr[m->pts->r][m->pts->c + 1]}), *degrees));
	else if (which == 3)
		return (r_xyz(&((vec){m->pts->x_c, m->pts->y_c - m->pts->add, m->pts->line_add * m->map->arr[m->pts->r - 1][m->pts->c]}), *degrees));
	else if (which == 4)
		return (r_xyz(&((vec){m->pts->x_c, m->pts->y_c, m->pts->line_add * m->map->arr[m->pts->r][m->map->c_cnt - 1]}), *degrees));
	else if (which == 5)
		return (r_xyz(&((vec){m->pts->x_c, m->pts->y_c - m->pts->add, m->pts->line_add * m->map->arr[m->pts->r - 1][m->map->c_cnt - 1]}), *degrees));
}

void	draw_grid(t_data *m)
{
	vec			before;
	vec			after;
	angles		*degrees;

	degrees = malloc(sizeof(angles));
	if (!m->pts || !degrees)
		return ;
	initialiser(degrees, m->pts);
	while ((++m->pts->r) + 1 <= m->map->r_cnt)
	{
		m->pts->c = -1;
		while ((++m->pts->c) + 1 < m->map->c_cnt)
		{
			before = store(m, 1, degrees);
			after = store(m, 2, degrees);
			if (m->pts->c <= m->map->c_cnt)
				swap_points(m, &before, &after, &(fade){m->map->arr[m->pts->r][m->pts->c], 
				m->map->arr[m->pts->r][m->pts->c + 1], m->pts->x_c, 1});
			if (m->pts->r)
			{
				after = store(m, 3, degrees);
				swap_points(m, &before, &after, &(fade){m->map->arr[m->pts->r - 1][m->pts->c], 
				m->map->arr[m->pts->r][m->pts->c], m->pts->x_c, 1});
			}
			m->pts->x_c += m->pts->add;
		}
		if (m->pts->c + 1 == m->map->c_cnt && m->pts->r && m->pts->r < m->map->r_cnt)
		{
			before = store(m, 4, degrees);
			after = store(m, 5, degrees);
			swap_points(m, &before, &after, &(fade){m->map->arr[m->pts->r][m->map->c_cnt - 1], 
			m->map->arr[m->pts->r - 1][m->map->c_cnt - 1], m->pts->x_c, 0});
		}
		m->pts->x_c = 620;
		m->pts->y_c += m->pts->add;
	}
	return ;
}