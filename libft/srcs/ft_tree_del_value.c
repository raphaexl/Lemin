/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_del_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:50:20 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 11:56:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tree_del_value(t_tree **tree)
{
	if (*tree)
	{
		ft_tree_del_value(&((*tree)->left));
		ft_tree_del_value(&((*tree)->right));
		free((*tree)->content);
		free(*tree);
	}
}
