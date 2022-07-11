/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:52:56 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 13:13:43 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../lib/gnl/libft/includes/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/minilibx/mlx.h"

# define BUF_SIZE 20

typedef struct s_daata		t_daata;
typedef struct s_data		t_data;

struct				s_data
{
	t_daata			*daata;
	t_daata			*tmp;
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	int				segment_long;
	int				start;
	int				z;
	int				ecart_x;
	int				ecart_y;
	float			zoom;
	char			*data_img;
};

struct				s_daata
{
	struct s_daata	*next;
	int				x;
	int				y;
	int				z;
	float			x_amp;
	float			y_amp;
	int				x_max;
	int				y_max;
};

t_data				*open_window(t_data *data);
t_data				move_tmp(t_data *data);
t_data				move_tmp_first(int y, int x, t_data *data);

int					expose_hook(t_data *data);
int					key_hook(int keycode, t_data *data);
int					ft_hook2(int keycode, t_data *data);
int					ft_hook4(int keycode, t_data *data);
int					ft_hook5(int keycode, t_data *data);
int					ft_atoi(const char *s);
int					get_next_line(int fd, char **line);

char				**ft_strsplit(char const *s, char c);

void				ft_put_pixel_to_image(t_data *data,
					int x, int y, int color);
void				ft_hook3(int keycode, t_data *data);
void				ft_listadd(int x, int y, t_daata **daata, t_data *data);
void				set_point(t_data *data);
void				ft_tableur(t_daata **daata, t_data *data);

#endif
