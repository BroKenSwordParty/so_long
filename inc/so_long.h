/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:33:30 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/17 12:11:10 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define NAME "I WANTED TO DO FRACTOL, BUT LOOK THIS DISABLED PIRATE!"

# define WALL "./assets/_oseano.xpm"
# define SAND "./assets/_sand.xpm"
# define PLAY "./assets/_BorderlinePirate.xpm"
# define ITEM "./assets/_item.xpm"
# define EXIT "./assets/_exit.xpm"

# define MOVE "Nº movements --> "

# define ARG_NUM "Error\nMust introduce 2 valid arguments\n"
# define ARG_INV "Error\nInvalid argument\n"
# define ARG_BER "Error\nFile must be .ber\n"
# define F_ERR "Error\nFile error\n"
# define MAP_READ "Error\nUnable to read the file\n"
# define MAP_WALL "Error\nMap must be sorrounded by walls\n"
# define MAP_WID "Error\nRow width must be the same\n"
# define MAP_PEC "Error\nMap contains invalid characters\n"
# define MAP_P2 "Error\nMap contains more than 1 Player\n"
# define MAP_P "Error\nNo PLAYER in this map\n"
# define MAP_E "Error\nNo EXIT in this map\n"
# define MAP_C "Error\nNo COLLECTABLE in this map\n"
# define EXIT2 "Closing the game\n"
# define WIN "YOU FOUND THE TREASURE!!!!\n"

typedef struct s_img
{
	void	*w;
	void	*s;
	void	*p;
	void	*i;
	void	*e;
	void	*z;
	int		hei;
	int		wid;
}				t_img;

typedef struct s_map
{
	ssize_t		fd;
	size_t		width;
	size_t		height;
	char		**map;
	char		*line;
	char		k;
	int			x[2];
	int			n_moves;
	int			c;
	void		*mx;
	void		*mw;
	void		*mi;
	t_img		ig;
}				t_map;

size_t	ft_strhei(ssize_t fd);
int		inputs(int k, t_map *s);
int		close1(t_map *s);
void	args_checker(int argc, char **argv);
void	init_map(t_map *stuc, char *arg_1);
void	map_tester(t_map *stuc);
void	map_err(t_map *s);
void	map_err2(char *line);
void	f_exit(char *problem, char *to_free);
void	ft_checkline(char *line, size_t i, t_map *stuc);
void	init_mlx(t_map *s);
void	xml_to_img(t_map *s);
void	paint_map(t_map *s);
int		find_p(t_map *s);
void	hooks(t_map *s);
void	m_up(t_map *s, int k);
void	move_plz(t_map *s, int k);
void	exit2(t_map *s);

#endif