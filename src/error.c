/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:08:09 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 02:38:25 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	error_all(t_all *all, int index)
{
	free_env(all);
	if (index == 0)
		ft_putstr("READ_FILE_ERROR\n");
	if (index == 1)
		ft_putstr("START_END_ERROR\n");
	if (index == 2)
		ft_putstr("PARSE_ANT_ERROR\n");
	if (index == 3)
		ft_putstr("MALLOC_ERROR\n");
	if (index == 4)
		ft_putstr("LINK_ERROR\n");
	if (index == 5)
		ft_putstr("ROOM_ERROR\n");
	if (index == 6)
		ft_putstr("NO ROOM OF LINK\n");
	exit(-1);
}
