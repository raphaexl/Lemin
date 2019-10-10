/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:08:27 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 12:52:32 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

static int	ft_validation_room(t_lemin *lem, char *s)
{
	if (lem->index_end == 2)
	{
		lem->room_name[lem->nbr_room - 1] = ft_strdup(s);
		lem->index_end = 3;
		return (1);
	}
	else if (lem->index_start == 2)
	{
		lem->room_name[0] = ft_strdup(s);
		lem->index_start = 3;
		return (1);
	}
	return (0);
}

static int	ft_check_room(t_lemin *lem, int j, char *s)
{
	int		index;

	index  = -1;
	while (lem->room_name[++index] && index < lem->nbr_room)
		if (!ft_strcmp(lem->room_name[index], s))
			break ;
	if (index > 0 && j != index)
	{
		ft_printf("error rooms checking");
		return (-1);
	}
	lem->room_name[j] = ft_strdup(s);
	return (0);
}

static void	ft_check_start_end(t_lemin *lem, char  **split, int index)
{
	if (!ft_strcmp(split[index], "##start"))
		lem->index_start = 2;
	else if (!ft_strcmp(split[index], "##end"))
		lem->index_end = 2;
	else 
		return ;
}

int				ft_lemin_matrix(t_lemin *lem)
{
	int		i;
	int		j;
	char	**split1;
	char	**split2;

	i = -1;
	j = 0;
	if (!(split1 = ft_strsplit(lem->room, '\n')))
		return (-1);
	while (split1[++i] && j < lem->nbr_room)
	{
		if (!(split2 = ft_strsplit(split1[i], ' ')))
			return (-1);
		if (split1[i][0] == '#' && (lem->index_start != 2 || lem->index_end != 2))
			ft_check_start_end(lem, split1, i);
		if (split1[i][0] != '#')
		{
			if (lem->index_start == 2 || lem->index_end == 2)
			{
				if (ft_validation_room(lem, split2[0]))
					continue ;
			}
			ft_check_room(lem, ++j, split2[0]);
		}
		ft_free_split(&split2);
	}
	ft_free_split(&split1);
	if (ft_check_map(lem))
		return (-1);
	return (0);
}
