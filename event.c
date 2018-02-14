/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:01:56 by Deydou            #+#    #+#             */
/*   Updated: 2018/02/14 12:47:31 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_redraw_image(t_env *tmp, int keycode)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp, 
	&tmp->img.size_bits, &tmp->img.endian);
	ft_transform_map(tmp, keycode);
 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
	ft_create_string(tmp);
}

int my_key_funct(int keycode, t_env *tmp)
{
	printf("key event %d\n", keycode);
	if (keycode == EXIT)
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
	if (keycode == COLOR_RED || keycode == COLOR_GREEN || keycode == COLOR_BLUE || keycode == ALL_COLOR) 
	{
		event_color(keycode, tmp);
		ft_redraw_image(tmp, keycode);
	}
	if (keycode == PROJECTION_PLUS || keycode == PROJECTION_MOINS) 
	{
		event_projection(keycode, tmp);
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

void	event_projection(int keycode, t_env *tmp)
{
		if (keycode == PROJECTION_PLUS)
			tmp->projection += 10;
		if (keycode == PROJECTION_MOINS)
			tmp->projection -= 10;
}

int my_mouse_funct(int button, int x, int y, t_env *tmp)
{
	if (button == CLIC_LEFT || button == CLIC_RIGHT)
	{	
		event_clic(button, tmp);
		ft_redraw_image(tmp, button);
	}
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{	
		event_clic(button, tmp);
		ft_redraw_image(tmp, button);
	}
	return(0);
}

void event_clic(int button, t_env *tmp)
{
	if (button == CLIC_LEFT)
		tmp->clic_proj += 10;
	if (button == CLIC_RIGHT)
		tmp->clic_proj -= 10;
	if (button == SCROLL_UP)
		tmp->scroll += 10;
	if (button == SCROLL_DOWN)
		tmp->scroll -= 10;
}
