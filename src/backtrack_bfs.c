/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_bfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:10:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 17:14:22 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int				backtrack(t_graph *graph, int d)
{
	t_room_bfs *curr;
	t_room_bfs *parent;

	curr = get_room_id_bfs(graph->rooms, d);
	while (curr)
	{
		parent = curr->parent;
		if (parent)
		{
			edit_capacity(parent, curr, -1);
			edit_capacity(curr, parent, 1);
		}
		curr = parent;
	}
	return (1);
}

t_room_bfs		*backtrack_2(t_graph *graph, int s, int d)
{
	t_room_bfs *curr;
	t_room_bfs *rev_paths;
	t_room_bfs *start;
	t_room_bfs *dest;
	t_room_bfs *parent;

	rev_paths = NULL;
	start = get_room_id_bfs(graph->rooms, s);
	dest = get_room_id_bfs(graph->rooms, d);
	curr = dest;
	while (curr)
	{
		parent = curr->parent;
		if (!curr->blocked)
		{
			if (curr != start && curr != dest)
				curr->blocked = 1;
			add_room_to_struct_bfs(&rev_paths,
					create_new_room_bfs(curr->value));
		}
		if (parent)
			edit_blocked(parent, curr, 1);
		curr = parent;
	}
	return (rev_paths);
}

void			edit_capacity(t_room_bfs *curr, t_room_bfs *prev, int v)
{
	t_link_bfs *links;

	links = curr->links;
	while (links)
	{
		if (links->room->value == prev->value)
		{
			links->capacity += v;
			return ;
		}
		links = links->next;
	}
}

void			edit_blocked(t_room_bfs *curr, t_room_bfs *prev, int v)
{
	t_link_bfs *links;

	v = 1;
	links = curr->links;
	while (links)
	{
		if (links->room->value == prev->value)
		{
			links->blocked = v;
			return ;
		}
		links = links->next;
	}
}
