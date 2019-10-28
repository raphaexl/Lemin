/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:48:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 12:31:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

long int	ft_ceil(float f)
{
	long int	n;

	n = (long int)f;
	if (f == (float)n)
		return (n);
	return (n + 1);
}

char		*get_room_name(t_all *all, int current_id)
{
	int		i;
	t_room	*current;

	i = -1;
	current = _ROOM;
	while (++i < current_id)
		current = current->next;
	return (ft_strdup(current->name));
}

int			get_room_id(t_all *all, t_room *room)
{
	t_room	*current;
	int		id_room;

	id_room = -1;
	current = _ROOM;
	while (++id_room < _INPUT->count_room)
	{
		if (current == room)
			break ;
		current = current->next;
	}
	return (id_room);
}

void		ft_way_free(char ***ways)
{
	int	i;

	i = -1;
	while ((*ways)[++i])
		free((*ways)[i]);
	free((*ways));
}
