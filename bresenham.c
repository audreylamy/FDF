/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:15:41 by alamy             #+#    #+#             */
/*   Updated: 2018/02/15 10:19:33 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(t_env *t, int x, int y, int color)
{
	int		new_color;
	t_color	rgbcolor;

	new_color = mlx_get_color_value(t->mlx, color);
	rgbcolor = ft_color_converter(t, new_color);
	if (x >= 0 && y >= 0 && x < WINDOW_L && y < WINDOW_H)
	{
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8] = rgbcolor.r;
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8 + 1] = rgbcolor.g;
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8 + 2] = rgbcolor.b;
	}
}

void	ft_bre_1(t_algob *b, t_env *tmp, t_data *data, int color)
{
	while (b->i <= b->px)
	{
		fill_pixel(tmp, data->x + tmp->move_x, data->y + tmp->move_y, color);
		(b->i)++;
		data->x = data->x + b->xincr;
		b->ex = b->ex - b->dy;
		if (b->ex < 0)
		{
			data->y = data->y + b->yincr;
			b->ex = b->ex + b->dx;
		}
	}
}

void	ft_bre_2(t_algob *b, t_env *tmp, t_data *data, int color)
{
	while (b->i <= b->py)
	{
		fill_pixel(tmp, data->x + tmp->move_x, data->y + tmp->move_y, color);
		(b->i)++;
		data->y = data->y + b->yincr;
		b->ey = b->ey - b->dx;
		if (b->ey < 0)
		{
			data->x = data->x + b->xincr;
			b->ey = b->ey + b->dy;
		}
	}
}

void	init_bre(t_algob *b)
{
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	b->px = b->ex;
	b->py = b->ey;
	b->i = 0;
	b->xincr = 1;
	b->yincr = 1;
}

void	ft_bresenham(t_data *data, t_env *tmp)
{
	t_algob	b;

	b.ex = ft_abs(data->x0 - data->x);
	b.ey = ft_abs(data->y0 - data->y);
	init_bre(&b);
	if (data->x > data->x0)
		b.xincr = -1;
	if (data->y > data->y0)
		b.yincr = -1;
	if (b.px > b.py)
		ft_bre_1(&b, tmp, data, data->color);
	else if (b.px < b.py)
		ft_bre_2(&b, tmp, data, data->color);
}
