/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:11:17 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/09 15:55:06 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	radians(float degrees)
{
	return ((degrees * M_PI) / 180.0);
}

t_vec	rz_xyz(t_vec mat, float theta)
{
	float	cos_;
	float	nsin_;
	t_vec	t_vec;

	cos_ = cos(radians(theta));
	nsin_ = -sin(radians(theta));
	t_vec.x = ((mat.x * cos_) + (nsin_ * mat.y) + (0.0 * mat.z));
	t_vec.y = (((nsin_ * -1) * mat.x) + (cos_ * mat.y) + (mat.z * 0.0));
	t_vec.z = ((mat.x * 0.0) + (mat.y * 0.0) + (mat.z * 1.0));
	return (t_vec);
}

t_vec	rx_xyz(t_vec mat, float theta)
{
	float	cos_;
	float	nsin_;
	t_vec	t_vec;

	cos_ = cos(radians(theta));
	nsin_ = -sin(radians(theta));
	t_vec.x = ((1.0 * mat.x) + (0.0 * mat.y) + (mat.z * 0));
	t_vec.y = ((0.0 * mat.x) + (cos_ * mat.y) + (nsin_ * mat.z));
	t_vec.z = ((0.0 * mat.x) + (mat.y * (nsin_ * -1)) + (mat.z * cos_));
	return (t_vec);
}

t_vec	ry_xyz(t_vec mat, float theta)
{
	float	cos_;
	float	nsin_;
	t_vec	t_vec;

	cos_ = cos(radians(theta));
	nsin_ = -sin(radians(theta));
	t_vec.x = ((cos_ * (mat.x)) + (0.0 * mat.y) + ((nsin_ * -1) * mat.z));
	t_vec.y = ((mat.x * 0.0) + (mat.y * 1.0) + (mat.z * 0.0));
	t_vec.z = ((nsin_ * mat.x) + (0.0 * mat.y) + (cos_ * mat.z));
	return (t_vec);
}

t_vec	r_xyz(t_vec *new, t_angles theta)
{
	t_vec	*matrix;

	matrix = new;
	*matrix = ry_xyz(*matrix, theta.y);
	*matrix = rz_xyz(*matrix, theta.z);
	*matrix = rx_xyz(*matrix, theta.x);
	return (*matrix);
}
