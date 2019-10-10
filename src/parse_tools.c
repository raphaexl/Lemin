/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:35:39 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 10:43:43 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		ft_lemin_link_format(char  *line)
{
	int		nb_h;
	int		i;

	i = -1;
	nb_h = 0;
	while (line[++i])
	{
		if (line[i] == '-')
			nb_h++;
	}
	return (nb_h == 1);
}

int		ft_lemin_room_format(char  **split)
{
	int		i;

	i = -1;
	while (split[1][++i])
	{
		if (!ft_isdigit(split[1][i]))
			return (0);
	}
	i = -1;
	while (split[2][++i])
	{
		if (!ft_isdigit(split[2][i]))
			return (0);
	}
	return (1);
}
