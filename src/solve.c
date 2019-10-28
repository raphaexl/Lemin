/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:10:11 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 19:36:34 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		solve(t_all *all)
{
	t_graph		*graph;
	t_room_bfs	*rooms;
	t_path		*paths;
	t_group		*groups;

	rooms = NULL;
	paths = NULL;
	groups = NULL;
	if ((graph = create_graph(all)) && ft_start_linked_end(all, graph->rooms))
		return ;
	while (bfs_path_1(graph, _START->id, _END->id))
	{
		reset_bfs_visited(graph->rooms);
		while ((rooms = bfs_path_2(graph, _START->id, _END->id)))
		{
			add_path_to_struct(&paths, create_new_path(rooms));
			reset_bfs_visited(graph->rooms);
			ft_room_bfs_free(&rooms);
		}
		add_group_to_struct(&groups,
				ft_evaluate_score(paths, _INPUT->count_ant));
		ft_path_free(&paths);
		reset_bfs_blocked(graph->rooms);
	}
	display(all, &groups, &graph);
}

t_graph		*create_graph(t_all *all)
{
	t_graph		*graph;
	t_room		*tmp_1;
	t_link		*tmp_2;

	tmp_1 = _ROOM;
	tmp_2 = _LINK;
	if (!(graph = malloc(sizeof(t_graph))))
		exit(-1);
	ft_memset(graph, 0, sizeof(t_graph));
	graph->rooms = NULL;
	while (tmp_1)
	{
		add_room_to_struct_bfs(&graph->rooms, create_new_room_bfs(tmp_1->id));
		tmp_1 = tmp_1->next;
	}
	while (tmp_2)
	{
		link_bfs(graph->rooms, tmp_2->first->id, tmp_2->second->id);
		link_bfs(graph->rooms, tmp_2->second->id, tmp_2->first->id);
		tmp_2 = tmp_2->next;
	}
	return (graph);
}

void		ft_graph_free(t_graph **graph)
{
	if (!graph || !*graph)
		return ;
	ft_room_bfs_free(&(*graph)->rooms);
	free(*graph);
}
