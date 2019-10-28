/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 02:42:21 by kchahid           #+#    #+#             */
/*   Updated: 2019/10/28 13:53:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	parse_link(t_all *all)
{
	t_link *new;

	if (_TMP->index_start == 1 || _TMP->index_end == 1)
		error_all(all, 1);
	split_name(all);
	new = fill_link_struct(all);
	add_link_to_struct(all, new);
	_INPUT->count_link++;
}

void	split_name(t_all *all)
{
	int i;
	int tmp;

	i = -1;
	if (_TMP->first)
		ft_strdel(&_TMP->first);
	if (_TMP->second)
		ft_strdel(&_TMP->second);
	_TMP->first = NULL;
	_TMP->second = NULL;
	while (_INPUT->line[++i] && _INPUT->line[i] != '-')
	{
		if (_INPUT->line[i] < 33)
			error_all(all, 4);
	}
	_TMP->first = ft_strsub(_INPUT->line, 0, i);
	tmp = i;
	while (_INPUT->line[++i])
	{
		if (_INPUT->line[i] == '-' || _INPUT->line[i] < 33)
			error_all(all, 4);
	}
	_TMP->second = ft_strsub(_INPUT->line, tmp + 1, (i - tmp));
}

t_link	*fill_link_struct(t_all *all)
{
	t_link *new;

	if (!(new = (t_link *)malloc(sizeof(t_link))))
		error_all(all, 3);
	new->first = fill_link_name(all, _TMP->first);
	new->second = fill_link_name(all, _TMP->second);
	new->next = NULL;
	return (new);
}

t_room	*fill_link_name(t_all *all, char *s)
{
	t_room *current;

	current = all->room;
	while (current && !ft_strequ(current->name, s))
		current = current->next;
	if (current == NULL)
		error_all(all, 6);
	return (current);
}

void	add_link_to_struct(t_all *all, t_link *link)
{
	t_link *current;

	if (!_LINK)
		_LINK = link;
	else
	{
		current = _LINK;
		while (current->next)
			current = current->next;
		if (current)
			current->next = link;
	}
}
