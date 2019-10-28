/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:38:51 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 17:39:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	reset_bfs_blocked(t_room_bfs *rooms)
{
	t_link_bfs	*links;

	while (rooms)
	{
		rooms->visited = 0;
		rooms->blocked = 0;
		links = rooms->links;
		while (links)
		{
			links->room->blocked = 0;
			links->blocked = 0;
			links = links->next;
		}
		rooms = rooms->next;
	}
}

void	reset_bfs_visited(t_room_bfs *rooms)
{
	while (rooms)
	{
		rooms->visited = 0;
		rooms = rooms->next;
	}
}
