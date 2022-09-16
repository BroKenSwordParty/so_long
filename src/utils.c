/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:40:35 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/17 22:48:23 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	ft_strhei(ssize_t fd)
{
	size_t		i;
	char		*str;

	i = 0;
	str = "1";
	while (str)
	{
		str = get_next_line(fd);
		i++;
		free(str);
	}
	return (i);
}

void	init_map(t_map *stuc, char *arg_1)
{
	int		i;
	char	*buff;

	i = 0;
	stuc->fd = open(arg_1, O_RDONLY);
	if (stuc->fd == -1)
	{
		ft_putendl_fd(MAP_READ, 2);
		exit(1);
	}
	buff = get_next_line(stuc->fd);
	stuc->height = ft_strhei(stuc->fd);
	stuc->width = ft_strlen2(buff);
	stuc->line = NULL;
	free(buff);
	stuc->fd = close(stuc->fd);
	stuc->map = (char **)malloc(sizeof (char **) * (stuc->height + 1));
	stuc->fd = open(arg_1, O_RDONLY);
	map_tester(stuc);
	map_err(stuc);
	stuc->n_moves = 0;
}

void	map_tester(t_map *stuc)
{
	size_t	i;
	char	*line;

	i = 0;
	line = "1";
	while (line)
	{
		line = get_next_line(stuc->fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		else
			line[ft_strlen(line)] = '\0';
		ft_checkline(line, i, stuc);
		stuc->map[i] = line;
		stuc->line = ft_strjoin(stuc->line, line);
		i++;
	}
}

void	ft_checkline(char *line, size_t i, t_map *stuc)
{
	size_t	cont;

	printf("LINE -> %s", line);
	cont = 0;
	if (i == 0 || i == stuc->height)
	{
		while (cont < stuc->width)
		{
			if (line[cont] != '1')
				f_exit(MAP_WALL, line);
			cont++;
		}
	}
	else if (i != 0 && i != stuc->height)
	{
		if (ft_strlen(line) != stuc->width)
			f_exit(MAP_WID, line);
		else if ((line && line[0] != '1') || line[stuc->width - 1] != '1')
			f_exit(MAP_WALL, line);
	}
}

int	find_p(t_map *s)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (s->map[h])
	{
		w = 0;
		while (s->map[h][w])
		{
			if (s->map[h][w] == 'P')
			{
				s->x[0] = h;
				s->x[1] = w;
				return (0);
			}
			w++;
		}
		h++;
	}
	return (0);
}
