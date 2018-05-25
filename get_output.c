/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:38:43 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/09 10:38:44 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_addline(t_out **out, char *line, int l)
{
	t_out *tmp;

	if (!(*out))
	{
		*out = (t_out*)malloc(sizeof(t_out));
		(*out)->str = ft_strdup(line);
		(*out)->level = 0;
		if (l == 1)
			ft_strdel(&line);
		(*out)->next = NULL;
		return ;
	}
	tmp = *out;
	while (tmp->next)
		tmp = (tmp)->next;
	tmp->next = (t_out*)malloc(sizeof(t_out));
	tmp->next->str = ft_strdup(line);
	tmp->next->level = 0;
	if (l == 1)
		ft_strdel(&line);
	tmp->next->next = NULL;
}

void	ft_print_out(t_out *out)
{
	while (out)
	{
		write(1, out->str, ft_strlen(out->str));
		write(1, "\n", 1);
		out = out->next;
	}
	write(1, "\n", 1);
}

int		ft_double_name(t_room *rooms)
{
	int		n;
	t_room	*head;
	t_room	*tmp;

	head = rooms;
	while (head)
	{
		n = 0;
		tmp = head;
		while (tmp)
		{
			if (ft_strcmp(tmp->name, head->name) == 0)
				++n;
			tmp = tmp->next;
		}
		if (n > 1)
			return (0);
		head = head->next;
	}
	return (1);
}

int		ft_equal_con(t_link *lists, char *r1, char *r2)
{
	t_link	*t1;

	t1 = lists;
	while (t1)
	{
		if (ft_strcmp(t1->s1, r1) == 0 && ft_strcmp(t1->s2, r2) == 0)
			return (0);
		if (ft_strcmp(t1->s1, r2) == 0 && ft_strcmp(t1->s2, r1) == 0)
			return (0);
		t1 = t1->next;
	}
	return (1);
}

int		ft_ch_se_coor(t_room *rooms)
{
	t_room	*head;
	int		s1;
	int		s2;

	s1 = 0;
	s2 = 0;
	head = rooms;
	while (rooms)
	{
		if (ft_h_ch(&s1, &s2, rooms->start, rooms->end) == -1)
			return (-1);
		rooms = rooms->next;
	}
	if (s1 == 0 || s2 == 0)
	{
		ft_s_e_error(s1, s2);
		return (-1);
	}
	return (1);
}
