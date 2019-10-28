/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:54:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/28 14:42:32 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define STDIN 0

# define _INPUT (all->input)
# define _ROOM (all->room)
# define _START (all->start)
# define _END (all->end)
# define _TMP (all->tmp)
# define _LINK (all->link)

typedef struct s_all			t_all;
typedef struct s_input			t_input;
typedef struct s_room			t_room;
typedef struct s_link			t_link;
typedef struct s_tmp			t_tmp;
typedef struct s_link_bfs		t_link_bfs;
typedef struct s_room_bfs		t_room_bfs;
typedef struct s_queue			t_queue;
typedef struct s_path			t_path;
typedef struct s_group			t_group;
typedef struct s_graph			t_graph;
typedef struct s_ant			t_ant;
typedef struct s_output			t_output;

struct			s_tmp
{
	int			index_start;
	int			index_end;
	char		*first;
	char		*second;
};

struct			s_input
{
	char		*line;
	int			count_ant;
	int			count_link;
	int			count_room;
};

struct			s_output
{
	char		*str;
	t_output	*next;
};

struct			s_room
{
	char		*name;
	int			x;
	int			y;
	int			id;
	t_room		*next;
};

struct			s_link
{
	t_room			*first;
	t_room			*second;
	t_link			*next;
};

struct			s_all
{
	t_input			*input;
	t_output		*output;
	t_link			*link;
	t_room			*room;
	t_room			*start;
	t_room			*end;
	t_tmp			*tmp;
};

struct			s_ant
{
	int				pos;
	int				id;
	t_ant			*next;
};

struct			s_room_bfs
{
	int				value;
	int				visited;
	int				blocked;
	t_link_bfs		*links;
	t_room_bfs		*next;
	t_room_bfs		*parent;
};

struct			s_link_bfs
{
	t_room_bfs		*room;
	int				capacity;
	int				blocked;
	t_link_bfs		*next;
};

struct			s_queue
{
	t_room_bfs		*room;
	t_queue			*next;
};

struct			s_path
{
	int				depth;
	char			**way;
	int				ant_index;
	t_room_bfs		*rooms;
	t_ant			*ant;
	t_path			*next;
};

struct			s_group
{
	t_path			*paths;
	int				score;
	int				max_depth;
	t_group			*next;
};

struct			s_graph
{
	t_room_bfs		*rooms;
};

void			init_all(t_all *all);
void			free_env(t_all *all);
int				parse_input(t_all *all);
void			parse_ant(t_all *all);
void			parse_link(t_all *all);
t_link			*fill_link_struct(t_all *all);
t_room			*fill_link_name(t_all *all, char *s);
void			add_link_to_struct(t_all *all, t_link *link);
void			split_name(t_all *all);
void			parse_room(t_all *all);
t_room			*new_room_struct(t_all *all);
void			check_link(t_all *all, int i, int index);
t_room			*fill_room_struct(t_all *all);
void			add_room_to_struct(t_all *all, t_room *room);
int				get_room_id(t_all *all, t_room *room);
char			*get_room_name(t_all *all, int current_id);
int				read_line(char **line, int fd);
void			solve(t_all *all);
t_graph			*create_graph(t_all *all);
void			ft_graph_free(t_graph **graph);
t_room_bfs		*create_new_room_bfs(int id_room);
void			add_room_to_struct_bfs(t_room_bfs **rooms, t_room_bfs *new);
t_room_bfs		*get_room_id_bfs(t_room_bfs *rooms, int id);
int				ft_rooms_length(t_room_bfs *rooms);
t_room_bfs		*ft_rooms_copy(t_room_bfs *rooms);
t_room_bfs		*get_room_id_bfs(t_room_bfs *rooms, int id);
void			ft_room_bfs_free(t_room_bfs **rooms);
void			link_bfs(t_room_bfs *rooms, int f, int	s);
t_link_bfs		*create_new_link_bfs(t_room_bfs *room);
void			add_link_to_struct_bfs(t_link_bfs **links, t_link_bfs *new);
void			ft_link_bfs_free(t_link_bfs **links);
void			add_group_to_struct(t_group **groups, t_group *new);
int				bfs_path_1(t_graph *graph, int	s, int d);
t_room_bfs		*bfs_path_2(t_graph *graph, int	s, int d);
void			reset_bfs_blocked(t_room_bfs *rooms);
void			reset_bfs_visited(t_room_bfs *rooms);
t_queue			*ft_queue_new(t_room_bfs *room);
void			ft_queue_enqueue(t_queue **queue, t_queue *new);
t_room_bfs		*ft_queue_dequeue(t_queue **queue);
int				ft_queue_clear(t_queue **queue);
t_group			*ft_evaluate_score(t_path *paths, int nb_ants);
t_path			*ft_group_paths(t_path *paths, int nb_ants);
void			ft_group_free(t_group **groups);
int				backtrack(t_graph *graph, int d);
t_room_bfs		*backtrack_2(t_graph *graph, int	s, int d);
void			edit_capacity(t_room_bfs *curr, t_room_bfs *prev, int v);
void			edit_blocked(t_room_bfs *curr, t_room_bfs *prev, int v);
t_path			*create_new_path(t_room_bfs *rooms);
void			add_path_to_struct(t_path **paths, t_path *new);
t_path			*ft_paths_copy(t_path *paths);
int				ft_paths_length(t_path *paths);
int				ft_paths_depth(t_path *paths);
void			ft_path_free(t_path **paths);
void			ft_room_print(t_all *all, t_room_bfs *room);
void			display(t_all *all, t_group **group, t_graph **graph);
void			print_sol_str(t_all *all, t_group *group);
int				find_group(t_group *group);
void			change_tab(t_group *g, int tab[]);
void			parse_output(t_all *all, t_group *group);
int				check_path(t_all *all, t_group *group, t_path *path);
void			add_ant_to_struct(t_path *path, int ant_id);
t_ant			*create_ant(int ant_id);
void			move_ant(t_group *group);
void			ft_ant_free(t_ant **ants);
void			ft_way_free(char ***ways);
void			print(t_path *path);
void			error_all(t_all *all, int index);
int				case_neg(t_all *all);
int				ft_start_linked_end(t_all *all, t_room_bfs *rs);
long int		ft_ceil(float f);
void			ft_output_push_back(t_output **lst, char *str);
int				ft_output_display(t_output *p);
void			ft_output_clean(t_output **lst);
#endif
