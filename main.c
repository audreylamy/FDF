/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/02/06 15:56:15 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_check_name_file(char *str)
{
	char *str1;
	int i;
	int j;

	i = 0;
	j = 0;
	str1 = ".fdf";
	
	while (str1[i] != '\0' && str[j] != '\0')
	{
		if (str1[i] == str[j])
			i++;
		if (str[j + 1] == '\0' && str1[i] != '\0')
			return(0);
		j++;
	}
	return(1);
}

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
		if ((ft_check_name_file(argv[1])) == 0)
		{
			ft_putstr("bad name : not .fdf");
			exit(1);
		}
		else
		{
			tmp.nb_line = ft_nb_line(argv); 
			tmp.nb_col = ft_nb_col(argv);
			tmp.mlx = mlx_init();
			tmp.win = mlx_new_window(tmp.mlx, WINDOW_L, WINDOW_H, "mlx 42");
			ft_parse_map(argv, &tmp);
			ft_create_image(&tmp);
			mlx_key_hook(tmp.win, my_key_funct, &tmp);
			//mlx_mouse_hook(tmp.win, my_mouse_funct, &tmp);
			mlx_loop(tmp.mlx);
		}
	}
	return (0);
}

