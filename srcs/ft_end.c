/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 16:57:34 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/30 22:46:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_free_links(t_room *room)
{
	t_link		*lk;
	t_link		*tmp;

	if (room->link)
	{
		lk = *room->link;
		while (lk)
		{
			tmp = lk->next;
			free(lk->l);
			free(lk);
			lk = tmp;
		}
		free(room->link);
		room->link = NULL;
	}
}

static void		ft_free_rooms(t_room **first)
{
	t_room		*room;
	t_room		*tmp;

	if (first)
	{
		if (*first)
		{
			room = *first;
			while (room)
			{
				tmp = room->next;
				ft_free_links(room);
				free(NAME);
				free(room);
				room = tmp;
			}
			free(first);
			first = NULL;
		}
	}
}

static void		ft_free(t_env **env, t_room **room)
{
	t_input		*tmp;

	if (env)
	{
		if ((*env)->start)
			free((*env)->start);
		if ((*env)->end)
			free((*env)->end);
		if ((*env)->input)
		{
			while ((*env)->input)
			{
				tmp = (*env)->input->next;
				free((*env)->input->line);
				free((*env)->input);
				(*env)->input = tmp;
			}
		}
		free(*env);
		env = NULL;
	}
	ft_free_rooms(room);
}

int				ft_end(int status, char **line, t_env **env, t_room **room)
{
	if (line)
		free(*line);
	ft_free(env, room);
	if (status == 0)
		return (0);
	else if (status == 1)
		ft_putendl_fd("ERROR", 2);
	else if (status == 2)
		ft_putendl_fd("MALLOC ERROR", 2);
	else if (status == 3)
		ft_putendl_fd("READ ERROR", 2);
	else if (status == 4)
		ft_putendl_fd("INPUT ERROR: This program only reads from STDIN.", 2);
	ft_putstr_fd("\n\"Go to the Ant, O sluggard,\nObserve her ways and be", 2);
	ft_putendl_fd(" wise\nWhich, having no chief,\nOfficer or ruler,", 2);
	ft_putstr_fd("Prepares her food in the summer,\nAnd gathers her", 2);
	ft_putendl_fd(" provision in the harvest\"", 2);
	ft_putendl_fd("\n      (Book of proverbs 6:6-8)\n", 2);
	return (-1);
}
