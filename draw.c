/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:12 by alamy             #+#    #+#             */
/*   Updated: 2018/02/15 16:53:29 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_horiz(t_env *tmp)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->nb_col - 1)
		{
			data.x = tmp->map_buffer[i][j][0];
			data.y = tmp->map_buffer[i][j][1];
			data.x0 = tmp->map_buffer[i][j + 1][0];
			data.y0 = tmp->map_buffer[i][j + 1][1];
			data.z0 = tmp->map_buffer[i][j][2];
			data.color = tmp->map_buffer[i][j][4];
			ft_bresenham(&data, tmp);
			j++;
		}
		i++;
	}
}

void	ft_draw_line_vertical(t_env *tmp)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < tmp->nb_col)
	{
		while (i < tmp->nb_line - 1)
		{
			data.x = tmp->map_buffer[i][j][0];
			data.y = tmp->map_buffer[i][j][1];
			data.x0 = tmp->map_buffer[i + 1][j][0];
			data.y0 = tmp->map_buffer[i + 1][j][1];
			data.z0 = tmp->map_buffer[i][j][2];
			data.color = tmp->map_buffer[i][j][4];
			ft_bresenham(&data, tmp);
			i++;
		}
		i = 0;
		j++;
	}
}
