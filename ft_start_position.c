/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:09:30 by khestia           #+#    #+#             */
/*   Updated: 2022/04/10 20:09:51 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_start_position(t_all *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->map.y)
	{
		while (++j < s->map.x)
		{
			c = s->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				s->pos.y = (double)i + 0.5;
				s->pos.x = (double)j + 0.5;
				if (c == 'E')
					s->dir.x = 1;
				else if (c == 'W')
					s->dir.x = -1;
				if (c == 'S')
					s->dir.y = 1;
				else if (c == 'N')
					s->dir.y = -1;
				s->err.p++;
			}
		}
		j = -1;
	}
}
