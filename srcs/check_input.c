/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:05:50 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/30 22:31:22 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_link_members(char *m1, char *m2, t_room **room)
{
	t_room		*tmp;
	int			cmp;

	tmp = *room;
	cmp = 0;
	while (tmp)
	{
		if (ft_strequ(m1, tmp->name))
			cmp++;
		if (ft_strequ(m2, tmp->name))
			cmp++;
		tmp = tmp->next;
	}
	free(m1);
	return (cmp == 2 ? 1 : 0);
}

static int		check_link(char *line, t_room **room)
{
	t_check		c;
	char		*m1;

	c.i = 0;
	while (line[c.i] && line[c.i] != '-')
		(c.i)++;
	if (c.i == 0 || !line[c.i + 1])
		return (0);
	m1 = ft_strsub(line, 0, c.i++);
	if (!line[c.i])
		return (0);
	c.k = c.i;
	while (line[c.i] && ft_isdigit(line[c.i]))
		(c.i)++;
	return (check_link_members(m1, &line[c.k], room));
}

static void		check_room_info(t_env *env, char **line, t_room **room)
{
	t_check		c;

	c.i = 0;
	while ((*line)[c.i] && ft_isprint((*line)[c.i]) && (*line)[c.i] != ' ')
		(c.i)++;
	if (c.i == 0 || !(*line)[c.i])
		exit(ft_end(1, line, &env, room));
	if ((*line)[c.i] == ' ')
	{
		c.j = ++(c.i);
		while ((*line)[c.i] && ft_isdigit((*line)[c.i]))
			(c.i)++;
		if ((*line)[c.i] && c.i != c.j && (*line)[c.i] == ' '
				&& ft_isdigit((*line)[++(c.i)]))
		{
			while ((*line)[c.i] && ft_isdigit((*line)[c.i]))
				(c.i)++;
			if (!(*line)[c.i])
				return ;
		}
	}
	exit(ft_end(1, line, &env, room));
}

static int		check_ants(t_env *env, char **line, t_room **room)
{
	if ((I = get_instructions(env, *line)) == IS_ANTS)
		return (IS_ANTS);
	else if (I == IS_COMMENT)
		return (IS_COMMENT);
	exit(ft_end(1, line, &env, room));
}

int				check_input(t_env *env, char **line, t_room **room)
{
	if (!ANTS_OK)
		return (check_ants(env, line, room));
	else if (ANTS_OK && !ROOMS_OK)
	{
		if ((I = get_instructions(env, *line)) == IS_ROOM)
		{
			check_room_info(env, line, room);
			return (IS_ROOM);
		}
		else if (!I || (I == IS_LINK && J))
			exit(ft_end(1, line, &env, room));
		else if (I == IS_LINK)
			ROOMS_OK = 1;
		else if (I != IS_ROOM && I != IS_LINK)
			return (IS_COMMENT);
	}
	if (ROOMS_OK)
	{
		if ((I = get_instructions(env, *line)) == IS_LINK &&
				check_link(*line, room))
			return (IS_LINK);
		if (I == IS_COMMENT)
			return (IS_COMMENT);
	}
	return (0);
}
