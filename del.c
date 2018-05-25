/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:59:33 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/13 10:59:34 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_del(t_room *rooms)
{
	t_node	*l;
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		rooms = tmp->next;
		while (tmp->nodes)
		{
			l = tmp->nodes;
			tmp->nodes = l->next;
			free(l);
		}
		ft_strdel(&(tmp->name));
		free(tmp);
		tmp = rooms;
	}
}

void	ft_del_out(t_out **out)
{
	t_out *tmp;

	tmp = *out;
	while (tmp)
	{
		*out = tmp->next;
		ft_strdel(&(tmp->str));
		free(tmp);
		tmp = NULL;
		tmp = *out;
	}
}

void	ft_del_links(t_link **links)
{
	t_link *l;

	l = *links;
	while (l)
	{
		*links = l->next;
		ft_strdel(&(l->s1));
		ft_strdel(&(l->s2));
		free(l);
		l = NULL;
		l = *links;
	}
}

void	ft_del_rooms(t_room *rooms)
{
	t_room *tmp;

	while (rooms)
	{
		tmp = rooms->next;
		ft_strdel(&(rooms->name));
		free(rooms);
		rooms = tmp;
	}
}

void	ft_del_routes(t_route *routes)
{
	t_route *tmp;

	while (routes)
	{
		tmp = routes->next;
		ft_del_rooms(routes->rooms);
		free(routes);
		routes = tmp;
	}
}
