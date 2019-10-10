/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:35:26 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 12:52:03 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		parse_ant(t_lemin *lem)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	if (lem->line[0] == '#')
		return (0);
	while (ft_isdigit(lem->line[++i]))
	{
		nb += (lem->line[i] - '0');
		if (ft_isdigit(lem->line[i + 1]))
			nb *= 10;
	}
	if (nb <= 0 || !i || lem->line[i])
	{
		ft_printf("error ants number\n");
		return (-1);
	}
	lem->nbr_ant = nb;
	return (0);
}

int		parse_link(t_lemin *lem)
{
	char	**split;

	if (!ft_lemin_link_format(lem->line) && ft_printf("error link declaration\n"))
		return (-1);
	if (!(split = ft_strsplit(lem->line, '-')) || !(ft_len_split(split) == 2))
	{
		ft_free_split(&split);
		ft_printf("error link declaration\n");
		return (-1);
	}
	lem->link = ft_strjoin_3(lem->link, lem->line, "\n");
	lem->nbr_link++;
	return (0);
}

int		parse_room(t_lemin *lem)
{
	char	**split;

	split = NULL;
	if (lem->line[0] == '#')
	{
		if (!ft_strcmp(lem->line, "##start"))
			lem->index_start++;
		else if (!ft_strcmp(lem->line, "##end"))
			lem->index_end++;
		else
			return (0);
	}
	else
	{
		if (!(split = ft_strsplit(lem->line, ' ')) || (split[0][0] == 'L') || (ft_len_split(split) != 3))
		{
			ft_free_split(&split);
			ft_printf("error room declaration");
			return (-1);
		}
		if (!ft_lemin_room_format(split))
		{
			ft_printf("error room declaration");
			return (-1);
		}
		lem->nbr_room++;
		ft_free_split(&split);
	}
	lem->room = ft_strjoin_3(lem->room, lem->line, "\n");
	return (0);
}

int		parse_input(t_lemin *lem)
{
	while ((lem->line = ft_read_line(0)))
	{
		if (!lem->nbr_ant)
		{
			if (-1 == parse_ant(lem))
				return (-1);
		}
		else if (ft_strchr(lem->line, '-'))
		{
			if (parse_link(lem))
				return (-1);
		}
		else 
		{
			if (parse_room(lem) == -1)
				return (-1);
		}
	}
	if (lem->index_start != 1 || lem->index_end != 1)
		return (-1);
	ft_printf("nb ants -- > %d\n", lem->nbr_ant);
	return (0);
}
