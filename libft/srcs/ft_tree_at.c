/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:41:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 16:22:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tree_at_infix_process(t_tree *tree, int *index)
{
	void	*res;

	if (tree != NULL)
	{
		if ((res = ft_tree_at_infix_process(tree->left, index)))
			return (res);
		if (*index == 0)
			return (tree->content);
		*index -= 1;
		if ((res = ft_tree_at_infix_process(tree->right, index)))
			return (res);
	}
	return (NULL);
}

void		*ft_tree_at_infix(t_tree *tree, int index)
{
	return (ft_tree_at_infix_process(tree, &index));
}
