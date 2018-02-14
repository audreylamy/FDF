/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_matrix1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:47:27 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 19:09:41 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector4	create_vector4(int x, int y, int z, int w)
{
	t_vector4	new_vector4;

	new_vector4.x1 = x;
	new_vector4.y1 = y;
	new_vector4.z1 = z;
	new_vector4.w1 = w;
	return (new_vector4);
}

t_matrix4	matrix_identity(void)
{
	t_matrix4	matrix;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((i == 0 && j == 0) || (i == 1 && j == 1) ||
			(i == 2 && j == 2) || (i == 3 && j == 3))
				matrix.m[i][j] = 1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

t_matrix4	matrix_translation(t_vector4 offset)
{
	t_matrix4	matrix;

	matrix = matrix_identity();
	matrix.m[0][3] = offset.x1;
	matrix.m[1][3] = offset.y1;
	matrix.m[2][3] = offset.z1;
	matrix.m[3][3] = offset.w1;
	return (matrix);
}

t_matrix4	matrix_homothetie(t_vector4 homo)
{
	t_matrix4	matrix;

	matrix = matrix_identity();
	matrix.m[0][0] = homo.x1;
	matrix.m[1][1] = homo.y1;
	matrix.m[2][2] = homo.z1;
	matrix.m[3][3] = homo.w1;
	return (matrix);
}

t_matrix4	matrix_proj(float angle, float ratio, float near, float far)
{
	t_matrix4	matrix;

	matrix = matrix_identity();
	matrix.m[0][0] = (1 / tan(angle / 2)) / ratio;
	matrix.m[1][1] = (1 / tan(angle / 2));
	matrix.m[2][2] = (-far - near) / (near - far);
	matrix.m[2][3] = (2 * far * near) / (near - far);
	matrix.m[3][2] = 1;
	return (matrix);
}
