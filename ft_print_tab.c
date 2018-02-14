/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:18:55 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 18:37:09 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_print_tab(t_env *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->nb_col)
		{
			ft_putnbr(tmp->map[i][j][0]);
			ft_putnbr(tmp->map[i][j][1]);
			ft_putnbr(tmp->map[i][j][2]);
			ft_putnbr(tmp->map[i][j][4]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}
