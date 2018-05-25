/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:29:47 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/08 15:29:48 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_ch_num(int *num, t_out **out)
{
	char	*line;
	int		i;

	i = -1;
	if (ft_get_line(&line) != 1)
		return (0);
	while (line && ft_comment(&line, out, NULL, 1) == 1)
	{
		ft_addline(out, line, 1);
		get_next_line(0, &line);
	}
	while (line && line[++i])
		if (line[i] < 48 || line[i] > 57)
		{
			write(1, "ERROR: No ants\n", 15);
			return (0);
		}
	if ((*num = ft_atoi(line)) <= 0)
	{
		write(1, "ERROR: No ants\n", 15);
		return (0);
	}
	ft_addline(out, line, 1);
	return (1);
}

int		ft_get_coor(char *line, int *i)
{
	int j;
	int num;

	num = 0;
	j = 0;
	while (--(*i) >= 0)
	{
		if (line[*i] == ' ')
			break ;
		if (!(line[*i] == '-' || (line[*i] >= 48 && line[*i] <= 57)))
			return (0);
		++num;
	}
	return (num);
}

void	ft_def_r(t_room **rooms, int x, int y, char *name)
{
	(*rooms)->x = x;
	(*rooms)->y = y;
	(*rooms)->name = ft_strdup(name);
	(*rooms)->start = 0;
	(*rooms)->end = 0;
	(*rooms)->id = 0;
}

void	ft_roomadd(t_room **rooms, int x, int y, char *name)
{
	t_room *new;

	if (!(*rooms))
	{
		*rooms = (t_room*)malloc(sizeof(t_room));
		ft_def_r(rooms, x, y, name);
		(*rooms)->next = NULL;
		(*rooms)->nodes = NULL;
		return ;
	}
	new = (t_room*)malloc(sizeof(t_room));
	ft_def_r(&new, x, y, name);
	new->next = *rooms;
	*rooms = new;
	(*rooms)->nodes = NULL;
}

int		ft_ch_end(t_room *end, t_room *room)
{
	while (room)
	{
		if (ft_strcmp(end->name, room->name) == 0 && room->end == 1)
			return (1);
		room = room->next;
	}
	return (0);
}
