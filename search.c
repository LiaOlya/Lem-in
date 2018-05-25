/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:59:34 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/09 11:59:34 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_add_r_b(t_room **room, int x, int y, char *name)
{
	t_room *head;

	if (!(*room))
	{
		*room = (t_room*)malloc(sizeof(t_room));
		(*room)->x = x;
		(*room)->y = y;
		(*room)->name = ft_strdup(name);
		(*room)->next = NULL;
		return ;
	}
	head = *room;
	while (head->next)
		head = head->next;
	head->next = (t_room*)malloc(sizeof(t_room));
	head->next->x = x;
	head->next->y = y;
	head->next->name = ft_strdup(name);
	head->next->next = NULL;
}

void	add_new_route(t_route **route, t_room *rooms, t_room **r)
{
	t_room	*add;
	t_route	*head;
	t_room	*tmp;

	head = *route;
	while (head->next)
		head = head->next;
	head->next = (t_route*)malloc(sizeof(t_route));
	add = NULL;
	tmp = (*route)->rooms;
	while (tmp)
	{
		ft_add_r_b(&add, tmp->x, tmp->y, tmp->name);
		tmp = tmp->next;
	}
	ft_add_r_b(&add, rooms->x, rooms->y, rooms->name);
	head->next->rooms = add;
	ft_mark(r, rooms->name);
	head->next->next = NULL;
}

void	ft_nodes(char *name, t_room *rooms, t_node **nodes)
{
	while (rooms)
	{
		if (ft_strcmp(name, rooms->name) == 0)
		{
			*nodes = rooms->nodes;
			return ;
		}
		rooms = rooms->next;
	}
}

int		ft_ch_id(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strcmp(rooms->name, name) == 0)
		{
			if (rooms->id == 0)
				return (1);
			return (0);
		}
		rooms = rooms->next;
	}
	return (0);
}

void	ft_search(t_room *rooms, t_route **route)
{
	t_node	*nodes;
	t_route *res;
	t_room	*tmp;

	res = NULL;
	rooms->id = 1;
	create_route(&res, rooms);
	*route = res;
	while (res)
	{
		tmp = res->rooms;
		while (tmp->next)
			tmp = tmp->next;
		if (ft_ch_end(tmp, rooms) != 1)
		{
			ft_nodes(tmp->name, rooms, &nodes);
			while (nodes->next)
			{
				if (ft_ch_id(rooms, nodes->rooms->name) == 1)
					add_new_route(&res, nodes->rooms, &rooms);
				nodes = nodes->next;
			}
		}
		res = res->next;
	}
}
