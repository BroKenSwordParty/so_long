/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:31:17 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/17 12:02:25 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_map *s)
{
	s->mx = mlx_init();
	s->mw = mlx_new_window(s->mx, (s->width * 64), (s->height * 64), NAME);
	s->mi = mlx_new_image(s->mx, s->width * 64, s->height * 64);
}

void	xml_to_img(t_map *s)
{
	s->ig.w = mlx_xpm_file_to_image(s->mx, WALL, &s->ig.wid, &s->ig.hei);
	s->ig.s = mlx_xpm_file_to_image(s->mx, SAND, &s->ig.wid, &s->ig.hei);
	s->ig.p = mlx_xpm_file_to_image(s->mx, PLAY, &s->ig.wid, &s->ig.hei);
	s->ig.i = mlx_xpm_file_to_image(s->mx, ITEM, &s->ig.wid, &s->ig.hei);
	s->ig.e = mlx_xpm_file_to_image(s->mx, EXIT, &s->ig.wid, &s->ig.hei);
	s->ig.z = mlx_xpm_file_to_image(s->mx, EXIT, &s->ig.wid, &s->ig.hei);
}

void	paint_map(t_map *s)
{
	int	y;
	int	x;

	y = 0;
	while (y < s->height)
	{
		x = 0;
		while (x < s->width)
		{
			mlx_put_image_to_window(s->mx, s->mw, s->ig.s, x * 64, y * 64);
			if (s->map[y][x] == '1')
				mlx_put_image_to_window(s->mx, s->mw, s->ig.w, x * 64, y * 64);
			else if (s->map[y][x] == '0')
				mlx_put_image_to_window(s->mx, s->mw, s->ig.s, x * 64, y * 64);
			else if (s->map[y][x] == 'C')
				mlx_put_image_to_window(s->mx, s->mw, s->ig.i, x * 64, y * 64);
			else if (s->map[y][x] == 'P')
				mlx_put_image_to_window(s->mx, s->mw, s->ig.p, x * 64, y * 64);
			else if (s->map[y][x] == 'E')
				mlx_put_image_to_window(s->mx, s->mw, s->ig.z, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
