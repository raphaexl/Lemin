/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:42:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/27 18:55:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		add_ant_to_struct(t_path *path, int ant_id)
{
	t_ant *new;
	t_ant *current;

	new = create_ant(ant_id);
	if (!path)
		return ;
	if (!path->ant)
		path->ant = new;
	else
	{
		current = path->ant;
		while (current->next)
			current = current->next;
		if (current)
			current->next = new;
	}
}

t_ant		*create_ant(int ant_id)
{
	t_ant *new;

	if (!(new = malloc(sizeof(t_ant))))
		exit(-1);
	new->pos = 0;
	new->id = ant_id;
	new->next = NULL;
	return (new);
}

int			check_path(t_all *all, t_group *group, t_path *path)
{
	t_path	*current;
	int		sum;

	sum = 0;
	(void)all;
	current = group->paths;
	if (_INPUT->count_ant <= path->depth - group->paths->depth)
		return (0);
	while (current != path)
	{
		sum = sum + (path->depth - current->depth);
		current = current->next;
	}
	if (_INPUT->count_ant > sum)
		return (1);
	return (0);
}

void		ft_ant_free(t_ant **ants)
{
	t_ant *p;

	p = *ants;
	while (p)
	{
		(*ants) = (*ants)->next;
		free(p);
		p = (*ants);
	}
}
