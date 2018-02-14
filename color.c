/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:34:40 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 14:44:37 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	ft_color_converter(t_env *tmp, int hexvalue)
{
	t_color rgbcolor;

	if (tmp->color_red > 255 || tmp->color_green > 255 || tmp->color_blue > 255)
	{
		tmp->color_red -= 255;
		tmp->color_green -= 255;
		tmp->color_blue -= 255;
	}
	rgbcolor.r = ((hexvalue >> 16) & 0xFF) + tmp->color_red;
	rgbcolor.g = ((hexvalue >> 8) & 0xFF) + tmp->color_green;
	rgbcolor.b = ((hexvalue) & 0xFF) + tmp->color_blue;
	return (rgbcolor);
}
