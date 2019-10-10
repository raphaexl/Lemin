/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:45:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 12:31:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_del(t_tree **tree, void (*free_func)(void *))
{
	if (*tree)
	{
		ft_tree_del(&((*tree)->left), free_func);
		ft_tree_del(&((*tree)->right), free_func);
		free_func((*tree)->content);
		free(*tree);
	}
}
