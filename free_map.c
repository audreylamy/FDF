/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:56:36 by alamy             #+#    #+#             */
/*   Updated: 2018/02/15 13:17:07 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_env *tmp)
{
	int i;
	int j;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->nb_col)
		{
			free(tmp->map[i][j]);
			free(tmp->map_buffer[i][j]);
			j++;
		}
		i++;
	}
	free(tmp->map);
	free(tmp->map_buffer);
}
