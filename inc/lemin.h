/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:54:15 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/10 12:29:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/incs/libft.h"

# define MALLOC_ERR -2

typedef struct	s_lemin
{
	int			nbr_ant;
	int			nbr_room;
	int			nbr_link;
	int			index_start;
	int			index_end;
	int			index;
	int			index_p;
	int			x;
	int			y;
	int			i;
	int			j;
	int			m;
	int			change;
	char		*line;
	char		**map;
	char		*room;
	char		**room_name;
	char		*link;
}				t_lemin;

int				ft_lemin_link_format(char  *line);
int				ft_lemin_room_format(char  **line);

int				parse_input(t_lemin *lem);
int				parse_ant(t_lemin *lem);
int				parse_links(t_lemin *lem);
int				parse_room(t_lemin *lem);
int				parse_map(t_lemin *lem);
int				parse_map(t_lemin *lem);
int				ft_check_map(t_lemin *lem);

void			ft_lemin_init(t_lemin *lem);

int				ft_lemin_matrix_init(t_lemin *lem);
int				ft_lemin_matrix(t_lemin *lem);

int				ft_solve(t_lemin *lem);
int				ft_solve_init(t_lemin *lem);
void			ft_display_map(t_lemin *lem);
void			ft_check_fisrt_room(t_lemin *lem, int index);
void			ft_check_last_room(t_lemin *lem, int index);
int				ft_change_path(t_lemin *lem, int index);
void			ft_check_all(t_lemin *lem, int index);

#endif
