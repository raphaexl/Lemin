/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:47:48 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 15:50:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_queue		*ft_queue_new(t_room_bfs *room)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	if (new == NULL)
		exit(-1);
	if (room == NULL)
		new->room = NULL;
	else
		new->room = room;
	new->next = NULL;
	return (new);
}

void		ft_queue_enqueue(t_queue **queue, t_queue *new)
{
	t_queue	*p;

	if (!queue || !new)
		return ;
	else if (!*queue)
		*queue = new;
	else
	{
		p = (*queue);
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

t_room_bfs	*ft_queue_dequeue(t_queue **queue)
{
	t_queue		*node;
	t_room_bfs	*rooms;

	if (!(*queue))
		return (NULL);
	node = (*queue);
	rooms = node->room;
	(*queue) = (*queue)->next;
	free(node);
	return (rooms);
}

int			ft_queue_clear(t_queue **queue)
{
	t_queue		*p;

	p = (*queue);
	while (p)
	{
		(*queue) = (*queue)->next;
		free(p);
		p = (*queue);
	}
	return (1);
}
