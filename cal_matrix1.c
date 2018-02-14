/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrix1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:46:30 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 17:50:15 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector4	ft_cal_translation(t_vector4 vector2, t_matrix4 m_trans)
{
	t_vector4	vec_translation;

	vec_translation.x1 = (vector2.x1 * m_trans.m[0][0]) +
	(vector2.y1 * m_trans.m[0][1]) + (vector2.z1 * m_trans.m[0][2])
	+ (vector2.w1 * m_trans.m[0][3]);
	vec_translation.y1 = (vector2.x1 * m_trans.m[1][0]) +
	(vector2.y1 * m_trans.m[1][1]) + (vector2.z1 * m_trans.m[1][2])
	+ (vector2.w1 * m_trans.m[1][3]);
	vec_translation.z1 = (vector2.x1 * m_trans.m[2][0]) +
	(vector2.y1 * m_trans.m[2][1]) + (vector2.z1 * m_trans.m[2][2])
	+ (vector2.w1 * m_trans.m[2][3]);
	vec_translation.w1 = (vector2.x1 * m_trans.m[3][0]) +
	(vector2.y1 * m_trans.m[3][1]) + (vector2.z1 * m_trans.m[3][2])
	+ (vector2.w1 * m_trans.m[3][3]);
	return (vec_translation);
}

t_vector4	ft_cal_homothetie(t_vector4 vector, t_matrix4 m_homothetie)
{
	t_vector4	vec_homothetie;

	vec_homothetie.x1 = (vector.x1 * m_homothetie.m[0][0]) +
	(vector.y1 * m_homothetie.m[0][1]) + (vector.z1 * m_homothetie.m[0][2])
	+ (vector.w1 * m_homothetie.m[0][3]);
	vec_homothetie.y1 = (vector.x1 * m_homothetie.m[1][0]) +
	(vector.y1 * m_homothetie.m[1][1]) + (vector.z1 * m_homothetie.m[1][2])
	+ (vector.w1 * m_homothetie.m[1][3]);
	vec_homothetie.z1 = (vector.x1 * m_homothetie.m[2][0]) +
	(vector.y1 * m_homothetie.m[2][1]) + (vector.z1 * m_homothetie.m[2][2])
	+ (vector.w1 * m_homothetie.m[2][3]);
	vec_homothetie.w1 = (vector.x1 * m_homothetie.m[3][0]) +
	(vector.y1 * m_homothetie.m[3][1]) + (vector.z1 * m_homothetie.m[3][2])
	+ (vector.w1 * m_homothetie.m[3][3]);
	return (vec_homothetie);
}

t_vector4	ft_cal_projection(t_vector4 vector, t_matrix4 m_projection)
{
	t_vector4	vec_projection;

	vec_projection.x1 = (vector.x1 * m_projection.m[0][0]) +
	(vector.y1 * m_projection.m[0][1]) + (vector.z1 * m_projection.m[0][2])
	+ (vector.w1 * m_projection.m[0][3]);
	vec_projection.y1 = (vector.x1 * m_projection.m[1][0]) +
	(vector.y1 * m_projection.m[1][1]) + (vector.z1 * m_projection.m[1][2])
	+ (vector.w1 * m_projection.m[1][3]);
	vec_projection.z1 = (vector.x1 * m_projection.m[2][0]) +
	(vector.y1 * m_projection.m[2][1]) + (vector.z1 * m_projection.m[2][2])
	+ (vector.w1 * m_projection.m[2][3]);
	vec_projection.w1 = (vector.x1 * m_projection.m[3][0]) +
	(vector.y1 * m_projection.m[3][1]) + (vector.z1 * m_projection.m[3][2])
	+ (vector.w1 * m_projection.m[3][3]);
	return (vec_projection);
}
