/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/02/12 14:27:23 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env tmp;

	if (argc != 2)
	{
		ft_putstr("too many or too few arguments\n");
		exit(1);
	}
	else
	{
		tmp.nb_line = ft_nb_line(argv); 
		tmp.nb_col = ft_nb_col(argv);
		if ((ft_checks(argv, &tmp)) == -1)
		{
			exit(1);
		}
		tmp.mlx = mlx_init();
		tmp.win = mlx_new_window(tmp.mlx, WINDOW_L, WINDOW_H, "mlx 42");
		ft_parse_map(argv, &tmp);
		ft_create_image(&tmp);
		mlx_hook(tmp.win, 2, 0, my_key_funct, &tmp.mlx);
		//mlx_mouse_hook(tmp.win, my_mouse_funct, &tmp);
		mlx_loop(tmp.mlx);
	}
	return (0);
}

