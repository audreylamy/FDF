/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:15:41 by alamy             #+#    #+#             */
/*   Updated: 2018/02/16 13:26:15 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(t_env *t, int x, int y, int color)
{
	t_color	rgbcolor;

	rgbcolor = ft_color_converter(t, color);
	if (x >= 0 && y >= 0 && x < WINDOW_L && y < WINDOW_H)
	{
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8] = rgbcolor.r;
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8 + 1] = rgbcolor.g;
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8 + 2] = rgbcolor.b;
	}
}

void	ft_bre_1(t_algob *b, t_env *tmp, t_data *data, int color)
{
	int i;

	i = 0;
	while (i <= b->px)
	{
		fill_pixel(tmp, data->x + tmp->move_x, data->y + tmp->move_y, color);
		i++;
		data->x = data->x + b->xincr;
		b->nb_pix_x = b->nb_pix_x - b->dy;
		if (b->nb_pix_x < 0)
		{
			data->y = data->y + b->yincr;
			b->nb_pix_x = b->nb_pix_x + b->dx;
		}
	}
}

void	ft_bre_2(t_algob *b, t_env *tmp, t_data *data, int color)
{
	int i;

	i = 0;
	while (i <= b->py)
	{
		fill_pixel(tmp, data->x + tmp->move_x, data->y + tmp->move_y, color);
		i++;
		data->y = data->y + b->yincr;
		b->nb_pix_y = b->nb_pix_y - b->dx;
		if (b->nb_pix_y < 0)
		{
			data->x = data->x + b->xincr;
			b->nb_pix_y = b->nb_pix_y + b->dy;
		}
	}
}

void	init_bre(t_algob *b)
{
	b->dx = 2 * b->nb_pix_x;
	b->dy = 2 * b->nb_pix_y;
	b->px = b->nb_pix_x;
	b->py = b->nb_pix_y;
	b->xincr = 1;
	b->yincr = 1;
}

void	ft_bresenham(t_data *data, t_env *tmp)
{
	t_algob	b;

	b.nb_pix_x = ft_abs(data->x0 - data->x);
	b.nb_pix_y = ft_abs(data->y0 - data->y);
	init_bre(&b);
	if (data->x > data->x0)
		b.xincr = -1;
	if (data->y > data->y0)
		b.yincr = -1;
	if (b.nb_pix_x > b.nb_pix_y)
		ft_bre_1(&b, tmp, data, data->color);
	else if (b.nb_pix_x < b.nb_pix_y)
		ft_bre_2(&b, tmp, data, data->color);
}
