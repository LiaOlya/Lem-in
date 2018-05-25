/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:13:48 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/07 13:13:49 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEMIN_H
# define __LEMIN_H

# include "libft/libft.h"

typedef	struct	s_link
{
	char			*s1;
	char			*s2;
	struct s_link	*next;
}				t_link;

typedef struct	s_out
{
	int				level;
	char			*str;
	struct s_out	*next;
}				t_out;

typedef	struct	s_node
{
	struct s_room	*rooms;
	struct s_node	*next;
}				t_node;

typedef struct	s_room
{
	int				end;
	int				start;
	char			*name;
	int				x;
	int				y;
	t_node			*nodes;
	int				id;
	struct s_room	*next;
}				t_room;

typedef	struct	s_route
{
	t_room			*rooms;
	struct s_route	*next;
}				t_route;

int				ft_get_dir(char *line, t_link **links);
int				ft_ch_num(int *num, t_out **out);
int				ft_cmd(char *line, t_room **rooms, int *ch, t_out **out);
void			ft_roomadd(t_room **rooms, int x, int y, char *name);
int				ft_get_coor(char *line, int *i);
int				ft_get_line(char **line);
int				ft_get_rooms(char *line, t_room **rooms, int ch);
int				ft_ch_se_coor(t_room *rooms);
int				ft_ch_end(t_room *end, t_room *room);
int				ft_ch_name(t_room *rooms, t_link *links);
void			ft_addline(t_out **out, char *line, int ch);
int				ft_comment(char **line, t_out **out, t_room **rooms, int k);
int				ft_h_ch(int *s1, int *s2, int s, int e);
int				ft_equal_con(t_link *links, char *r1, char *r2);
void			ft_search(t_room *rooms, t_route **route);
void			ft_move_start(t_room **rooms);
void			ft_move_end(t_room **rooms);
void			ft_get_id(t_room **rooms);
void			ft_s_e_error(int s1, int s2);
int				ft_double_name(t_room *rooms);
void			ft_get_nodes(t_room **rooms, t_link *links);
void			create_route(t_route **route, t_room *rooms);
void			ft_mark(t_room **rooms, char *name);
int				ft_room_h(char **tmp, int x, int y, int i);
void			ft_add_node(t_node **nodes, t_room *new);
void			ft_start_end(t_room **rooms, int ch);
void			ft_find_rooom(t_room **rooms, char *str);
void			ft_move_start(t_room **rooms);
void			ft_move_end(t_room **rooms);
int				ft_s_e(t_room **rooms, char **line, t_out **out, int i);
void			ft_del_out(t_out **out);
void			ft_del(t_room *rooms);
void			ft_del_links(t_link **links);
void			ft_del_rooms(t_room *rooms);
void			ft_del_routes(t_route *routes);
void			ft_print_out(t_out *out);
void			ft_print_routes(t_route *routes);
void			ft_end(t_room **end);
void			ft_get_last(t_room **rooms, t_room *r, t_route **tmp,
	t_route *t);
void			ft_finish(t_route **routes, t_room *end);
int				ft_read_h(t_room **rooms, char **line, t_out **out,
	t_link **links);
void			ft_move_all(t_route *route, int num);
void			ft_print_route(t_route *route);
void			ft_link_add(t_link **links, char *r1, char *r2);
int				ft_route_length(t_route *rooms);

#endif
