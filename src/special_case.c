/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:23:38 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 15:57:39 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		ft_special_display(t_all *all)
{
	int		i;

	i = 0;
	while (++i <= _INPUT->count_ant)
	{
		write(1, "L", 1);
		ft_putnbr(i);
		write(1, "-", 1);
		ft_putstr(get_room_name(all, _END->id));
		write(1, "\n", 1);
	}
	return (1);
}

int		ft_start_linked_end(t_all *all, t_room_bfs *rooms)
{
	t_room_bfs	*dest;
	t_link_bfs	*links;

	dest = get_room_id_bfs(rooms, _END->id);
	links = get_room_id_bfs(rooms, _START->id)->links;
	while (links && links->room != dest)
		links = links->next;
	if (links && links->room == dest)
		return (ft_special_display(all));
	else
		return (0);
}
