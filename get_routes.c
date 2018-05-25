/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_routes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:25:18 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/13 21:25:19 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_routes(t_route *routes)
{
	t_room *rooms;

	while (routes)
	{
		rooms = routes->rooms;
		while (rooms)
		{
			write(1, rooms->name, ft_strlen(rooms->name));
			if (rooms->next)
				write(1, "->", 2);
			rooms = rooms->next;
		}
		write(1, "\n", 1);
		routes = routes->next;
	}
	write(1, "\n", 1);
}

void	ft_end(t_room **end)
{
	while (*end)
	{
		if ((*end)->end == 1)
			return ;
		(*end) = (*end)->next;
	}
}

void	ft_get_last(t_room **rooms, t_room *r, t_route **tmp, t_route *t)
{
	*rooms = r;
	while ((*rooms)->next)
		*rooms = (*rooms)->next;
	if (tmp)
		*tmp = t;
}

void	ft_h_finsh(t_room *rooms, t_route **routes, t_route *head, char *end)
{
	t_route *tmp;
	t_route	*t;
	t_route *r;

	r = *routes;
	while (r->next)
	{
		head = r;
		tmp = r->next;
		ft_get_last(&rooms, tmp->rooms, NULL, NULL);
		while (ft_strcmp(rooms->name, end) != 0)
		{
			t = tmp->next;
			ft_del_rooms(tmp->rooms);
			free(tmp);
			head->next = t;
			if (!t)
			{
				r->next = NULL;
				return ;
			}
			ft_get_last(&rooms, t->rooms, &tmp, t);
		}
		r = head->next;
	}
}

void	ft_finish(t_route **routes, t_room *end)
{
	t_route	*head;
	t_room	*rooms;
	t_route	*tmp;

	ft_end(&end);
	head = NULL;
	rooms = (*routes)->rooms;
	while (ft_strcmp(rooms->name, end->name) != 0)
	{
		tmp = (*routes)->next;
		if (!tmp)
		{
			*routes = NULL;
			return ;
		}
		ft_del_rooms((*routes)->rooms);
		free(*routes);
		*routes = tmp;
		ft_get_last(&rooms, (*routes)->rooms, NULL, NULL);
	}
	ft_get_last(&rooms, (*routes)->rooms, NULL, NULL);
	ft_h_finsh(rooms, routes, head, end->name);
}
