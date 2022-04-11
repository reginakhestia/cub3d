/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:59:29 by khestia           #+#    #+#             */
/*   Updated: 2022/04/11 13:56:32 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct_three(t_all s, char *file)
{
	t_pos	pos;
	t_dir	dir;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	s.pos = pos;
	s.dir = dir;
	s.mlx.ptr = mlx_init();
	if (ft_parse(&s, file) == -1)
		return (ft_close(&s, 0));
	// ВОТ ТУТ ЗАКОНЧИЛА
	ft_rotate(&s, 1);
	ft_move(&s, 1);
	ft_rotate(&s, -1);
	ft_move(&s, -1);
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	ft_draw(&s);
	mlx_hook(s.win.ptr, 2, 0, ft_key, &s);
	mlx_hook(s.win.ptr, 17, 0, ft_close, &s);
	mlx_loop(s.mlx.ptr);
	return (1);
}

void	ft_init_struct_two(t_all s, char *file)
{
	t_map	map;
	t_tex	tex;
	//t_spr	*spr;
	t_stk	*stk;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	//spr = NULL;
	stk = NULL;
	map.x = 0;
	map.y = 0;
	//map.spr = 0;
	tex.c = NULL;
	tex.f = NULL;
	s.map = map;
	s.tex = tex;
	//s.spr = spr;
	s.stk = stk;
	ft_init_struct_three(s, file);
}

void	ft_init_struct_one(char *file)
{
	t_all	s;
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;

	mlx.ptr = NULL;
	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = 2560;
	win.y = 1400;
	img.fsh = 0;
	err.n = 0;
	err.m = 0;
	err.p = 0;
	s.mlx = mlx;
	s.win = win;
	s.img = img;
	s.err = err;
	ft_init_struct_two(s, file);
}
