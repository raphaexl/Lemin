/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_infix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:45:05 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 16:22:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_infix(t_tree *racine, void (*f)(t_tree *tree))
{
	if (racine)
	{
		ft_tree_infix(racine->left, (*f));
		f(racine);
		ft_tree_infix(racine->right, (*f));
	}
}
