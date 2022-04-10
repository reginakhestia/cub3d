/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:06:52 by khestia           #+#    #+#             */
/*   Updated: 2022/04/10 20:08:00 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error(int i)
{
	if (i == -1)
		write(2, "Error : Couldn't open file (FD)\n", 32);
	if (i == -2)
		write(2, "Error : Couldn't parse file (GNL)\n", 34);
	if (i == -3)
		write(2, "Error : Resolution specified twice\n", 35);
	if (i == -4)
		write(2, "Error : Invalid resolution\n", 27);
	if (i == -5)
		write(2, "Error : Floor/ceiling specified twice\n", 38);
	if (i == -6)
		write(2, "Error : Invalid floor/ceiling line\n", 35);
	if (i == -7)
		write(2, "Error : Texture path specified twice\n", 37);
	if (i == -8)
		write(2, "Error : Malloc fail (texture path)\n", 35);
	if (i == -9)
		write(2, "Error : Invalid texture image\n", 30);
	if (i == -10)
		write(2, "Error : Invalid line in file\n", 29);
	if (i == -11)
		write(2, "Error : Malloc fail (map table)\n", 32);
	if (i == -12)
		write(2, "Error : Invalid map\n", 20);
	if (i == -13)
		write(2, "Error : Map isn't a rectangle\n", 30);
	if (i == -14)
		write(2, "Error : No resolution specified\n", 32);
	if (i == -15)
		write(2, "Error : Missing texture\n", 24);
	if (i == -16)
		write(2, "Error : Missing floor/ceiling color\n", 26);
	if (i == -17)
		write(2, "Error : No starting position\n", 29);
	if (i == -18)
		write(2, "Error : Multiple starting positions\n", 36);
	if (i == -19)
		write(2, "Error : Map isn't surrounded by walls\n", 38);
	return (-1);
}

int		ft_map_chek(t_all *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->map.y)
	{
		j = 0;
		while (j < s->map.x)
		{
			if (s->map.tab[i][j] != '1' && i == 0)
				return (-1);
			else if (s->map.tab[i][j] != '1' && i == s->map.y - 1)
				return (-1);
			else if (s->map.tab[i][j] != '1' && j == 0)
				return (-1);
			else if (s->map.tab[i][j] != '1' && j == s->map.x - 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_parse_check(t_all *s)
{
	if (s->win.x <= 0 || s->win.y <= 0)
		return (ft_error(-14));
	else if ((s->tex.n == NULL || s->tex.s == NULL || s->tex.e == NULL)
			|| (s->tex.w == NULL || s->tex.i == NULL))
		return (ft_error(-15));
	else if (s->tex.c == NULL || s->tex.f == NULL)
		return (ft_error(-16));
	else if (s->err.p == 0)
		return (ft_error(-17));
	else if (s->err.p > 1)
		return (ft_error(-18));
	else if (ft_map_check(s) == -1)
		return (ft_strerror(-19));
	return (1);
}

int	ft_chek_name(char *file, char *s)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	if ((i > 4 && file[i - 1] == s[2] && file[i - 2] == s[1])
		&& (file[i - 3] == s[0] && file[i - 4] == '.'))
		return (1);
	return (0);
}