/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:28:44 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 17:42:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_room_bfs		*create_new_room_bfs(int id_room)
{
	t_room_bfs	*room;

	if ((room = malloc(sizeof(t_room_bfs))))
	{
		room->value = id_room;
		room->visited = 0;
		room->blocked = 0;
		room->links = NULL;
		room->parent = NULL;
		room->next = NULL;
	}
	else
		exit(-1);
	return (room);
}

void			add_room_to_struct_bfs(t_room_bfs **rooms, t_room_bfs *new)
{
	t_room_bfs	*p;

	if (!rooms || !new)
		return ;
	if (!*rooms)
		*rooms = new;
	else
	{
		p = *rooms;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

t_room_bfs		*get_room_id_bfs(t_room_bfs *rooms, int id)
{
	t_room_bfs	*p;

	p = rooms;
	while (p)
	{
		if (p->value == id)
			return (p);
		p = p->next;
	}
	return (p);
}

int				ft_rooms_length(t_room_bfs *rooms)
{
	if (!rooms)
		return (0);
	return (1 + ft_rooms_length(rooms->next));
}

void			ft_room_bfs_free(t_room_bfs **rooms)
{
	t_room_bfs	*p;

	p = *rooms;
	while (p)
	{
		(*rooms) = (*rooms)->next;
		if (p->links)
			ft_link_bfs_free(&p->links);
		free(p);
		p = (*rooms);
	}
}
