/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:45:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/28 20:47:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				get_instructions(t_env *env, char *line)
{
	int			i;

	i = 0;
	if (!ANTS_OK)
	{
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (!line[i])
		{
			ANTS_OK = 1;
			return ((ANTS_TOTAL = ft_atoi(line)) >= 1 ? IS_ANTS : 0);
		}
	}
	if (!line || line[0] == 'L')
		return (0);
	if (ft_strequ(line, "##end"))
		return (IS_END);
	if (ft_strequ(line, "##start"))
		return (IS_START);
	if (line[0] == '#')
		return (IS_COMMENT);
	if (ft_strchr(line, '-'))
		return (IS_LINK);
	return (IS_ROOM);
}
