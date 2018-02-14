/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:18:21 by Deydou            #+#    #+#             */
/*   Updated: 2018/02/14 15:05:09 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_string(t_env *t)
{
	mlx_string_put(t->mlx, t->win, 10, 0, 16777215, "Quit : esc");
	mlx_string_put(t->mlx, t->win, 10, 20, 16777215, "Reset : space");
	mlx_string_put(t->mlx, t->win, 10, 40, 16777215, "Translation : < > ^ v");
	mlx_string_put(t->mlx, t->win, 10, 60, 16777215, "Zoom : + - (num keypad)");
	mlx_string_put(t->mlx, t->win, 10, 80, 16777215, "Zoom Z : + -");
	mlx_string_put(t->mlx, t->win, 10, 100, 16777215, "Rotation X : 4 or 6");
	mlx_string_put(t->mlx, t->win, 10, 120, 16777215, "Rotation Y : 2 or 8");
	mlx_string_put(t->mlx, t->win, 10, 140, 16777215, "Rotation Z : A or W");
	mlx_string_put(t->mlx, t->win, 10, 160, 16777215,
	"Projection + : return or clic right");
	mlx_string_put(t->mlx, t->win, 10, 180, 16777215,
	"Projection - : shift or clic left");
	mlx_string_put(t->mlx, t->win, 10, 200, 167119960, "Color R : R");
	mlx_string_put(t->mlx, t->win, 10, 220, 168529960, "Color G : G");
	mlx_string_put(t->mlx, t->win, 10, 240, 16987360, "Color B : B");
	mlx_string_put(t->mlx, t->win, 10, 260, 16777215, "Color mix : C");
}
