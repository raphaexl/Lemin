/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:41:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 14:08:22 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	parse_output(t_all *all, t_group *group)
{
	t_path		*current;
	int			nbr_ant;

	nbr_ant = _INPUT->count_ant;
	while (_INPUT->count_ant > 0)
	{
		current = group->paths;
		while (current)
		{
			if (check_path(all, group, current))
			{
				add_ant_to_struct(current, (nbr_ant - _INPUT->count_ant + 1));
				_INPUT->count_ant--;
			}
			else
				break ;
			current = current->next;
		}
	}
	move_ant(group);
}

void	move_ant(t_group *group)
{
	t_path	*current;
	int		index;

	index = 0;
	while (group->paths->ant)
	{
		current = group->paths;
		while (current)
		{
			print(current);
			if (index > 0)
			{
				if (current->next != NULL)
					;
				else
					write(1, "\n", 1);
			}
			current = current->next;
		}
		index++;
	}
}

void	print(t_path *path)
{
	t_ant *current;

	current = path->ant;
	while (current)
	{
		if (current->pos == 0)
		{
			current->pos++;
			break ;
		}
		write(1, "L", 1);
		ft_putnbr(current->id);
		write(1, "-", 1);
		ft_putstr(path->way[current->pos]);
		write(1, " ", 1);
		current->pos++;
		current = current->next;
	}
	if (path->ant && path->ant->pos == path->depth + 1)
	{
		current = path->ant;
		path->ant = path->ant->next;
		free(current);
	}
}
