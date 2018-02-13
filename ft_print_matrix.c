/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:48:13 by alamy             #+#    #+#             */
/*   Updated: 2018/02/13 18:04:17 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_print_matrix(t_matrix4 matrix)
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			ft_putnbr(matrix.m[i][j]);
			if (j == 3)
				ft_putchar('\n');
			j++;
		}
		i++;
	}
}
