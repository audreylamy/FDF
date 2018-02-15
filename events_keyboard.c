/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:01:56 by Deydou            #+#    #+#             */
/*   Updated: 2018/02/15 17:52:01 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, t_env *tmp)
{
	if (keycode == EXIT)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		ft_free_map(tmp);
		exit(1);
	}
	if (keycode == RESET)
		ft_redraw_image(tmp, keycode);
	event_translation(keycode, tmp);
	event_rotation(keycode, tmp);
	event_zoom_projection(keycode, tmp);
	event_color(keycode, tmp);
	ft_redraw_image(tmp, keycode);
	return (0);
}

void	event_translation(int keycode, t_env *tmp)
{
	if (keycode == UP)
		tmp->move_y -= 10;
	if (keycode == DOWN)
		tmp->move_y += 10;
	if (keycode == RIGHT)
		tmp->move_x += 10;
	if (keycode == LEFT)
		tmp->move_x -= 10;
}

void	event_rotation(int keycode, t_env *tmp)
{
	if (keycode == ROTATION_X_DOWN)
		tmp->move_rotation_x -= 5;
	if (keycode == ROTATION_X_UP)
		tmp->move_rotation_x += 5;
	if (keycode == ROTATION_Z_RIGHT)
		tmp->move_rotation_y += 5;
	if (keycode == ROTATION_Z_LEFT)
		tmp->move_rotation_y -= 5;
	if (keycode == ROTATION_Y_A)
		tmp->move_rotation_z += 5;
	if (keycode == ROTATION_Y_W)
		tmp->move_rotation_z -= 5;
}

void	event_zoom_projection(int keycode, t_env *tmp)
{
	if (keycode == ZOOM_UP)
		tmp->zoom += 1.0;
	if (keycode == ZOOM_DOWN)
		tmp->zoom -= 1.0;
	if (keycode == ZOOM_Z_UP)
		tmp->zoom_z += 1.0;
	if (keycode == ZOOM_Z_DOWN)
		tmp->zoom_z -= 1.0;
	if (keycode == PROJECTION_UP)
		tmp->projection += 10;
	if (keycode == PROJECTION_DOWN)
		tmp->projection -= 10;
}

void	event_color(int keycode, t_env *tmp)
{
	if (keycode == COLOR_RED)
		tmp->color_red += 5;
	if (keycode == COLOR_GREEN)
		tmp->color_green += 5;
	if (keycode == COLOR_BLUE)
		tmp->color_blue += 5;
	if (keycode == ALL_COLOR)
	{
		tmp->color_red += 5;
		tmp->color_green += 5;
		tmp->color_blue += 5;
	}
}
