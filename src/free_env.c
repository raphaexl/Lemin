/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:10:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 15:57:53 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		ft_free_room(t_room **room)
{
	if (!room || !*room)
		return ;
	if ((*room)->name)
		ft_strdel(&(*room)->name);
	free((*room));
}

void		ft_free_rooms(t_room **rooms)
{
	t_room	*p;

	p = (*rooms);
	while (p)
	{
		(*rooms) = (*rooms)->next;
		ft_free_room(&p);
		p = (*rooms);
	}
}

void		ft_free_links(t_link **links)
{
	t_link	*p;

	p = (*links);
	while (p)
	{
		(*links) = (*links)->next;
		free(p);
		p = (*links);
	}
}

void		free_env(t_all *all)
{
	ft_strdel(&all->input->line);
	ft_output_clean(&all->output);
	ft_free_links(&all->link);
	ft_free_rooms(&all->room);
	ft_strdel(&all->tmp->second);
	ft_strdel(&all->tmp->first);
	free(all->input);
	free(all->tmp);
}
