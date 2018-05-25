/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 12:01:54 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/12 12:01:55 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_start_end(t_room **rooms, int ch)
{
	if (ch == 1)
		(*rooms)->start = 1;
	if (ch == 2)
		(*rooms)->end = 1;
}

void	ft_find_rooom(t_room **rooms, char *str)
{
	while (*rooms)
	{
		if (ft_strcmp((*rooms)->name, str) == 0)
			return ;
		(*rooms) = (*rooms)->next;
	}
}

void	ft_add_node(t_node **nodes, t_room *new)
{
	t_node	*tmp;

	if (!(*nodes))
	{
		*nodes = (t_node*)malloc(sizeof(t_node));
		(*nodes)->rooms = new;
		(*nodes)->next = NULL;
		return ;
	}
	tmp = (t_node*)malloc(sizeof(t_node));
	tmp->rooms = new;
	tmp->next = *nodes;
	*nodes = tmp;
}

void	ft_move_start(t_room **rooms)
{
	t_room	*start;
	t_room	*tmp;
	t_room	*head;

	if (!(*rooms) || !(*rooms)->next)
		return ;
	if ((*rooms)->start == 1)
		return ;
	tmp = *rooms;
	head = *rooms;
	while (tmp->next)
	{
		if (tmp->next->start == 1)
			break ;
		tmp = tmp->next;
	}
	if (!tmp->next)
		return ;
	start = tmp->next;
	tmp->next = tmp->next->next;
	start->next = head;
	*rooms = start;
}

void	ft_move_end(t_room **rooms)
{
	t_room	*end;
	t_room	*tmp;

	tmp = *rooms;
	while (tmp->next)
	{
		if (tmp->next->end == 1)
			break ;
		tmp = tmp->next;
	}
	if (!tmp->next->next)
		return ;
	end = tmp->next;
	tmp->next = tmp->next->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	tmp->next->next = NULL;
}
