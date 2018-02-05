/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:15:41 by alamy             #+#    #+#             */
/*   Updated: 2018/02/03 18:34:17 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_bre_1(t_algob *b, t_env *tmp, int x0, int y0)
{
	while(b->i <= b->Dx)
		{
			fill_pixel(tmp, x0 + tmp->new_move_x, y0 + tmp->new_move_y,  0x00FFFF);
			(b->i)++;
			x0 = x0 + b->Xincr;
			b->ex = b->ex - b->dy;
			if (b->ex < 0)
			{
				y0 = y0 + b->Yincr;
				b->ex = b->ex + b->dx;
			}
		}
}

void ft_bre_2(t_algob *b, t_env *tmp, int x0, int y0)
{
	while (b->i <= b->Dy)
		{
			fill_pixel(tmp, x0 + tmp->new_move_x, y0 + tmp->new_move_y, 0x00FFFF);
			(b->i)++;
			y0 = y0 + b->Yincr;
			b->ey = b->ey - b->dx;
			if (b->ey < 0)
			{
				x0 = x0 + b->Xincr;
				b->ey = b->ey + b->dy;
			}
		}
}

void init_bre(t_algob *b)
{
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	b->Dx = b->ex;
	b->Dy = b->ey;
	b->i = 0;
	b->Xincr = 1;
	b->Yincr = 1;
}

void ft_bresenham(int x0, int y0, int x1, int y1, t_env *tmp)
{
	t_algob b;

	b.ex = ft_abs(x1 - x0);
	b.ey = ft_abs(y1 - y0);
	init_bre(&b);
	if (x0 > x1)
		b.Xincr = -1;
	if (y0 > y1)
		b.Yincr = -1;

	if (b.Dx > b.Dy)
		ft_bre_1(&b, tmp, x0, y0);
	else if (b.Dx < b.Dy)
		ft_bre_2(&b, tmp, x0, y0);
}
