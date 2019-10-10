/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:52:28 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 16:22:52 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_prefix(t_tree *racine, void (*f)(t_tree *tree))
{
	if (racine)
	{
		f(racine);
		ft_tree_prefix(racine->left, (*f));
		ft_tree_prefix(racine->right, (*f));
	}
}
