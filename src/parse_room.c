/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 02:43:26 by kchahid           #+#    #+#             */
/*   Updated: 2019/10/28 20:01:30 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	parse_room(t_all *all)
{
	if (_INPUT->line[0] == '#')
	{
		if (ft_strcmp(_INPUT->line, "##start") == 0)
		{
			if (_TMP->index_start == 1 || _TMP->index_end == 1)
				error_all(all, 1);
			_TMP->index_start++;
		}
		if (ft_strcmp(_INPUT->line, "##end") == 0)
		{
			if (_TMP->index_end == 1 || _TMP->index_start == 1)
				error_all(all, 1);
			_TMP->index_end++;
		}
	}
	else if (_INPUT->line[0] != '#')
	{
		if (_TMP->index_start == 1 && (_TMP->index_start++))
			all->start = fill_room_struct(all);
		else if (_TMP->index_end == 1 && (_TMP->index_end++))
			all->end = fill_room_struct(all);
		else
			fill_room_struct(all);
	}
}

t_room	*fill_room_struct(t_all *all)
{
	t_room	*new;
	int		i;

	i = -1;
	new = new_room_struct(all);
	new->id = _INPUT->count_room;
	while (_INPUT->line[++i] && _INPUT->line[i] != ' ')
		check_link(all, i, 1);
	check_link(all, i, 3);
	new->name = ft_strsub(_INPUT->line, 0, i);
	new->x = ft_atoi(&_INPUT->line[i]);
	while (_INPUT->line[++i] && _INPUT->line[i] != ' ')
		;
	check_link(all, i, 3);
	new->y = ft_atoi(&_INPUT->line[i]);
	while (_INPUT->line[++i])
		check_link(all, i, 2);
	add_room_to_struct(all, new);
	_INPUT->count_room++;
	return (new);
}

void	check_link(t_all *all, int i, int index)
{
	if (index == 1)
	{
		if (_INPUT->line[i] < 33 || _INPUT->line[0] == 'L')
			error_all(all, 5);
	}
	if (index == 2)
	{
		if (_INPUT->line[i] == '-')
			i++;
		if (!ft_isdigit(_INPUT->line[i]))
			error_all(all, 5);
	}
	if (index == 3)
	{
		if (_INPUT->line[i] != ' ')
			error_all(all, 5);
	}
}

t_room	*new_room_struct(t_all *all)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		error_all(all, 4);
	new->x = 0;
	new->y = 0;
	new->id = 0;
	new->name = NULL;
	new->next = NULL;
	return (new);
}

void	add_room_to_struct(t_all *all, t_room *room)
{
	t_room *current_room;

	if (!_ROOM)
		_ROOM = room;
	else
	{
		current_room = _ROOM;
		if (!ft_strcmp(current_room->name, room->name))
			error_all(all, 5);
		while (current_room->next != NULL)
		{
			if (!ft_strcmp(current_room->name, room->name))
				error_all(all, 5);
			current_room = current_room->next;
		}
		if (!ft_strcmp(current_room->name, room->name))
			error_all(all, 5);
		current_room->next = room;
	}
}
