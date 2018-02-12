/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:31:57 by alamy             #+#    #+#             */
/*   Updated: 2018/02/12 12:39:33 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_nb_col(char **argv)
{
	int 	nb_col;
	int		fd;
	char	*line;
	char 	**str;

	fd = open(argv[1], O_RDONLY);
	nb_col = 0;
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		while (str[nb_col] != '\0')
			nb_col++;
		break;
	}
	while (get_next_line(fd, &line) > 0)
	{	
	}
	return(nb_col);
}

int ft_nb_line(char **argv)
{
	int 	nb_line;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	nb_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
	}
	free(line);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
	return(nb_line);
}

int ft_lenght(char **str)
{
	int y;

	y = 0;
	while(str[y] != '\0')
	{
		y++;
	}
	return(y);
}

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}
