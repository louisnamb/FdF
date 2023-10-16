/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/16 14:49:59 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialiser(t_angles *degrees, t_pts_info *pts)
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

t_vec	store(t_data *m, int which, t_angles *deg)
{
	int	x_c;
	int	add;
	int	y_c;
	int	r;
	int	c;

	x_c = m->pts->x_c;
	y_c = m->pts->y_c;
	add = m->pts->line_add;
	r = m->pts->r;
	c = m->pts->c;
	if (which == 1)
		return (r_xyz(&((t_vec){x_c, y_c, add * m->map->arr[r][c]}), *deg));
	else if (which == 2)
		return (r_xyz(&((t_vec){x_c + m->pts->add, y_c, add * m->map->arr[r][c + 1]}), *deg));
	else if (which == 3)
		return (r_xyz(&((t_vec){x_c, y_c - m->pts->add, add * m->map->arr[r - 1][c]}), *deg));
	else if (which == 4)
		return (r_xyz(&((t_vec){x_c, y_c, add * m->map->arr[r][m->map->c_cnt - 1]}), *deg));
	else
		return (r_xyz(&((t_vec){x_c, y_c - m->pts->add,
					add * m->map->arr[r - 1][m->map->c_cnt - 1]}), *deg));
}

t_fade	set(double z, double z_next, int x_c, int vert)
{
	return ((t_fade){z, z_next, x_c, vert});
}

void	everything(t_data *m, t_fin *everything, t_angles *degrees, int option)
{
	if (option == 1)
	{
		*everything->after = store(m, 1, degrees);
		*everything->before = store(m, 2, degrees);
		*everything->faded = set(m->map->arr[m->pts->r][m->pts->c],
		m->map->arr[m->pts->r][m->pts->c + 1], m->pts->x_c, 1);
	}
	else if (option == 2)
	{
		*everything->faded = set(m->map->arr[m->pts->r - 1][m->pts->c],
		m->map->arr[m->pts->r][m->pts->c], m->pts->x_c, 1);
		*everything->after = store(m, 3, degrees);
		swap_points(m, everything->before, everything->after, everything->faded);
	}
	else if (option == 3)
	{
		*everything->before = store(m, 4, degrees);
		*everything->after = store(m, 5, degrees);
		*everything->faded = set(m->map->arr[m->pts->r][m->map->c_cnt - 1],
		m->map->arr[m->pts->r - 1][m->map->c_cnt - 1], m->pts->x_c, 0);
		swap_points(m, everything->before, everything->after, everything->faded);
	}
}

void	draw_grid(t_data *m)
{
	t_fin		**fin;
	t_angles	*degrees;

	fin
	degrees = malloc(sizeof(t_angles));
	if (!m->pts || !degrees)
		return ;
	initialiser(degrees, m->pts);
	while ((++m->pts->r) + 1 <= m->map->r_cnt)
	{
		m->pts->c = -1;
		while ((++m->pts->c) + 1 < m->map->c_cnt)
		{
			everything(m, *fin, degrees, 1);
			if (m->pts->c <= m->map->c_cnt)
				swap_points(m, (*fin)->before, (*fin)->after, (*fin)->faded);
			if (m->pts->r)
				everything(m, *fin, degrees, 2);
			m->pts->x_c += m->pts->add;
		}
		if (m->pts->c + 1 == m->map->c_cnt && m->pts->r && m->pts->r < m->map->r_cnt)
			everything(m, *fin, degrees, 3);
		m->pts->x_c = 620;
		m->pts->y_c += m->pts->add;
	}
}
