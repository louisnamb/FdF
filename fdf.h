/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:29 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/28 11:47:20 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct	window_info {
	void	*mlx;
	void	*img;
	char	*addr;
	int		bitsperpix;
	int		linelen;
	int		endian;
	void	*win;
}	t_data;

void	mlx_put_pix(t_data *data, int x, int y, int colour);

int	insidewin(int keycode, t_data *hook);

void	draw_square(t_data *mlx, int x, int x_bound, int height, char which);

int	xbutton(int button, int x, int y, t_data *hook);
