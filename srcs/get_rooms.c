/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:11:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/30 20:35:38 by ljoly            ###   ########.fr       */
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

static void		check_doubles(t_env *env, char **line, t_room **first, char *s)
{
	t_room		*tmp;

	tmp = *first;
	while (tmp)
	{
		if (ft_strequ(tmp->name, s) || (env->x == tmp->x &&
			env->y == tmp->y))
		{
			free(s);
			exit(ft_end(1, line, &env, first));
		}
		tmp = tmp->next;
	}
}

static t_room	*get_room_info(t_env *env, t_room *room, char **line,
	t_room **first)
{
	t_check		c;
	char		*s;

	c.i = 0;
	while ((*line)[c.i] != ' ')
		c.i++;
	c.j = c.i;
	c.k = ++(c.i);
	while ((*line)[c.i] != ' ')
		(c.i)++;
	c.l = c.i;
	while ((*line)[c.i])
		(c.i)++;
	env->x = ft_atoi(&(*line)[c.k]);
	env->y = ft_atoi(&(*line)[c.l]);
	s = ft_strsub(*line, 0, c.j);
	check_doubles(env, line, first, s);
	NAME = s;
	X = env->x;
	Y = env->y;
	return (room);
}

static t_room	*create_new_room(t_env *env, char **line, t_room **first)
{
	t_room		*room;

	if (!(room = ft_memalloc(sizeof(t_room))))
		exit(ft_end(2, line, &env, first));
	room = get_room_info(env, room, line, first);
	if (J == IS_START)
	{
		if (START)
			ft_strdel(&START);
		START = ft_strdup(NAME);
		J = 0;
	}
	if (J == IS_END)
	{
		if (END)
			ft_strdel(&END);
		END = ft_strdup(NAME);
		J = 0;
	}
	ROOMS++;
	return (room);
}

void			get_rooms(t_env *env, char **line, t_room **room)
{
	t_room		*last;

	if (!*room)
		*room = create_new_room(env, line, room);
	else
	{
		last = create_new_room(env, line, room);
		ft_push_bck(room, last);
	}
}
