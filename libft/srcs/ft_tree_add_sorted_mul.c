/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_add_sorted_mul.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:44:28 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 11:55:28 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tree_add_sorted_mul(t_tree **tree, void *content,
		int (*sort)(void*, void *), int mul)
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
		if (mul * sort((*tree)->content, content) > 0)
			return (ft_tree_add_sorted_mul(&((*tree)->left),
						content, sort, mul));
		else
			return (ft_tree_add_sorted_mul(&((*tree)->right),
						content, sort, mul));
	}
}
