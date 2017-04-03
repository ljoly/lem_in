/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:18:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/31 13:35:45 by ljoly            ###   ########.fr       */
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

static t_input	*store_input(t_env *env, char **line, t_room **room)
{
	t_input		*input;

	if (I == IS_START || I == IS_END)
		J = I;
	if (!check_input(env, line, room))
		return (NULL);
	if ((I == IS_START || I == IS_END) && J)
		exit(ft_end(1, line, &env, room));
	if (ANTS_OK && !ROOMS_OK && I == IS_ROOM)
		get_rooms(env, line, room);
	else if (ROOMS_OK && ROOMS > 1 && I == IS_LINK)
	{
		if (!START || !END)
			exit(ft_end(1, line, &env, room));
		get_links(env, line, room);
	}
	if (!(input = ft_memalloc(sizeof(t_input))))
		exit(ft_end(2, line, &env, room));
	input->line = ft_strdup(*line);
	return (input);
}

static int		list_input(t_env *env, char **line, t_room **room)
{
	t_input		*last;

	if (!env->input)
	{
		if (!(env->input = store_input(env, line, room)))
		{
			free(*line);
			return (0);
		}
	}
	else
	{
		if (!(last = store_input(env, line, room)))
		{
			free(*line);
			return (0);
		}
		ft_push_bck(&env->input, last);
	}
	return (1);
}

void			get_input(t_env *env, t_room **room)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			exit(ft_end(3, NULL, &env, room));
		if (!list_input(env, &line, room))
			break ;
		free(line);
	}
}
