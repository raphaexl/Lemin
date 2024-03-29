/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:36:44 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 13:16:21 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		main(void)
{
	t_all all;

	init_all(&all);
	if (parse_input(&all) == 0)
		error_all(&all, 0);
	solve(&all);
	free_env(&all);
	return (0);
}
