/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 09:41:15 by alamy             #+#    #+#             */
/*   Updated: 2018/02/16 12:45:22 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_name_file(char *str)
{
	char	*str1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1 = ".fdf";
	while (str1[i] != '\0' && str[j] != '\0')
	{
		if (str1[i] == str[j])
			i++;
		if (str[j + 1] == '\0' && str1[i] != '\0')
		{
			ft_putstr("name file is not valid\n");
			return (-1);
		}
		j++;
	}
	return (0);
}

int		ft_empty_file(char *str)
{
	int		fd;
	char	*line;
	int		nb;

	fd = open(str, O_RDONLY);
	if (ft_open_failed(fd) == -1)
		return (-1);
	nb = get_next_line(fd, &line);
	free(line);
	if (nb == -1 || nb == 0)
	{
		ft_putstr("Empty file\n");
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
	}
	free(line);
	if (ft_close_failed(fd) == -1)
		return (-1);
	return (0);
}

int		ft_check_map_rec(char *str, t_env *tmp)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	if (ft_open_failed(fd) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		if (tmp->nb_col != ft_count_words(line))
		{
			ft_putstr("map not rectangular\n");
			return (-1);
		}
		free(line);
	}
	free(line);
	if (ft_close_failed(fd) == -1)
		return (-1);
	return (0);
}

int		ft_isxdigit(char *str)
{
	int		i;
	char	*hex;

	i = 0;
	if (ft_strlen(str) >= 10)
	{
		hex = ft_strsub(str, ft_strlen(str) - 6, 6);
		if (ft_strspn(hex, "0123456789abcdefABCDEF") == 6
		&& ft_strstr(str, ",0x"))
			return (1);
	}
	return (0);
}

int		ft_check_data(char *str)
{
	int		i;
	int		fd;
	char	**str1;
	char	*line;

	fd = open(str, O_RDONLY);
	if (ft_open_failed(fd) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		i = -1;
		str1 = ft_strsplit(line, ' ');
		while (str1[++i] != '\0')
		{
			if (ft_isnumber(str1[i]) == 0 && ft_isxdigit(str1[i]) == 0)
				return (-1);
			free(str1[i]);
		}
		free(str1);
		free(line);
	}
	free(line);
	if (ft_close_failed(fd) == -1)
		return (-1);
	return (0);
}
