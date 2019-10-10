/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:31:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 12:51:44 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		ft_lemin_init(t_lemin *lem)
{
	ft_bzero(lem, sizeof(t_lemin));
	lem->room = ft_strdup("");
	lem->link = ft_strdup("");
}

int			ft_lemin_matrix_init(t_lemin *lem)
{
	int		i;
	int		j;

	i = -1;
	if (!(lem->map = ft_memalloc(sizeof(char *) * lem->nbr_room)))
		return (-1);
	if (!(lem->room_name = ft_memalloc(sizeof(char *) * (lem->nbr_room + 1))))
		return (-1);
	while (++i < lem->nbr_room)
	{
		j = -1;
		if (!(lem->map[i] = ft_memalloc(sizeof(char) * lem->nbr_room)))
			return (-1);
		lem->room_name[i] = NULL;
		while (++j < lem->nbr_room)
			lem->map[i][j] = '\0';
	}
	lem->room_name[i] = NULL;
	return (0);
}
