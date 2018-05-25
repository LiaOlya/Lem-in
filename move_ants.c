/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:27:58 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/14 14:27:58 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_incr(int *id, int *next_id, int num)
{
	if (*id > 1)
		*next_id += 1;
	else if (*next_id > 1)
		*next_id += 1;
	if (*id > num)
		*id = 0;
}

void	ft_move_ants(t_route *route, int num, int i)
{
	int		prev_id;
	int		id;
	t_room	*tmp;

	prev_id = route->rooms->id;
	if (i == -1)
		route->rooms->id = 0;
	else
		route->rooms->id = i;
	tmp = route->rooms;
	while (tmp->next)
	{
		if (tmp->id > num)
			tmp->id = 0;
		id = tmp->next->id;
		tmp->next->id = prev_id;
		tmp = tmp->next;
		prev_id = id;
	}
}

int		ft_ch_route_id(t_route *route)
{
	t_route	*tmp;
	t_room	*rooms;

	tmp = route;
	while (tmp)
	{
		rooms = tmp->rooms;
		while (rooms)
		{
			if (rooms->id != 0)
				return (0);
			rooms = rooms->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	ft_f_move(t_route *route, int num)
{
	t_route *tmp;

	tmp = route;
	while (ft_ch_route_id(route) != 1)
	{
		tmp = route;
		while (tmp)
		{
			ft_move_ants(tmp, num, -1);
			tmp = tmp->next;
		}
		ft_print_route(route);
	}
}

void	ft_move_all(t_route *route, int num)
{
	t_route	*tmp;
	int		i;

	i = 1;
	while (i <= num)
	{
		tmp = route;
		while (tmp)
		{
			ft_move_ants(tmp, num, i++);
			tmp = tmp->next;
			if (tmp && (ft_route_length(tmp) + i) > num)
			{
				ft_move_ants(tmp, num, -1);
				break ;
			}
		}
		ft_print_route(route);
	}
	ft_f_move(route, num);
}
