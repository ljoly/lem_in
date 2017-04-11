/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:43:02 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/30 17:01:09 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			transfer_data(t_env *env, t_room *room, t_room *go)
{
	ANT--;
	go->ant++;
	if (ft_strequ(NAME, START))
	{
		ANT_NAME--;
		ANTS_INDEX++;
		go->ant_name = ANTS_INDEX;
	}
	else
	{
		go->ant_name = ANT_NAME;
		ANT_NAME = 0;
	}
	go->cant_move = 1;
}

void			next_move(t_room **first)
{
	t_room		*room;

	room = *first;
	while (room)
	{
		CANT_MOVE = 0;
		NGB = 0;
		room = room->next;
	}
	ft_putchar('\n');
}
