/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:05:50 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/23 10:30:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_link_members(char *m1, int len, char *m2, t_room *first)
{
	t_room		*tmp;
	int			cmp;

	tmp = first;
	cmp = 0;
	while (tmp)
	{
		if (ft_strnstr(m1, tmp->name, len))
			cmp++;
		else if (ft_strstr(m2, tmp->name))
			cmp++;
		tmp = tmp->next;
	}
	return (cmp == 2 ? 1 : 0);
}

static int		check_link(char *line, t_room *room)
{
	t_check		c;

	c.i = 0;
	while (line[c.i] && line[c.i] != '-')
		(c.i)++;
	if (c.i == 0 || !line[c.i + 1])
		return (0);
	c.j = c.i++;
	if (!line[c.i])
		return (0);
	c.k = c.i;
	while (line[c.i] && ft_isdigit(line[c.i]))
		(c.i)++;
	return (check_link_members(line, c.j, &line[c.k], room));
}

static void		check_room_info(char *line)
{
	t_check		c;

	c.i = 0;
	while (line[c.i] && ft_isprint(line[c.i]) && line[c.i] != ' ')
		(c.i)++;
	if (c.i == 0 || !line[c.i])
		exit(ft_end(1));
	c.k = c.i;
	if (line[c.i] == ' ')
	{
		c.j = ++(c.i);
		while (line[c.i] && ft_isdigit(line[c.i]))
			(c.i)++;
		if (line[c.i] && c.i != c.j && line[c.i] == ' '
				&& ft_isdigit(line[++(c.i)]))
		{
			c.l = c.i;
			while (line[c.i] && ft_isdigit(line[c.i]))
				(c.i)++;
			if (!line[c.i])
				return ;
		}
	}
	exit(ft_end(1));
}

static int		get_instructions(t_env *env, char *line)
{
	int			i;

	i = 0;
	if (!ANTS_CHECKED)
	{
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (!line[i])
		{
			ANTS_CHECKED = 1;
			return ((ANTS_TOTAL = ft_atoi(line) > 1 ? IS_ANTS : 0));
		}
	}
	if (!line || line[0] == 'L')
		return (0);
	if (ft_strequ(line, "##end"))
		return (IS_END);
	if (ft_strequ(line, "##start"))
		return (IS_START);
	if (line[0] == '#')
		return (IS_COMMENT);
	if (ft_strchr(line, '-'))
		return (IS_LINK);
	return (IS_ROOM);
}

int				check_input(t_env *env, char *line, t_room *room)
{
	if (!ANTS_CHECKED)
	{
//		ft_putstr("ants\n");
		if ((env->i = get_instructions(env, line)) == IS_ANTS)
			return (IS_ANTS);
		exit(ft_end(1));
	}
	else if (!ROOMS_CHECKED)
	{
//		ft_putstr("rooms\n");
		if ((env->i = get_instructions(env, line)) == IS_ROOM)
			check_room_info(line);
		else if (!env->i)
			exit(ft_end(1));
		else if (env->i == IS_LINK)
			ROOMS_CHECKED = 1;
		return (IS_ROOM);
	}
	else if (ROOMS_CHECKED)
	{
//		ft_putstr("links\n");
		if ((env->i = get_instructions(env, line)) == IS_LINK &&
				check_link(line, room))
			return (IS_LINK);
		if (env->i == IS_COMMENT)
			return (IS_COMMENT);
	}
	return (0);
}
