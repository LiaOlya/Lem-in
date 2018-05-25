/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:13:25 by oltkache          #+#    #+#             */
/*   Updated: 2018/05/07 13:13:26 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_comment(char **line, t_out **out, t_room **rooms, int k)
{
	int i;

	if ((*line)[0] == '#' && ft_strcmp(&((*line)[1]), "#start") != 0 &&
		ft_strcmp(&((*line)[1]), "#end") != 0)
		return (1);
	else if (k != 1 && (*line)[0] == '#' && (*line)[1] == '#')
	{
		i = 1;
		i = ft_s_e(rooms, line, out, i);
		if (i == -1 || i == 0)
			return (i);
	}
	else
		return (0);
	return (1);
}

int		ft_get_dir(char *line, t_link **links)
{
	int		len;
	int		i;
	char	*r1;
	char	*r2;

	i = 0;
	len = (int)ft_strlen(line);
	while (line[i] && line[i] != '-')
		++i;
	if (!line[i])
		return (0);
	r1 = ft_strsub(line, 0, i);
	r2 = ft_strsub(line, i + 1, len - i - 1);
	if (!r1 || !r2)
		return (0);
	if (ft_equal_con(*links, r1, r2) == 1)
		ft_link_add(links, r1, r2);
	return (1);
}

int		ft_read(t_link **links, t_out **out, t_room **rooms)
{
	int		k;
	char	*line;

	*links = NULL;
	while (get_next_line(0, &line) > 0)
	{
		k = ft_read_h(rooms, &line, out, links);
		if (k != 1)
			return (k);
		if (*rooms && ft_double_name(*rooms) == 0)
		{
			write(1, "ERROR: room is declared\n", 24);
			return (-1);
		}
		if (!rooms)
		{
			write(1, "ERROR: No rooms\n", 16);
			return (0);
		}
	}
	return (1);
}

int		ft_functions(t_link *links, t_route **routes, t_out **out, int *num)
{
	t_room *rooms;

	rooms = NULL;
	if (!ft_ch_num(num, out))
		return (0);
	if (ft_read(&links, out, &rooms) == -1)
		return (0);
	if (ft_ch_se_coor(rooms) == -1)
		return (0);
	ft_get_nodes(&rooms, links);
	ft_move_end(&rooms);
	ft_search(rooms, routes);
	ft_finish(routes, rooms);
	if (!(*routes))
	{
		write(1, "ERROR: No possible solution\n", 28);
		return (0);
	}
	ft_del(rooms);
	return (1);
}

int		main(int argc, char **argv)
{
	t_route	*routes;
	t_out	*out;
	t_link	*links;
	int		num;

	routes = NULL;
	out = NULL;
	links = NULL;
	if (ft_functions(links, &routes, &out, &num) == 0)
		return (0);
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "routes") == 0))
		ft_print_out(out);
	if (argc != 1 && !(argc == 2 && ft_strcmp(argv[1], "routes") == 0))
	{
		write(1, "USAGE: ./lem-in [routes]\n", 25);
		return (0);
	}
	else if (argc != 1)
		ft_print_routes(routes);
	ft_move_all(routes, num);
	ft_del_routes(routes);
	ft_del_out(&out);
	ft_del_links(&links);
	return (0);
}
