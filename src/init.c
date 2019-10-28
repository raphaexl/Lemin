/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 02:38:49 by kchahid           #+#    #+#             */
/*   Updated: 2019/10/28 14:09:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	init_all(t_all *all)
{
	if (!(_INPUT = (t_input *)malloc(sizeof(t_input))))
		error_all(all, 3);
	if (!(_TMP = (t_tmp*)malloc(sizeof(t_tmp))))
		error_all(all, 3);
	_INPUT->count_ant = 0;
	_INPUT->count_link = 0;
	_INPUT->count_room = 0;
	_TMP->index_start = 0;
	_TMP->index_end = 0;
	_ROOM = NULL;
	_LINK = NULL;
	_START = NULL;
	_END = NULL;
	_TMP->first = NULL;
	_TMP->second = NULL;
	all->output = NULL;
}

int		parse_input(t_all *all)
{
	int index;

	index = -1;
	while ((index = read_line(&_INPUT->line, STDIN)))
	{
		if (_INPUT->count_ant == 0)
			parse_ant(all);
		else if (ft_strchr(_INPUT->line, '-'))
		{
			if (_INPUT->line[0] == '#')
				continue;
			if (case_neg(all) == 1)
				parse_room(all);
			else
				parse_link(all);
		}
		else
			parse_room(all);
		ft_output_push_back(&all->output, _INPUT->line);
	}
	if (index == -1)
		error_all(all, 0);
	if (_TMP->index_start != 2 || _TMP->index_end != 2)
		error_all(all, 1);
	return (ft_output_display(all->output));
}

int		case_neg(t_all *all)
{
	int i;

	i = -1;
	while (_INPUT->line[++i])
	{
		if (_INPUT->line[i] == '-' && _INPUT->line[i - 1] == ' ')
			return (1);
	}
	return (0);
}
