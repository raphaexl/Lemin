/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:28:01 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 12:52:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static void		ft_room_index(t_lemin *lem, char **split)
{
	int		i;
	int		x;
	int		y;
	
	i = -1;
	x = 0;
	while (lem->room_name[++i] && i < lem->nbr_room)
		if (!ft_strcmp(lem->room_name[i], split[0]))
			x = i;
	i = -1;
	y = 0;
	while (lem->room_name[++i] && i < lem->nbr_room)
		if (!ft_strcmp(lem->room_name[i], split[1]))
			y = i;
	if (x)
		lem->map[y][x] = 1;
	if (y)
		lem->map[x][y] = 1;
}

int				ft_check_map(t_lemin *lem)
{
	int		i;
	char	**split1;
	char	**split2;

	i = -1;
	if (!(split1 = ft_strsplit(lem->link, '\n')))
		return (-1);
	while (split1[++i])
	{
		if (!(split2 = ft_strsplit(split1[i], '-')))
			return (-1);
		ft_room_index(lem, split2);
		ft_free_split(&split2);
	}
	ft_free_split(&split1);
	return (0);
}
