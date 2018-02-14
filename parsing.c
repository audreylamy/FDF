/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:19:16 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 14:29:10 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_parse_map(char **argv, t_env *tmp)
{
	int			fd;
	char		*line;
	int			***map;
	int			***map_buffer;

	if (!(map = (int ***)malloc(tmp->nb_line * sizeof(int **))) ||
		!(map_buffer = (int ***)malloc(tmp->nb_line * sizeof(int **))))
	{
		ft_putstr("malloc failed");
		exit(EXIT_FAILURE);
	}
	tmp->map = map;
	tmp->map_buffer = map_buffer;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while (get_next_line(fd, &line) > 0)
	{
		ft_get_coord(line, tmp);
	}
	free(line);
	if (close(fd) == -1)
		ft_putstr("close() failed\n");
}

static char		*ft_sk(char *str)
{
	int			j;

	j = 0;
	while (str[j] != '\0' && str[j] != ',')
	{
		j++;
	}
	if (str[j] == ',')
		j++;
	if (str[j] == '0')
		j++;
	if (str[j] == 'x')
		j++;
	return (&str[j]);
}

void			ft_get_coord(char *line, t_env *tmp)
{
	static int	i;
	int			j;
	char		**str;

	j = 0;
	str = ft_strsplit(line, ' ');
	tmp->map[i] = (int **)malloc(tmp->nb_col * sizeof(int *));
	tmp->map_buffer[i] = (int **)malloc(tmp->nb_col * sizeof(int *));
	while (str[j] != '\0' && j < tmp->nb_col)
	{
		tmp->map[i][j] = (int *)malloc(5 * sizeof(int));
		tmp->map_buffer[i][j] = (int *)malloc(5 * sizeof(int));
		tmp->map[i][j][0] = j * TILE_WIDTH;
		tmp->map[i][j][1] = i * TILE_HEIGHT;
		tmp->map[i][j][2] = ft_getnbr(str[j]);
		tmp->map[i][j][3] = 1;
		tmp->map[i][j][4] = ft_strchr(str[j], ',') ?
		(int)ft_atoi_base(ft_sk(str[j]), 16) : (int)ft_atoi_base("FFC0CB", 16);
		j++;
	}
	i++;
}
