/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:14:37 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 17:15:14 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		add_group_to_struct(t_group **groups, t_group *new)
{
	t_group	*p;

	if (!groups || !new)
		return ;
	if (!*groups)
		*groups = new;
	else
	{
		p = *groups;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

void		ft_group_free(t_group **groups)
{
	t_group *p;

	if (!groups || !*groups)
		return ;
	p = *groups;
	while (p)
	{
		(*groups) = (*groups)->next;
		if (p->paths)
			ft_path_free(&p->paths);
		free(p);
		p = (*groups);
	}
}
