/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:33:45 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 13:52:57 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		link_bfs(t_room_bfs *rooms, int f, int s)
{
	t_room_bfs *r;

	r = get_room_id_bfs(rooms, f);
	add_link_to_struct_bfs(&r->links,
			create_new_link_bfs(get_room_id_bfs(rooms, s)));
}

t_link_bfs	*create_new_link_bfs(t_room_bfs *room)
{
	t_link_bfs *link;

	if ((link = malloc(sizeof(t_link_bfs))))
	{
		link->capacity = 1;
		link->blocked = 0;
		link->room = room;
		link->next = NULL;
	}
	else
		exit(-1);
	return (link);
}

void		add_link_to_struct_bfs(t_link_bfs **links, t_link_bfs *new)
{
	t_link_bfs	*p;

	if (!links || !new)
		return ;
	if (!*links)
		*links = new;
	else
	{
		p = *links;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

void		ft_link_bfs_free(t_link_bfs **links)
{
	t_link_bfs *p;

	p = *links;
	while (p)
	{
		(*links) = (*links)->next;
		free(p);
		p = (*links);
	}
}
