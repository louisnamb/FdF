/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:55:20 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/23 16:06:29 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initialiser(t_angles *degrees, t_pts_info *pts, t_fin *fin)
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
	if (!pts->mx && !pts->my)
	{
		fin->after = malloc(sizeof(t_vec));
		fin->before = malloc(sizeof(t_vec));
		fin->faded = malloc(sizeof(t_fade));
	}
	if (!fin->after || !fin->before || !fin->faded)
		return (1);
	return (0);
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
		return (r_xyz(&((t_vec){x_c + m->pts->add, y_c,
					add * m->map->arr[r][c + 1]}), *deg));
	else if (which == 3)
		return (r_xyz(&((t_vec){x_c, y_c - m->pts->add,
					add * m->map->arr[r - 1][c]}), *deg));
	else if (which == 4)
		return (r_xyz(&((t_vec){x_c, y_c,
					add * m->map->arr[r][m->map->c_cnt - 1]}), *deg));
	else
		return (r_xyz(&((t_vec){x_c, y_c - m->pts->add,
					add * m->map->arr[r - 1][m->map->c_cnt - 1]}), *deg));
}

t_fade	set(double z, double z_next, int x_c, int vert)
{
	return ((t_fade){z, z_next, x_c, vert});
}

void	everything(t_data *m, t_fin *fin, t_angles *degrees, int option)
{
	if (option == 1)
	{
		*fin->before = store(m, 1, degrees);
		*fin->after = store(m, 2, degrees);
		*fin->faded = set(m->map->arr[m->pts->r][m->pts->c],
				m->map->arr[m->pts->r][m->pts->c + 1], m->pts->x_c, 1);
	}
	else if (option == 2)
	{
		*fin->faded = set(m->map->arr[m->pts->r - 1][m->pts->c],
				m->map->arr[m->pts->r][m->pts->c], m->pts->x_c, 1);
		*fin->after = store(m, 3, degrees);
		swap_points(m, fin->before, fin->after, fin->faded);
	}
	else if (option == 3)
	{
		*fin->before = store(m, 4, degrees);
		*fin->after = store(m, 5, degrees);
		*fin->faded = set(m->map->arr[m->pts->r][m->map->c_cnt - 1],
				m->map->arr[m->pts->r - 1][m->map->c_cnt - 1], m->pts->x_c, 0);
		swap_points(m, fin->before, fin->after, fin->faded);
	}
}

void	draw_grid(t_data *m)
{
	ft_bzero(m->addr, m->width * m->h * (m->bbp / 8));
	if (initialiser(m->degrees, m->pts, m->fin))
		return ;
	while ((++m->pts->r) + 1 <= m->map->r_cnt)
	{
		m->pts->c = -1;
		while ((++m->pts->c) + 1 < m->map->c_cnt)
		{
			everything(m, m->fin, m->degrees, 1);
			if (m->pts->c <= m->map->c_cnt)
				swap_points(m, m->fin->before, m->fin->after, m->fin->faded);
			if (m->pts->r)
				everything(m, m->fin, m->degrees, 2);
			m->pts->x_c += m->pts->add;
		}
		if (m->pts->c + 1 == m->map->c_cnt && m->pts->r)
			everything(m, m->fin, m->degrees, 3);
		m->pts->x_c = 620;
		m->pts->y_c += m->pts->add;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	draw_menu(m);
}
