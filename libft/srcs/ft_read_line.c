/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:37:07 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/08 13:40:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_read_line(const int fd)
{
	char	*line;

	if (ft_get_next_line(fd, &line) == 1 && line)
		return (line);
	return (NULL);
}

