/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_add_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:38:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 11:55:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tree_add_sorted(t_tree **tree, void *content,
		int (*sort)(void*, void *))
{
	if (*tree == NULL)
	{
		if (!(*tree = ft_tree_new_ptr(content)))
			return (1);
		else
			return (0);
	}
	else
	{
		if (sort((*tree)->content, content) > 0)
			return (ft_tree_add_sorted(&((*tree)->left), content, sort));
		else
			return (ft_tree_add_sorted(&((*tree)->right), content, sort));
	}
}
