/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:39:04 by alamy             #+#    #+#             */
/*   Updated: 2018/02/12 17:50:12 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_redraw_image(t_env *tmp, int keycode)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp, &tmp->img.size_bits, &tmp->img.endian);
	ft_transform_map(tmp, keycode);
 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

int my_key_funct(int keycode, t_env *tmp)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(0);
	}

	if (keycode == UP || keycode == DOWN || keycode == RIGHT ||
		keycode == LEFT)
		{
			event_translation(keycode, tmp);
			ft_redraw_image(tmp, keycode);
		}
	if (keycode == ROTATION_X_DOWN || keycode == ROTATION_X_UP || keycode == ROTATION_Z_RIGHT ||
		keycode == ROTATION_Z_LEFT || keycode == ROTATION_Y_A || keycode == ROTATION_Y_W)
		{
			event_rotation(keycode, tmp);
			ft_redraw_image(tmp, keycode);
		}
	if (keycode == ZOOM_UP || keycode == ZOOM_DOWN || keycode == ZOOM_Z_UP || keycode == ZOOM_Z_DOWN) 
	{
		event_zoom(keycode, tmp);
		ft_redraw_image(tmp, keycode);
	}
	if (keycode == COLOR_RED || keycode == COLOR_GREEN || keycode == COLOR_BLUE) 
	{
		event_color(keycode, tmp);
		ft_redraw_image(tmp, keycode);
	}
	if (keycode == RESET)
	{
		ft_redraw_image(tmp, keycode);
	}
	return(0);
}

void	event_translation(int keycode, t_env *tmp)
{
    if (keycode == UP)
			tmp->new_move_y -= 10;
    if (keycode == DOWN)
			tmp->new_move_y += 10;
    if (keycode == RIGHT)
			tmp->new_move_x += 10;
    if (keycode == LEFT)
			tmp->new_move_x -= 10;
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

void	event_zoom(int keycode, t_env *tmp)
{
		if (keycode == ZOOM_UP)
			tmp->zoom += 1.0;
		if (keycode == ZOOM_DOWN)
			tmp->zoom -= 1.0;
		if (keycode == ZOOM_Z_UP)
			tmp->zoom_z += 1.0;
		if (keycode == ZOOM_Z_DOWN)
			tmp->zoom_z -= 1.0;
}

void	event_color(int keycode, t_env *tmp)
{
		if (keycode == COLOR_RED)
			tmp->color_red += 10;
		if (keycode == COLOR_GREEN)
			tmp->color_green += 10;
		if (keycode == COLOR_BLUE)
			tmp->color_blue += 10;
}