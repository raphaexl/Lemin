/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:58:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/30 17:51:39 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_turn_split(char ***tab, int ret)
{
	int		i;

	i = 0;
	while ((*tab)[i])
		free((*tab)[i++]);
	free(*tab);
	*tab = NULL;
	return (ret);
}

int		ft_free_turn_splits(char ***tab1, char ***tab2, int ret)
{
	int		i;

	i = 0;
	while ((*tab1)[i])
		free((*tab1)[i++]);
	free(*tab1);
	*tab1 = NULL;
	i = 0;
	while ((*tab2)[i])
		free((*tab2)[i++]);
	free(*tab2);
	*tab2 = NULL;
	return (ret);
}

char	*ft_free_turn_strs(char **to_del, char **to_del2, char *res)
{
	ft_strdel(to_del);
	ft_strdel(to_del2);
	return (res);
}

char	*ft_free_turn_str(char **to_del, char *res)
{
	ft_strdel(to_del);
	return (res);
}

int		ft_free_turn(void *str, int ret)
{
	free(str);
	return (ret);
}
