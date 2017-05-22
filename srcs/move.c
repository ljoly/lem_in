/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:04:51 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/22 19:26:44 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_room	*best_path(t_env *env, t_room *room, t_room *go, t_room *tmp)
{
	if (go)
	{
		if (!W_LESS && ft_strequ(NAME, START) && NGB &&
			((ANT_NAME + NGB) / NGB) > tmp->weight)
			go = tmp;
		if (tmp->weight < go->weight)
		{
			W_LESS = 1;
			go = tmp;
		}
	}
	else
	{
		if (!W_LESS && ft_strequ(NAME, START) && NGB &&
			((ANT_NAME + NGB) / NGB) > tmp->weight)
			go = tmp;
		if (tmp->weight < WEIGHT)
		{
			W_LESS = 1;
			go = tmp;
		}
	}
	return (go);
}

static void		get_ngb(t_room *room, t_room **first)
{
	t_link		*lk;
	t_room		*tmp;

	lk = *room->link;
	while (lk)
	{
		tmp = *first;
		while (tmp)
		{
			if (ft_strequ(lk->l, tmp->name) && (tmp->ant))
				NGB += tmp->weight;
			tmp = tmp->next;
		}
		lk = lk->next;
	}
}

static t_room	*finding_path(t_env *env, t_room *room, t_room **first)
{
	t_link		*lk;
	t_room		*tmp;
	t_room		*go;

	go = NULL;
	W_LESS = 0;
	if (room)
	{
		get_ngb(room, first);
		lk = *room->link;
		while (lk)
		{
			tmp = *first;
			while (tmp)
			{
				if (ft_strequ(lk->l, tmp->name) && ft_strequ(tmp->name, END))
					return (go = tmp);
				if (ft_strequ(lk->l, tmp->name) && (!tmp->ant))
					go = best_path(env, room, go, tmp);
				tmp = tmp->next;
			}
			lk = lk->next;
		}
	}
	return (go);
}

static t_room	*finding_first_ant(t_env *env, t_room **first)
{
	t_room		*room;
	t_room		*first_ant;
	int			ant;
	int			can;

	room = *first;
	first_ant = NULL;
	ant = ANTS_TOTAL + 1;
	can = 0;
	while (room)
	{
		if (ANT && !CANT_MOVE && !ft_strequ(NAME, END))
		{
			if (!can && ft_strequ(NAME, START))
				first_ant = room;
			else if (ANT_NAME > 0 && ANT_NAME < ant)
			{
				ant = ANT_NAME;
				first_ant = room;
				can = 1;
			}
		}
		room = room->next;
	}
	return (first_ant);
}

void			move(t_env *env, t_room *end, t_room **first)
{
	t_room		*room;
	t_room		*go;

	while (end->ant < ANTS_TOTAL)
	{
		room = finding_first_ant(env, first);
		if ((go = finding_path(env, room, first)))
		{
			transfer_data(env, room, go);
			ft_printf("L%d-%s ", go->ant_name, go->name);
		}
		else
			next_move(first);
	}
	ft_putchar('\n');
	ft_end(0, NULL, &env, first);
}
