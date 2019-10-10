/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:43:07 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 11:57:22 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_treelen(t_tree *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + ft_treelen(tree->left) + ft_treelen(tree->right));
}
