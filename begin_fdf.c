/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:13:14 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 17:49:47 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_create_image(t_env *tmp)
{
	int			keycode;

	keycode = 0;
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
					&tmp->img.size_bits, &tmp->img.endian);
	ft_transform_map(tmp, keycode);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

t_vector4	ft_two_transformation(t_data *data, t_env *tmp, int keycode)
{
	t_vector4	resultat;

	if (keycode == RESET)
		resultat = ft_reset_transformation(data, tmp);
	else
		resultat = ft_create_transformation(data, tmp);
	return (resultat);
}

void		ft_transform_map(t_env *tmp, int keycode)
{
	int			i;
	int			j;
	t_data		data;
	t_vector4	resultat;

	data.w0 = 1;
	i = -1;
	while (++i < tmp->nb_line)
	{
		j = -1;
		while (++j < tmp->nb_col)
		{
			data.x0 = tmp->map[i][j][0];
			data.y0 = tmp->map[i][j][1];
			data.z0 = tmp->map[i][j][2];
			data.color = tmp->map[i][j][4];
			resultat = ft_two_transformation(&data, tmp, keycode);
			tmp->map_buffer[i][j][0] = resultat.x1;
			tmp->map_buffer[i][j][1] = resultat.y1;
			tmp->map_buffer[i][j][2] = resultat.z1;
			tmp->map_buffer[i][j][4] = data.color;
		}
	}
	ft_draw_line_horiz(tmp);
	ft_draw_line_vertical(tmp);
}
