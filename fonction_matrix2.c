/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_matrix2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:21:53 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 16:52:19 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	matrix_rotation_x(float angle)
{
	t_matrix4	matrix;

	matrix = matrix_identity();
	matrix.m[1][1] = cos(angle);
	matrix.m[2][1] = sin(angle);
	matrix.m[1][2] = -sin(angle);
	matrix.m[2][2] = cos(angle);
	return (matrix);
}

t_matrix4	matrix_rotation_y(float angle)
{
	t_matrix4	matrix;

	matrix = matrix_identity();
	matrix.m[0][0] = cos(angle);
	matrix.m[0][2] = sin(angle);
	matrix.m[2][0] = -sin(angle);
	matrix.m[2][2] = cos(angle);
	return (matrix);
}

t_matrix4	matrix_rotation_z(float angle)
{
	t_matrix4	matrix;

	matrix = matrix_identity();
	matrix.m[0][0] = cos(angle);
	matrix.m[0][1] = -sin(angle);
	matrix.m[1][0] = sin(angle);
	matrix.m[1][1] = cos(angle);
	return (matrix);
}
