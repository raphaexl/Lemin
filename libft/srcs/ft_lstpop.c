/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:43:36 by ebatchas          #+#    #+#             */
/*   Updated: 2019/08/09 10:59:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **lst)
{
	void	*content;
	t_list	*p;

	if (*lst)
	{
		p = *lst;
		content = p->content;
		*lst = (*lst)->next;
		free(p);
		return (content);
	}
	return (NULL);
}
