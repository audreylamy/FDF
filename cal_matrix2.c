/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrix2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:25 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 17:50:27 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector4	ft_cal_rotation_x(t_vector4 vector, t_matrix4 m_rotation_x)
{
	t_vector4	vec_rotation_x;

	vec_rotation_x.x1 = (vector.x1 * m_rotation_x.m[0][0]) +
	(vector.y1 * m_rotation_x.m[0][1]) + (vector.z1 * m_rotation_x.m[0][2])
	+ (vector.w1 * m_rotation_x.m[0][3]);
	vec_rotation_x.y1 = (vector.x1 * m_rotation_x.m[1][0]) +
	(vector.y1 * m_rotation_x.m[1][1]) + (vector.z1 * m_rotation_x.m[1][2])
	+ (vector.w1 * m_rotation_x.m[1][3]);
	vec_rotation_x.z1 = (vector.x1 * m_rotation_x.m[2][0]) +
	(vector.y1 * m_rotation_x.m[2][1]) + (vector.z1 * m_rotation_x.m[2][2])
	+ (vector.w1 * m_rotation_x.m[2][3]);
	vec_rotation_x.w1 = (vector.x1 * m_rotation_x.m[3][0]) +
	(vector.y1 * m_rotation_x.m[3][1]) + (vector.z1 * m_rotation_x.m[3][2])
	+ (vector.w1 * m_rotation_x.m[3][3]);
	return (vec_rotation_x);
}

t_vector4	ft_cal_rotation_y(t_vector4 vector, t_matrix4 m_rotation_y)
{
	t_vector4	vec_rotation_y;

	vec_rotation_y.x1 = (vector.x1 * m_rotation_y.m[0][0]) +
	(vector.y1 * m_rotation_y.m[0][1]) + (vector.z1 * m_rotation_y.m[0][2])
	+ (vector.w1 * m_rotation_y.m[0][3]);
	vec_rotation_y.y1 = (vector.x1 * m_rotation_y.m[1][0]) +
	(vector.y1 * m_rotation_y.m[1][1]) + (vector.z1 * m_rotation_y.m[1][2])
	+ (vector.w1 * m_rotation_y.m[1][3]);
	vec_rotation_y.z1 = (vector.x1 * m_rotation_y.m[2][0]) +
	(vector.y1 * m_rotation_y.m[2][1]) + (vector.z1 * m_rotation_y.m[2][2])
	+ (vector.w1 * m_rotation_y.m[2][3]);
	vec_rotation_y.w1 = (vector.x1 * m_rotation_y.m[3][0]) +
	(vector.y1 * m_rotation_y.m[3][1]) + (vector.z1 * m_rotation_y.m[3][2])
	+ (vector.w1 * m_rotation_y.m[3][3]);
	return (vec_rotation_y);
}

t_vector4	ft_cal_rotation_z(t_vector4 vector, t_matrix4 m_rotation_z)
{
	t_vector4	vec_rotation_z;

	vec_rotation_z.x1 = (vector.x1 * m_rotation_z.m[0][0]) +
	(vector.y1 * m_rotation_z.m[0][1]) + (vector.z1 * m_rotation_z.m[0][2])
	+ (vector.w1 * m_rotation_z.m[0][3]);
	vec_rotation_z.y1 = (vector.x1 * m_rotation_z.m[1][0]) +
	(vector.y1 * m_rotation_z.m[1][1]) + (vector.z1 * m_rotation_z.m[1][2])
	+ (vector.w1 * m_rotation_z.m[1][3]);
	vec_rotation_z.z1 = (vector.x1 * m_rotation_z.m[2][0]) +
	(vector.y1 * m_rotation_z.m[2][1]) + (vector.z1 * m_rotation_z.m[2][2])
	+ (vector.w1 * m_rotation_z.m[2][3]);
	vec_rotation_z.w1 = (vector.x1 * m_rotation_z.m[3][0]) +
	(vector.y1 * m_rotation_z.m[3][1]) + (vector.z1 * m_rotation_z.m[3][2])
	+ (vector.w1 * m_rotation_z.m[3][3]);
	return (vec_rotation_z);
}
