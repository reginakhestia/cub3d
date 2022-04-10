/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:45:11 by khestia           #+#    #+#             */
/*   Updated: 2022/04/10 20:10:02 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_chek_name(argv[1], ".cub") == 1)
		write(2, "Invalid arguments\n", 18);
	else
		ft_init_struct_one(argv[1]);
}
