/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:22:59 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/14 22:23:01 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_link_add(t_link **links, char *r1, char *r2)
{
	t_link *new;

	if (links && !(*links))
	{
		*links = (t_link*)malloc(sizeof(t_link));
		(*links)->s1 = ft_strdup(r1);
		(*links)->s2 = ft_strdup(r2);
		ft_strdel(&r1);
		ft_strdel(&r2);
		(*links)->next = NULL;
		return ;
	}
	new = (t_link*)malloc(sizeof(t_link));
	new->s1 = ft_strdup(r1);
	new->s2 = ft_strdup(r2);
	ft_strdel(&r1);
	ft_strdel(&r2);
	new->next = *links;
	*links = new;
}

void	ft_write(int id, char *name)
{
	write(1, "L", 1);
	ft_putnbr(id);
	write(1, "-", 1);
	write(1, name, ft_strlen(name));
	write(1, " ", 1);
}

void	ft_print_route(t_route *route)
{
	int		ch;
	t_route	*tmp;
	t_room	*head;

	ch = 0;
	tmp = route;
	while (tmp)
	{
		head = tmp->rooms;
		head->start = 1;
		while (head)
		{
			if (head->id != 0 && head->start != 1)
			{
				ft_write(head->id, head->name);
				ch = 1;
			}
			head = head->next;
		}
		tmp = tmp->next;
	}
	if (ch == 1)
		write(1, "\n", 1);
}

int		ft_route_length(t_route *rooms)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = rooms->rooms;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i - 1);
}

int		ft_get_line(char **line)
{
	get_next_line(0, line);
	if (!(*line))
	{
		write(1, "ERROR: no ant farm\n", 19);
		return (0);
	}
	return (1);
}
