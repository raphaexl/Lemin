/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:43:49 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 15:57:28 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int			bfs_path_1(t_graph *graph, int s, int d)
{
	t_queue		*queue;
	t_room_bfs	*room;
	t_link_bfs	*links;

	queue = NULL;
	ft_queue_enqueue(&queue, ft_queue_new(get_room_id_bfs(graph->rooms, s)));
	queue->room->visited = 1;
	while (queue)
	{
		room = ft_queue_dequeue(&queue);
		links = room->links;
		while (links)
		{
			if (links->room->visited == 0 && links->capacity > 0)
			{
				links->room->visited = 1;
				links->room->parent = room;
				if ((links->room->value == d) && ft_queue_clear(&queue))
					return (backtrack(graph, d));
				ft_queue_enqueue(&queue, ft_queue_new(links->room));
			}
			links = links->next;
		}
	}
	return (0);
}

t_room_bfs	*bfs_path_2(t_graph *graph, int s, int d)
{
	t_queue		*queue;
	t_room_bfs	*room;
	t_link_bfs	*links;

	queue = NULL;
	ft_queue_enqueue(&queue, ft_queue_new(get_room_id_bfs(graph->rooms, s)));
	queue->room->visited = 1;
	while (queue)
	{
		room = ft_queue_dequeue(&queue);
		links = room->links;
		while (links)
		{
			if (links->room->visited == 0 && links->capacity == 0
					&& links->room->blocked == 0 && (links->room->visited = 1))
			{
				links->room->parent = room;
				if ((links->room->value == d) && ft_queue_clear(&queue))
					return (backtrack_2(graph, s, d));
				ft_queue_enqueue(&queue, ft_queue_new(links->room));
			}
			links = links->next;
		}
	}
	return (NULL);
}
