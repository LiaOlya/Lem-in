/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:25:00 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/09 09:25:01 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ch_room_name(char *name)
{
	int i;

	i = 0;
	if (name[0] == 'L')
		return (0);
	while (name[i])
		if (name[i++] == '-')
			return (0);
	return (1);
}

int		ft_get_rooms(char *line, t_room **rooms, int ch)
{
	int		x;
	int		y;
	char	*tmp;
	int		i;

	i = (int)ft_strlen(line);
	if (line[i - 1] < 48 || line[i - 1] > 57 || !ft_get_coor(line, &i))
		return (0);
	y = ft_atoi(&line[i + 1]);
	if (!(x = ft_get_coor(line, &i)))
		return (0);
	tmp = ft_strsub(line, i + 1, x);
	x = ft_atoi(tmp);
	if (ft_room_h(&tmp, x, y, i) == -1)
		return (-1);
	tmp = ft_strsub(line, 0, i);
	if (ch_room_name(tmp) == 0)
	{
		write(1, "ERROR: invalid room name\n", 25);
		return (-1);
	}
	ft_roomadd(rooms, x, y, tmp);
	ft_strdel(&tmp);
	ft_start_end(rooms, ch);
	return (1);
}

int		ft_ch_name(t_room *rooms, t_link *links)
{
	t_room	*head;
	int		s1;
	int		s2;

	while (links)
	{
		s1 = 0;
		s2 = 0;
		head = rooms;
		while (head)
		{
			if (ft_strcmp(links->s1, head->name) == 0)
				s1 = 1;
			if (ft_strcmp(links->s2, head->name) == 0)
				s2 = 1;
			head = head->next;
		}
		if (s1 == 0 || s2 == 0)
		{
			write(1, "ERROR: invalid room\n", 20);
			return (-1);
		}
		links = links->next;
	}
	return (1);
}

void	ft_s_e_error(int s1, int s2)
{
	if (s1 == 0 && s2 == 0)
		write(1, "ERROR: NO ##start and ##end coordinates\n", 40);
	else if (s1 == 0)
		write(1, "ERROR: NO ##start coordinates\n", 30);
	else if (s2 == 0)
		write(1, "ERROR: NO ##end coordinates\n", 28);
}

int		ft_h_ch(int *s1, int *s2, int s, int e)
{
	if (s == 1 && *s1 == 0)
		*s1 = 1;
	else if (e == 1 && *s2 == 0)
		*s2 = 1;
	else if ((s == 1 && *s1 == 1))
	{
		write(1, "ERROR: ##start is not unique\n", 29);
		return (-1);
	}
	else if ((e == 1 && *s2 == 1))
	{
		write(1, "ERROR: ##end is not unique\n", 27);
		return (-1);
	}
	return (1);
}
