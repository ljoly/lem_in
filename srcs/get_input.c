/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:18:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/23 10:30:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_push_bck(t_input **first, t_input *last)
{
	t_input		*tmp;

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

static t_input	*store_input(t_env *env, char *line, t_room *room)
{
	t_input		*input;

	if (!check_input(env, line, room))
		return (NULL);
	if (ANTS_CHECKED && !ROOMS_CHECKED && env->i == IS_ROOM)
	{
		get_rooms(env, line, room);
		ft_putstr("coucou\n");
//		ft_printf("NAME = %s\n", NAME); <<<<<<<< SEGFAULT;
	}
	ft_putstr("oui\n");
	if (ROOMS_CHECKED && ROOMS > 1 && env->i == IS_LINK)
		get_links(line, room);
	if (!(input = ft_memalloc(sizeof(t_input))))
		exit(ft_end(2));
	input->line = ft_strdup(line);
	input->next = NULL;
	env->lines++;
	return (input);
}

t_room			*get_input(t_env *env)
{
	t_input		*last;
	t_room		*room;
	char		*line;
	int			ret;

	room = NULL;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			exit(ft_end(3));
		if (!env->input)
			env->input = store_input(env, line, room);
		else
		{
			last = store_input(env, line, room);
			ft_push_bck(&env->input, last);
		}
		free(line);
		env->lines++;
	}
	return (room);
}
