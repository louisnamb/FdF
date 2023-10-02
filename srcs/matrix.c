/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:11:17 by lnambaji          #+#    #+#             */
/*   Updated: 2023/10/02 15:57:47 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	radians(float degrees)
{
	return ((degrees * M_PI) / 180.0);
}

vec	rz_xyz(vec mat, float theta)
{
	float	cos_;
	float	nsin_;
	vec		vec;

	cos_ = cos(radians(theta));
	nsin_ = -sin(radians(theta));
	vec.x = ((mat.x * cos_) + (nsin_ * mat.y) + (0.0 * mat.z));
	vec.y = (((nsin_ * -1) * mat.x) + (cos_ * mat.y) + (mat.z * 0.0));
	vec.z = ((mat.x * 0.0) + (mat.y * 0.0) + (mat.z * 1.0));
	return (vec);
}

vec	rx_xyz(vec mat, float theta)
{
	float	cos_;
	float	nsin_;
	vec		vec;

	cos_ = cos(radians(theta));
	nsin_ = -sin(radians(theta));
	vec.x = ((1.0 * mat.x) + (0.0 * mat.y) + (mat.z * 0));
	vec.y = ((0.0 * mat.x) + (cos_ * mat.y) + (nsin_ * mat.z));
	vec.z = ((0.0 * mat.x) + (mat.y * (nsin_ * -1)) + (mat.z * cos_));
	return (vec);
}

vec	ry_xyz(vec mat, float theta)
{
	float	cos_;
	float	nsin_;
	vec		vec;

	cos_ = cos(radians(theta));
	nsin_ = -sin(radians(theta));
	vec.x = ((cos_ * (mat.x)) + (0.0 * mat.y) + ((nsin_ * -1) * mat.z));
	vec.y = ((mat.x * 0.0) + (mat.y * 1.0) + (mat.z * 0.0));
	vec.z = ((nsin_ * mat.x) + (0.0 * mat.y) + (cos_ * mat.z));
	return (vec);
}

vec	r_xyz(vec *new, angles theta)
{
	vec	*matrix;

	matrix = new;
	*matrix = ry_xyz(*matrix, theta.y);
	*matrix = rz_xyz(*matrix, theta.z);
	*matrix = rx_xyz(*matrix, theta.x);
	return (*matrix);
}
