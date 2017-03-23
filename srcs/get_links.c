/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:20:28 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/22 17:32:33 by ljoly            ###   ########.fr       */
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

static t_link	*store_link(char *line, char *ptr)
{
	t_link		*link;
	int			i;

	if (!(link = ft_memalloc(sizeof(t_link))))
		exit(ft_end(2));
	i = 0;
	if (ptr != line)
	{
		while (line[i] != '-')
			i++;
		link->l = ft_strsub(line, 0, i);
	}
	else
	{
		while (line[i] != '-')
			i++;
		i++;
		link->l = ft_strdup(&line[i]);
	}
	link->next = NULL;
	return (link);
}

void			get_links(char *line, t_room *first)
{
	t_room		*room;
	t_link		*last_link;
	char		*ptr;

	last_link = NULL;
	room = first;
	while (room)
	{
		if ((ptr = ft_strstr(line, NAME)))
		{
			if (!room->first_link)
				room->first_link = store_link(line, ptr);
			else
				last_link = store_link(line, ptr);
		}
		room = room->next;
	}
	if (last_link)
		ft_push_bck(&room->first_link, last_link);
}
