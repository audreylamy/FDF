/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:54:51 by alamy             #+#    #+#             */
/*   Updated: 2018/02/12 14:55:35 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isnumber(char *str)
{
	int i;

	i = 0;
    while (str[i] != '\0')
    {
        if (ft_iswhitespace(str[i]))
             return (0);
        if (str[i] == '+' || str[i] == '-')
             i++;
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
     }
    return (1);
}
