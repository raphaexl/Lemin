/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:10:25 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 14:50:48 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	display(t_all *all, t_group **groups, t_graph **graph)
{
	t_group *g;
	int		num_group;

	if (!(*groups))
	{
		ft_putendl("NO PATH COULD BE FOUND");
		ft_group_free(groups);
		return ;
	}
	g = (*groups);
	num_group = find_group((*groups));
	while (g)
	{
		num_group--;
		if (num_group == 0)
			break ;
		g = g->next;
	}
	print_sol_str(all, g);
	parse_output(all, g);
	ft_group_free(groups);
	ft_graph_free(graph);
}

void	print_sol_str(t_all *all, t_group *group)
{
	t_path		*tmp;
	t_room_bfs	*r;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = group->paths;
	while (tmp)
	{
		tmp->way = malloc(sizeof(char *) * (tmp->depth + 2));
		r = tmp->rooms;
		j = tmp->depth + 1;
		while (r)
		{
			tmp->way[--j] = get_room_name(all, r->value);
			r = r->next;
		}
		tmp->way[tmp->depth + 1] = NULL;
		i++;
		tmp = tmp->next;
	}
}

int		find_group(t_group *groups)
{
	t_group *g;
	int		tab[5];

	g = groups;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = g->score;
	tab[4] = g->max_depth;
	while (g)
	{
		tab[0] = 0;
		tab[2]++;
		change_tab(g, tab);
		g = g->next;
	}
	return (tab[1]);
}

void	change_tab(t_group *g, int tab[])
{
	if ((tab[3] > g->score) && (tab[0] = 1) && (tab[1]++))
	{
		tab[3] = g->score;
		tab[4] = g->max_depth;
		tab[1] = tab[1] + (tab[2] - tab[1]);
	}
	if ((tab[3] == g->score) && (tab[0] != 1))
	{
		if (tab[4] >= g->max_depth && (tab[1]++))
		{
			tab[3] = g->score;
			tab[4] = g->max_depth;
		}
	}
}
