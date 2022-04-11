/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:01:24 by khestia           #+#    #+#             */
/*   Updated: 2022/04/11 14:12:37 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_map_line_len(t_all *s, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	return (i);
}

char	*ft_map_line(t_all *s, char *line, int *i)
{
	char	*map_line;
	int	j;

	if (!(map_line = malloc(sizeof(char) * (ft_map_line_len(s, line) + 1))))
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if (line[*i] == '0' || line[*i] == '1' || line[*i] == 'N'
			|| line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W' || line[*i] == ' ')
			map_line[j++] = line[*i];
		else
		{
			free(map_line);
			return (NULL);
		}
		(*i)++;
	}
	map_line[j] = '\0';
	return (map_line);
}

int		ft_map(t_all *s, char *line, int *i)
{
	char	**tmp;
	int		j;

	s->err.m = 1;
	if (!(tmp = malloc(sizeof(char *) * (s->map.y + 2))))
		return (-11);
	j = -1;
	while (++j < s->map.y)
		tmp[j] = s->map.tab[j];
	if ((tmp[s->map.y] = ft_map_line(s, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[s->map.y + 1] = NULL;
	if (s->map.y > 0)
		free(s->map.tab);
	s->map.tab = tmp;
	s->map.y++;
	return (0);
}

int		ft_parse_line(t_all *s, char *line)
{
	int		i;

	i = 0;
	ft_skip_space(line, &i);
	if ((line[i] == '1' || s->err.m == 1) && line[i] != '\0')
	{
		i = 0;
		s->err.n = ft_map(s, line, &i);
	}
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.e, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		s->err.n = ft_colors(&s->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		s->err.n = ft_colors(&s->tex.c, line, &i);
	if (ft_spaceskip(line, &i) && s->err.n == 0 && line[i] != '\0')
		return (ft_error(-10));
	if (s->err.n < 0)
		return (ft_error(s->err.n));
	else
		return (0);
}

int		ft_parse(t_all *s, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = 1;
	if (fd == -1)
		return (ft_error(1));
	while (ret == 1)
	{
		ret = ft_gnl(fd, &line);
		if (ft_parse_line(s, line) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (ret == -1 || ret == -3)
		return (ft_error(ret + 1));
	ft_start_position(s);
	return (ft_parse_chek(s));
}
