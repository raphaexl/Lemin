/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:03:01 by kchahid           #+#    #+#             */
/*   Updated: 2019/10/20 20:03:03 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static int	ft_get_nline(char **line, int fd)
{
	char	buf[2];
	char	*temp;
	int		ret;
	int		ret_add;

	ret_add = 0;
	if (!(*line = ft_strnew(1)))
		return (0);
	while ((ret = read(fd, buf, 1)))
	{
		ret_add = ret + ret_add;
		buf[ret] = '\0';
		temp = *line;
		if (!(ft_isascii(buf[0])) || !(*line = ft_strjoin(*line, buf)))
		{
			ft_strdel(&temp);
			return (0);
		}
		ft_strdel(&temp);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	line[0][ret_add - 1] = '\0';
	return (ret_add);
}

int			read_line(char **line, int fd)
{
	int		i;

	i = 0;
	i = ft_get_nline(line, fd);
	return (i);
}
