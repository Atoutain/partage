/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 01:15:34 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/12 14:20:06 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include "../gnl/libft/includes/libft.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct s_data	t_data;

struct		s_data
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*map_name;
	char	*line;
	char	*data_img;

	char	**tab;

	int		old_pos_mous;
	int		old_pos_mous_y;

	int		map;
	int		color;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		w;
	int		h;
	int		t;
	int		r;
	int		g;
	int		b;
	int		left;
	int		right;
	int		up;
	int		down;
	int		mapx;
	int		mapy;
	int		hauteurmur;
	int		drawstart;
	int		drawend;
	int		etapex;
	int		etapey;
	int		touche;
	int		murvertiouhori;

	int		filed_map[100][100];

	double	orien;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	distmurx;
	double	distmury;
	double	dist2murx;
	double	dist2mury;
	double	longueurmur;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
};

t_data		*choose_color(t_data *data);
t_data		*folow(t_data *data);
t_data		*wall_height(t_data *data);
t_data		*wall_detect(t_data *data);
t_data		*calcul_un(t_data *data);
t_data		*init_first(t_data *data);
t_data		*cond_forest(t_data *data);
t_data		*draw_vert_line(int drawstart, int drawend, int x, t_data *data);
t_data		*wolf_midlend(t_data *data);
t_data		*open_window(t_data *data);
t_data		*parsing(t_data *data);
t_data		*key_hook2(int keycode, t_data *data, double ms, double rs);
t_data		*key_hook3(int keycode, t_data *data, double ms);

double long	ft_time();

int			motion_hook(int x, int y, t_data *data);
int			key_hook(int keycode, t_data *data);
int			expose_wolf(t_data *data);
int			rgb(int x, int y, int z);
int			get_next_line(int fd, char **line);

void		wolf_start(t_data *data);
void		ft_put_pixel_to_image(t_data *data, int x, int y, int color);

#endif
