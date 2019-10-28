/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:34:48 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 12:41:01 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_group		*ft_evaluate_score(t_path *paths, int nb_ants)
{
	t_group		*group;
	int			flow;
	int			nb_rooms;

	if (!(group = malloc(sizeof(t_group))))
		exit(-1);
	group->paths = ft_group_paths(paths, nb_ants);
	flow = ft_paths_length(group->paths);
	group->max_depth = ft_paths_depth(paths);
	nb_rooms = group->max_depth - flow;
	group->score = ft_ceil((nb_ants + nb_rooms)) / (float)flow;
	group->next = NULL;
	return (group);
}

t_path		*ft_group_paths(t_path *paths, int nb_ants)
{
	t_path		*g_paths;
	int			score;
	int			cur_score;
	int			flow;
	int			nb_rooms;

	g_paths = NULL;
	flow = 1;
	score = -1;
	nb_rooms = ft_rooms_length(paths->rooms) - 2;
	cur_score = ft_ceil((nb_ants + nb_rooms)) / (float)flow;
	while (score < cur_score && paths)
	{
		add_path_to_struct(&g_paths, create_new_path(paths->rooms));
		if ((paths = paths->next))
		{
			flow += 1;
			nb_rooms = ft_rooms_length(paths->rooms) - 2;
			cur_score = score > 0 ? score : cur_score;
			score = ft_ceil((nb_ants + nb_rooms) / (float)flow);
		}
	}
	return (g_paths);
}
