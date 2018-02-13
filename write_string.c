/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:21 by Deydou            #+#    #+#             */
/*   Updated: 2018/02/13 18:45:26 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_create_string(t_env *tmp)
{
	mlx_string_put(tmp->mlx, tmp->win, 10, 10, 255255255, "Quit : esc");
	mlx_string_put(tmp->mlx, tmp->win, 10, 30, 255255255, "Reset : space");
	mlx_string_put(tmp->mlx, tmp->win, 10, 50, 255255255, "Translation : < > ");
	mlx_string_put(tmp->mlx, tmp->win, 10, 70, 255255255, "Zoom : + - ");
	mlx_string_put(tmp->mlx, tmp->win, 10, 90, 255255255, "Zoom Z : + - ");
	mlx_string_put(tmp->mlx, tmp->win, 10, 110, 255255255, "Rotation X :  - ");
	mlx_string_put(tmp->mlx, tmp->win, 10, 130, 255255255, "Rotation Y : 2 or 8");
	mlx_string_put(tmp->mlx, tmp->win, 10, 150, 255255255, "Rotation Z : 4 or 6");
	mlx_string_put(tmp->mlx, tmp->win, 10, 170, 255255255, "Projection 100 : enter");
	mlx_string_put(tmp->mlx, tmp->win, 10, 190, 255255255, "Projection 70 : maj");
}