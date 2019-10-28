/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 02:41:52 by kchahid           #+#    #+#             */
/*   Updated: 2019/10/28 20:02:12 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	parse_ant(t_all *all)
{
	int i;

	i = -1;
	if (_INPUT->line[0] == '#')
		return ;
	if (ft_strlen(_INPUT->line) > 9)
		error_all(all, 2);
	_INPUT->count_ant = ft_atoi(_INPUT->line);
	if (_INPUT->count_ant > 0)
	{
		while (_INPUT->line[++i] != '\0')
		{
			if (!ft_isdigit(_INPUT->line[i]))
				error_all(all, 2);
		}
	}
	else
		error_all(all, 2);
}
