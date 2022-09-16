/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:08:57 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/17 12:06:57 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/so_long.h"

void	exit2(t_map *s)
{
	mlx_destroy_window(s->mx, s->mw);
	ft_putendl_fd(WIN, 2);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	args_checker(argc, argv);
	init_map(&map, argv[1]);
	init_mlx(&map);
	xml_to_img(&map);
	paint_map(&map);
	hooks(&map);
	mlx_loop(&map.mx);
	return (0);
}
