/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_path2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:17:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 17:31:32 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_path		*ft_paths_copy(t_path *paths)
{
	t_path	*path;

	path = 0;
	while (paths)
	{
		add_path_to_struct(&path, create_new_path(paths->rooms));
		paths = paths->next;
	}
	return (path);
}

t_room_bfs	*ft_rooms_copy(t_room_bfs *rooms)
{
	t_room_bfs	*path;

	path = NULL;
	while (rooms)
	{
		add_room_to_struct_bfs(&path, create_new_room_bfs(rooms->value));
		rooms = rooms->next;
	}
	return (path);
}
