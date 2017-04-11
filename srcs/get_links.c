/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:20:28 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/30 20:36:37 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_push_bck(t_link **first, t_link *last)
{
	t_link		*tmp;

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

static t_link	*store_link(char **line, char *ptr, t_env *env, t_room **room)
{
	t_link		*link;
	int			i;

	if (!(link = ft_memalloc(sizeof(t_link))))
		exit(ft_end(2, line, &env, room));
	i = 0;
	if (ptr != *line)
	{
		while ((*line)[i] != '-')
			i++;
		link->l = ft_strsub(*line, 0, i);
	}
	else
	{
		while ((*line)[i] != '-')
			i++;
		i++;
		link->l = ft_strdup(&(*line)[i]);
	}
	return (link);
}

static int		get_link_members(char *line, t_room *room)
{
	int			i;
	char		*m1;

	i = 0;
	while (line[i] != '-')
		i++;
	m1 = ft_strsub(line, 0, i++);
	if (ft_strequ(m1, NAME) || ft_strequ(&line[i], NAME))
	{
		free(m1);
		return (1);
	}
	free(m1);
	return (0);
}

void			get_links(t_env *env, char **line, t_room **first)
{
	t_room		*room;
	t_link		*last_link;
	char		*ptr;

	room = *first;
	while (room)
	{
		if (get_link_members(*line, room))
		{
			ptr = ft_strstr(*line, NAME);
			if (!room->link)
			{
				if (!(room->link = (t_link**)ft_memalloc(sizeof(t_link*))))
					exit(ft_end(2, line, &env, first));
				*room->link = store_link(line, ptr, env, first);
			}
			else
			{
				last_link = store_link(line, ptr, env, first);
				ft_push_bck(room->link, last_link);
			}
		}
		room = room->next;
	}
}
