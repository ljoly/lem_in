/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:37:30 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/22 19:32:29 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** HERE: fonction free (structures + contenu) a la fin
*/

int				ft_end(int status)
{
	if (status == 1)
		ft_putendl_fd("ERROR", 2);
	else if (status == 2)
		ft_putendl_fd("MALLOC ERROR", 2);
	else if (status == 3)
		ft_putendl_fd("READ ERROR", 2);
	else if (status == 4)
		ft_putendl_fd("INPUT ERROR: This program only reads from STDIN.", 2);
	return (-1);
}

int				main(int argc, char **argv)
{
	t_env		*env;
	t_room		*room;

	(void)argv;
	if (argc > 1)
		exit(ft_end(4));
	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(ft_end(2));
	room = get_input(env);
	ft_putstr("THE END\n");
// Si pas ##start ou ##end ==> ERROR;
//	solver(t_input *input, t_env *env, t_room *room);
	return (0);
}
