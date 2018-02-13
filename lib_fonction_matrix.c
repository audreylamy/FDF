/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fonction_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:47:27 by alamy             #+#    #+#             */
/*   Updated: 2018/02/13 17:25:33 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4  matrix_translation(t_vecteur4 offset)
{
	t_matrix4 matrix;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 0 && j == 3)
				matrix.m[i][j] = offset.x1;
			else if (i == 1 && j == 3)
				matrix.m[i][j] = offset.y1;
			else if (i == 2 && j == 3)
				matrix.m[i][j] = offset.z1;
			else if (i == 3 && j == 3)
				matrix.m[i][j] = offset.w1;
			else if ((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 2))
				matrix.m[i][j] = 1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_matrix4  matrix_rotationX(float angle)
{
	t_matrix4 matrix;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 1 && j == 1)
				matrix.m[i][j] = cos(angle);
			else if (i == 2 && j == 1)
				matrix.m[i][j] = sin(angle);
			else if (i == 1 && j == 2)
				matrix.m[i][j] = -sin(angle);
			else if (i == 2 && j == 2)
				matrix.m[i][j] = cos(angle);
			else if ((i == 0 && j == 0) || (i == 3 && j == 3))
				matrix.m[i][j] = 1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_matrix4  matrix_rotationY(float angle)
{
	t_matrix4 matrix;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 0 && j == 0)
				matrix.m[i][j] = cos(angle);
			else if (i == 0 && j == 2)
				matrix.m[i][j] = sin(angle);
			else if (i == 2 && j == 0)
				matrix.m[i][j] = -sin(angle);
			else if (i == 2 && j == 2)
				matrix.m[i][j] = cos(angle);
			else if ((i == 1 && j == 1) || (i == 3 && j == 3))
				matrix.m[i][j] = 1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_matrix4  matrix_rotationZ(float angle)
{
	t_matrix4 matrix;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 0 && j == 0)
				matrix.m[i][j] = cos(angle);
			else if (i == 0 && j == 1)
				matrix.m[i][j] = -sin(angle);
			else if (i == 1 && j == 0)
				matrix.m[i][j] = sin(angle);
			else if (i == 1 && j == 1)
				matrix.m[i][j] = cos(angle);
			else if ((i == 2 && j == 2) || (i == 3 && j == 3))
				matrix.m[i][j] = 1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_matrix4  matrix_homothetie(t_vecteur4 homo)
{
	t_matrix4 matrix;
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 0 && j == 0)
				matrix.m[i][j] = homo.x1;
			else if (i == 1 && j == 1)
				matrix.m[i][j] = homo.y1;
			else if (i == 2 && j == 2)
				matrix.m[i][j] = homo.z1;
			else if (i == 3 && j == 3)
				matrix.m[i][j] = homo.w1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_matrix4 matrix_projection(float angle, float ratio, float near, float far) 
{
	float f;
	float r;
	float nd;
	float fd;
	t_matrix4 matrix;
	int i;
	int j;

	f = 1 / tan(angle / 2);
	r = ratio;
	nd = near;
	fd = far;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 0 && j == 0)
				matrix.m[i][j] = f / r;
			else if (i == 1 && j == 1)
				matrix.m[i][j] = f;
			else if (i == 2 && j == 2)
				matrix.m[i][j] = (-fd-nd)/(nd-fd);
			else if (i == 2 && j == 3)
				matrix.m[i][j] = (2*fd*nd)/(nd-fd);
			else if ((i == 3 && j == 3) || (i == 3 && j == 2))
				matrix.m[i][j] = 1;
			else
				matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

t_vecteur4 create_vecteur4(int x, int y, int z, int w)
{
	t_vecteur4 new_vecteur4;

	new_vecteur4.x1= x;
	new_vecteur4.y1= y;
	new_vecteur4.z1= z;
	new_vecteur4.w1= w;
	return(new_vecteur4);
}
