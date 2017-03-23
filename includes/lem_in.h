/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:23:56 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/22 19:15:07 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>

# include "../libft/includes/libft.h"

/*
** Storing input (I)
*/

# define IS_ANTS 1
# define IS_COMMENT 2
# define IS_START 3
# define IS_END 4
# define IS_ROOM 5
# define IS_LINK 6

/*
** Storing environment (II)
*/

# define ANTS_TOTAL env->ants_total
# define ROOMS env->rooms_total
# define ANTS_CHECKED env->ants_checked
# define ROOMS_CHECKED env->rooms_checked
# define START env->start
# define END env->end
# define PTR env->ptr

/*
** Storing rooms and links (III)
*/

# define NAME room->name
# define X room->x
# define Y room->y
# define ANT room->ant
# define WEIGHT room->weight

/*
** (I) Linked list
*/

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_input;

/*
** (II) Struct
*/

typedef struct		s_env
{
	int				ants_total;
	int				rooms_total;
	int				ants_checked;
	int				rooms_checked;
	t_input			*input;
	char			*start;
	char			*end;
	int				lines;
	int				i;
}					t_env;

typedef struct		s_check
{
	int				i;
	int				j;
	int				k;
	int				l;
}					t_check;

/*
** (III) Linked list
*/

typedef struct		s_link
{
	char			*l;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ant;
	t_link			*first_link;
	int				weight;
	struct s_room	*next;
}					t_room;

/*
** Non-static functions
*/

t_room				*get_input(t_env *env);
int					check_input(t_env *env, char *line, t_room *room);
void				get_rooms(t_env *env, char *line, t_room *first);
void				get_links(char *line, t_room *first);
int					ft_end(int status);

#endif
