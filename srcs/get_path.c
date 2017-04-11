/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:34:57 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/30 18:43:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		display_input(t_env *env)
{
	t_input		*in;

	in = env->input;
	while (in)
	{
		ft_putendl(in->line);
		in = in->next;
	}
	ft_putchar('\n');
}

static void		assign_weight(t_env *env, t_room *room, t_room **first, int w)
{
	t_link		*lk;
	t_room		*tmp;

	if (ft_strequ(NAME, START))
	{
		WEIGHT = w;
		return ;
	}
	WEIGHT = (ft_strequ(NAME, END) ? 0 : w);
	if (room->link)
	{
		lk = *room->link;
		while (lk)
		{
			tmp = *first;
			while (tmp)
			{
				if (ft_strequ(lk->l, tmp->name))
					if (!tmp->weight || w < tmp->weight)
						assign_weight(env, tmp, first, w + 1);
				tmp = tmp->next;
			}
			lk = lk->next;
		}
	}
}

void			get_path(t_env *env, t_room **first)
{
	t_room		*room;

	room = *first;
	while (room && !ft_strequ(NAME, END))
		room = room->next;
	assign_weight(env, room, first, 0);
	room = *first;
	while (room && !ft_strequ(NAME, START))
		room = room->next;
	if (!WEIGHT)
		exit(ft_end(1, NULL, &env, first));
	room = *first;
	while (room && !ft_strequ(NAME, START))
		room = room->next;
	ANT_NAME = ANTS_TOTAL;
	ANT = ANTS_TOTAL;
	room = *first;
	while (room && !ft_strequ(NAME, END))
		room = room->next;
	display_input(env);
	move(env, room, first);
}
