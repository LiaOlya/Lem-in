/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:06:36 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/16 20:06:37 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_room_h(char **tmp, int x, int y, int i)
{
	ft_strdel(tmp);
	if (x < 0 || y < 0)
	{
		write(1, "ERROR: negative coordinates\n", 28);
		return (-1);
	}
	if (i < 0)
	{
		write(1, "ERROR: invalid room\n", 20);
		return (-1);
	}
	return (1);
}

int		ft_s_e(t_room **rooms, char **line, t_out **out, int i)
{
	if (ft_strcmp("start", &((*line)[2])) == 0)
	{
		if ((*rooms) && (*rooms)->start == 1)
		{
			write(1, "ERROR: ##start is not unique\n", 29);
			return (-1);
		}
		ft_addline(out, *line, 1);
		get_next_line(0, line);
		i = ft_get_rooms(*line, rooms, 1);
	}
	else if (ft_strcmp("end", &((*line)[2])) == 0)
	{
		if ((*rooms) && (*rooms)->end == 1)
		{
			write(1, "ERROR: ##end is not unique\n", 27);
			return (-1);
		}
		ft_addline(out, *line, 1);
		get_next_line(0, line);
		i = ft_get_rooms(*line, rooms, 2);
	}
	return (i);
}

int		ft_read_h(t_room **rooms, char **line, t_out **out, t_link **links)
{
	int k;
	int i;

	if ((k = ft_comment(line, out, rooms, 0)) != 1)
	{
		if (k == -1)
			return (-1);
		if ((i = ft_get_rooms(*line, rooms, 0)) == -1)
			return (-1);
		if (i == 0 && ft_ch_se_coor(*rooms) == -1)
			return (-1);
		if (i == 0 && !ft_get_dir(*line, links))
			return (0);
		if (i == 0 && ft_ch_name(*rooms, *links) == -1)
			return (-1);
	}
	ft_move_start(rooms);
	ft_addline(out, *line, 1);
	return (1);
}
