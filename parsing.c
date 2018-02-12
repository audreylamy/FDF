/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:19:16 by alamy             #+#    #+#             */
/*   Updated: 2018/02/12 16:08:37 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void   ft_parse_map(char **argv, t_env *tmp)
{
	int		fd;
    char	*line;
	int		***map;
	int 	***map_buffer;

	if(!(map = (int ***)malloc(tmp->nb_line * sizeof(int **))) || 
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

void     ft_get_coord(char *line, t_env *tmp)
{
    static	int	i;
	int			j;
	char		**str;

	j = 0;
    str = ft_strsplit(line, ' ');

	tmp->map[i] = (int **)malloc(tmp->nb_col * sizeof(int *));
	tmp->map_buffer[i] = (int **)malloc(tmp->nb_col * sizeof(int *));
	while (str[j] != '\0' && j < tmp->nb_col)
	{
		tmp->map[i][j] = (int *)malloc(4 * sizeof(int));
		tmp->map_buffer[i][j] = (int *)malloc(4 * sizeof(int));
		tmp->map[i][j][0] = j * TILE_WIDTH;
		tmp->map[i][j][1] = i * TILE_HEIGHT;
		tmp->map[i][j][2] = ft_getnbr(str[j]);
		tmp->map[i][j][3] = 1;
		// tmp->map[i][j][4] = ft_strchr(str[j], ',') ? (int)ft_strtol(ft_strsub(str[j], ft_strlen(str[j]) - 6, 6)) : (int)ft_strtol("FFC0CB");
		j++;
	}
	i++;
}