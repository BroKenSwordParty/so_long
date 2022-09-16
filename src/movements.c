/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:52:55 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/17 12:04:11 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hooks(t_map *s)
{
	mlx_hook (s->mw, 2, 1L << 0, inputs, s);
	mlx_hook (s->mw, 17, 1L << 5, close1, s);
}

int	inputs(int k, t_map *s)
{
	char	j;

	if (k <= 126 && k >= 123)
		m_up(s, k);
	else if (k == 53)
		close1(s);
	return (0);
}

void	m_up(t_map *s, int k)
{
	char	c;

	find_p(s);
	if (k == 126)
		c = s->map[(s->x[0]) - 1][s->x[1]];
	else if (k == 123)
		c = s->map[s->x[0]][(s->x[1] - 1)];
	else if (k == 125)
		c = s->map[(s->x[0]) + 1][s->x[1]];
	else if (k == 124)
		c = s->map[s->x[0]][(s->x[1] + 1)];
	if (c != '1')
	{
		if (c == 'E' && s->c == 0)
			exit2(s);
		else if (c != 'E')
		{
			if (c == 'C')
				s->c--;
			move_plz(s, k);
		}
	}
}

void	move_plz(t_map *s, int k)
{
	find_p(s);
	s->n_moves++;
	printf("Moves -> %d\n", s->n_moves);
	s->map[s->x[0]][s->x[1]] = '0';
	if (k == 126)
		s->map[(s->x[0]) - 1][s->x[1]] = 'P';
	else if (k == 123)
		s->map[s->x[0]][(s->x[1] - 1)] = 'P';
	else if (k == 125)
		s->map[(s->x[0]) + 1][s->x[1]] = 'P';
	else if (k == 124)
		s->map[s->x[0]][(s->x[1] + 1)] = 'P';
	mlx_clear_window(s->mx, s->mw);
	paint_map(s);
}
