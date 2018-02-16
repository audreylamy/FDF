/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:31:57 by alamy             #+#    #+#             */
/*   Updated: 2018/02/16 12:41:21 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_nb_col(char **argv)
{
	int		nb_col;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (ft_open_failed(fd) == -1)
		return (-1);
	get_next_line(fd, &line);
	nb_col = ft_count_words(line);
	free(line);
	if (ft_close_failed(fd) == -1)
		return (-1);
	return (nb_col);
}

int	ft_nb_line(char **argv)
{
	int		nb_line;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (ft_open_failed(fd) == -1)
		return (-1);
	nb_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
	return (nb_line);
}

int	ft_count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			count++;
		}
	}
	return (count);
}
