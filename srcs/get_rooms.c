/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:11:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/23 10:30:48 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_push_bck(t_room **first, t_room *last)
{
	t_room		*tmp;

	if (*first)
	{
		tmp = *first;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = last;
	}
	else
		*first = last;
}

static void		check_name(t_room *first, char *line, int len)
{
	t_room		*tmp;

	tmp = first;
	while (tmp)
	{
		if (ft_strnstr(line, tmp->name, len))
			exit(ft_end(1));
		tmp = tmp->next;
	}
}

static void		get_room_info(t_room *room, char *line, t_room *first)
{
	t_check		c;

	c.i = 0;
	while (line[c.i] != ' ')
		c.i++;
	c.j = (c.i)++;
	c.k = ft_atoi(&line[c.j]);
	while (line[c.j] != ' ')
		(c.j)++;
	c.l = ft_atoi(&line[++(c.j)]);
	check_name(first, line, c.j);
	NAME = ft_strsub(line, 0, c.j);
	X = c.k;
	Y = c.l;
}

static t_room	*create_new_room(t_env *env, char *line, t_room *first)
{
	t_room		*room;

	if (!(room = ft_memalloc(sizeof(t_room))))
		exit(ft_end(2));
	get_room_info(room, line, first);
	if (env->i == IS_START)
		START = ft_strdup(NAME);
	if (env->i == IS_END)
		END = ft_strdup(NAME);
	ROOMS++;
	return (room);
}

void			get_rooms(t_env *env, char *line, t_room *first)
{
	t_room		*last;

	if (!first)
	{
		ft_putstr("ok\n");
		first = create_new_room(env, line, NULL);
	}
	else
	{
		last = create_new_room(env, line, first);
		ft_push_bck(&first, last);
	}
}
