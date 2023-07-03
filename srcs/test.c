/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/28 11:24:50 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	window_info {
	void	*mlx;
	void	*img;
	char	*addr;
	int		bitsperpix;
	int		linelen;
	int		endian;
	void	*win;
}	t_data;

void	mlx_put_pix(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bitsperpix / 8));//iterates over every line
	//iterate over each pixel 0 + 4 * (desiredpix)
	*(unsigned int *)dst = colour;
}

