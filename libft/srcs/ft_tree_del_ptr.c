/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_del_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:49:34 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 11:56:46 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_del_ptr(t_tree **tree)
{
	if (*tree)
	{
		ft_tree_del_ptr(&((*tree)->left));
		ft_tree_del_ptr(&((*tree)->right));
		free(*tree);
	}
}
