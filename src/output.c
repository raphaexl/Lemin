/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:20:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 14:09:51 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	ft_output_push_back(t_output **lst, char *str)
{
	t_output	*p;
	t_output	*new;

	if (!(new = malloc(sizeof(t_output))))
		return ;
	new->str = str;
	new->next = NULL;
	if (!lst)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

int		ft_output_display(t_output *p)
{
	while (p)
	{
		ft_putendl(p->str);
		p = p->next;
	}
	return (write(1, "\n", 1));
}

void	ft_output_clean(t_output **lst)
{
	t_output	*p;

	if (!lst)
		return ;
	p = (*lst);
	while (p)
	{
		(*lst) = (*lst)->next;
		if (p->str)
			free(p->str);
		free(p);
		p = (*lst);
	}
}
