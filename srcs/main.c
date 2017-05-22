/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:37:30 by ljoly             #+#    #+#             */
/*   Updated: 2017/05/22 17:46:51 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				main(int argc, char **argv)
{
	t_env		*env;
	t_room		**room;

	(void)argv;
	if (argc > 1)
		exit(ft_end(4, NULL, NULL, NULL));
	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(ft_end(2, NULL, NULL, NULL));
	if (!(room = (t_room**)ft_memalloc(sizeof(t_room*))))
		exit(ft_end(2, NULL, &env, NULL));
	get_input(env, room);
	if (!START || !END)
		exit(ft_end(1, NULL, &env, room));
	get_path(env, room);
	return (0);
}
