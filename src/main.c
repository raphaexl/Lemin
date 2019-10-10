/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:11:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 12:35:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	ft_lemin_display(t_lemin *lem)
{
	int		i;
	int		j;

	ft_printf("====map===\n");
	i = -1;
	ft_printf("\t");
	while (++i < lem->nbr_room)
		ft_printf("%s ", lem->room_name[i]);
	ft_printf("\n\n");
	i = -1;
	while (++i < lem->nbr_room)
	{
		ft_printf("%s\t", lem->room_name[i]);
		j = -1;
		while (++j < lem->nbr_room)
			ft_printf("%d ", lem->map[i][j]);
		ft_printf("\n");
	}
}

int		main(void)
{
	t_lemin lem;

	ft_lemin_init(&lem);
	if (parse_input(&lem) == -1)
		ft_printf("ERROR _PARSE\n");
	if (ft_lemin_matrix_init(&lem))
		ft_printf("ERROR _INIT_MATRIX\n");
	if (ft_lemin_matrix(&lem))
		ft_printf("ERROR _MATRIX\n");
	ft_lemin_display(&lem);
	//ft_quit_lemin(&lem);
	return (0);
}
