/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:12 by alamy             #+#    #+#             */
/*   Updated: 2018/02/03 18:32:24 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stdio.h"
#include "fdf.h"

void ft_draw_line_horiz(t_env *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int x1;
	int y1;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->nb_col - 1)
		{
			x = tmp->map_buffer[i][j][0];
			y = tmp->map_buffer[i][j][1];
			x1 = tmp->map_buffer[i][j + 1][0];
			y1 = tmp->map_buffer[i][j + 1][1];
			//tmp->img.color = tmp->map_buffer[i][j][4];
			ft_bresenham(x, y, x1, y1, tmp);
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical(t_env *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int x1;
	int y1;
	
	i = 0;
	j = 0;
	while (j < tmp->nb_col)
	{
		while (i < tmp->nb_line - 1)
		{
			x = tmp->map_buffer[i][j][0];
			y = tmp->map_buffer[i][j][1];
			x1 = tmp->map_buffer[i + 1][j][0];
			y1 = tmp->map_buffer[i + 1][j][1];
			//tmp->img.color = tmp->map_buffer[i][j][4];
			ft_bresenham(x, y, x1, y1, tmp);
			i++;
		}
		i = 0;
		j++;
	}
}