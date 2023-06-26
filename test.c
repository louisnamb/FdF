/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/06/26 14:39:05 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minilibx/mlx.h"
#include "minilibx/mlx.h"
#include "minilibx_macos/mlx.h"
#include "minilibx_mms_20191025_beta/mlx.h"
#include "minilibx-linux/mlx.h"
//#include <mlx.h>

int main(void)
{
    void *mlx_ptr;
    void *mlx_new_window;

    mlx_ptr = mlx_init();
    mlx_window_identifier = mlx_new_window(mlx_ptr, 600, 500, "fdf");
    mlx_loop(mlx_ptr);
    if (!mlx_ptr || !mlx_new_window)
        return (1);
    return (0);
}