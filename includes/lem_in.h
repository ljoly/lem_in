/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:23:56 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/31 12:20:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
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
# define ANTS_OK env->ants_ok
# define ROOMS_OK env->rooms_ok
# define START env->start
# define END env->end
# define I env->i
# define J env->j
# define ANTS_INDEX env->ants_index
# define W_LESS env->w_less

/*
** Storing rooms and links (III)
*/

# define NAME room->name
# define X room->x
# define Y room->y
# define ANT room->ant
# define ANT_NAME room->ant_name
# define CANT_MOVE room->cant_move
# define WEIGHT room->weight
# define NGB room->ngb

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
	int				ants_ok;
	int				rooms_ok;
	t_input			*input;
	int				x;
	int				y;
	char			*start;
	char			*end;
	int				i;
	int				j;
	int				ants_index;
	int				w_less;
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
	int				ant_name;
	int				cant_move;
	t_link			**link;
	int				weight;
	int				ngb;
	struct s_room	*next;
}					t_room;

/*
** Non-static functions
*/

void				get_input(t_env *env, t_room **room);
int					check_input(t_env *env, char **line, t_room **room);
int					get_instructions(t_env *env, char *line);
void				get_rooms(t_env *env, char **line, t_room **room);
void				get_links(t_env *env, char **line, t_room **first);
void				get_path(t_env *env, t_room **first);
void				move(t_env *env, t_room *end, t_room **first);
void				transfer_data(t_env *env, t_room *room, t_room *go);
void				next_move(t_room **first);
int					ft_end(int status, char **line, t_env **env, t_room **room);

#endif
