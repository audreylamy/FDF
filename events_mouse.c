/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:28:21 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 19:15:59 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_redraw_image(t_env *tmp, int keycode)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
	&tmp->img.size_bits, &tmp->img.endian);
	ft_transform_map(tmp, keycode);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
	ft_create_string(tmp);
}

int		my_mouse_funct(int button, int x, int y, t_env *tmp)
{
	event_clic(button, tmp);
	ft_redraw_image(tmp, button);
	return (0);
}

void	event_clic(int button, t_env *tmp)
{
	if (button == CLIC_LEFT)
		tmp->clic_proj += 10;
	if (button == CLIC_RIGHT)
		tmp->clic_proj -= 10;
}
