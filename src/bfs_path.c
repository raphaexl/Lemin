/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:15:24 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 20:49:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_path		*create_new_path(t_room_bfs *rooms)
{
	t_path	*path;

	if ((path = malloc(sizeof(t_path))))
	{
		path->ant = NULL;
		path->ant_index = 0;
		path->way = NULL;
		path->rooms = ft_rooms_copy(rooms);
		path->depth = ft_rooms_length(rooms) - 1;
		path->next = NULL;
	}
	else
		exit(-1);
	return (path);
}

void		add_path_to_struct(t_path **paths, t_path *new)
{
	t_path	*p;

	if (!paths || !new)
		return ;
	if (!*paths)
		*paths = new;
	else
	{
		p = *paths;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

int			ft_paths_length(t_path *paths)
{
	if (!paths)
		return (0);
	return (1 + ft_paths_length(paths->next));
}

int			ft_paths_depth(t_path *paths)
{
	int		depth;

	depth = 0;
	while (paths)
	{
		depth += paths->depth;
		paths = paths->next;
	}
	return (depth);
}

void		ft_path_free(t_path **paths)
{
	t_path *p;

	if (!paths || !*paths)
		return ;
	p = *paths;
	while (p)
	{
		(*paths) = (*paths)->next;
		if (p->rooms)
			ft_room_bfs_free(&p->rooms);
		if (p->ant)
			ft_ant_free(&p->ant);
		if (p->way)
			ft_way_free(&p->way);
		free(p);
		p = (*paths);
	}
}
