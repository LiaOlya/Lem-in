/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:55:44 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/13 10:55:45 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_help_add(t_room *tmp, char *s, t_node **nodes)
{
	ft_find_rooom(&tmp, s);
	ft_add_node(nodes, tmp);
}

void	ft_get_nodes(t_room **rooms, t_link *links)
{
	t_room *tmp;
	t_link *l;
	t_room *h;
	t_room *start;

	h = *rooms;
	while (h)
	{
		l = links;
		h->nodes = (t_node*)malloc(sizeof(t_node));
		h->nodes->next = NULL;
		while (l)
		{
			tmp = *rooms;
			if (ft_strcmp(l->s1, h->name) == 0)
				ft_help_add(tmp, l->s2, &(h->nodes));
			if (ft_strcmp(l->s2, h->name) == 0)
				ft_help_add(tmp, l->s1, &(h->nodes));
			l = l->next;
		}
		if (h->start == 1)
			start = h;
		h = h->next;
	}
}

void	create_route(t_route **route, t_room *rooms)
{
	t_room *add;

	add = NULL;
	*route = (t_route*)malloc(sizeof(t_route));
	ft_roomadd(&add, rooms->x, rooms->y, rooms->name);
	add->id = 1;
	(*route)->rooms = add;
	(*route)->next = NULL;
}

void	ft_mark(t_room **rooms, char *name)
{
	t_room *tmp;

	tmp = *rooms;
	while (*rooms)
	{
		if (ft_strcmp((*rooms)->name, name) == 0)
		{
			if ((*rooms)->end != 1)
				(*rooms)->id = 1;
			*rooms = tmp;
			return ;
		}
		(*rooms) = (*rooms)->next;
	}
	*rooms = tmp;
}
