/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:26:08 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/17 16:42:37 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	args_checker(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd(ARG_NUM, 2);
		exit (0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_putendl_fd(ARG_INV, 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putendl_fd(ARG_BER, 2);
		exit(0);
	}
}

void	map_err(t_map *s)
{
	int	i;
	int	p;

	p = 0;
	map_err2(s->line);
	i = 0;
	s->c = 0;
	while (s->line[i])
	{
		if ((s->line[i] != '1') && (s->line[i] != '0') && (s->line[i] != 'P'
			) && (s->line[i] != 'E') && (s->line[i] != 'C'))
			f_exit(MAP_PEC, s->line);
		else if (s->line[i] == 'P')
			p++;
		else if (s->line[i] == 'C')
			s->c++;
		i++;
	}
	if (p > 1)
		f_exit(MAP_P2, s->line);
}

void	map_err2(char *line)
{
	if (!ft_strchr(line, 'P'))
		f_exit(MAP_P, line);
	else if (!ft_strchr(line, 'E'))
		f_exit(MAP_E, line);
	else if (!ft_strchr(line, 'C'))
		f_exit(MAP_C, line);
}

void	f_exit(char *problem, char *to_free)
{
	ft_putendl_fd(problem, 2);
	free(to_free);
	exit (0);
}

int	close1(t_map *s)
{
	mlx_clear_window(s->mx, s->mw);
	mlx_destroy_window(s->mx, s->mw);
	ft_putendl_fd(EXIT2, 2);
	exit (0);
}
