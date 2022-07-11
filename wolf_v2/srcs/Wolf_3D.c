/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:46:44 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/12 14:44:36 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <time.h>

void		wolf_start(t_data *data)
{
	data = init_first(data);
	data = parsing(data);
	if(data->filed_map[(int)data->posx][(int)data->posy] != 0)
	{
		ft_putendl("Map invalide !");
		exit(0);
	}
	if (ft_strcmp(data->map_name, "map") == 0)
	{
		data = open_window(data);
	}
	data = wolf_midlend(data);
	mlx_loop(data->mlx);
//	free(data);
}

t_data		*wolf_midlend(t_data *data)
{
	char		*tmp;

	tmp = 0;
	while (data->x < data->w)
	{
		data = calcul_un(data);
		data = cond_forest(data);
		data = wall_detect(data);
		data = wall_height(data);
		draw_vert_line(data->drawstart, data->drawend, data->x, data);
		data->x = data->x + 1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_do_key_autorepeaton(data->mlx);
//	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 6, (1L << 6), motion_hook, data);
	mlx_hook(data->win, 2, (1L << 0), key_hook, data);
	mlx_do_sync(data->mlx);
	mlx_expose_hook(data->win, expose_wolf, data);
/*	if (data->filed_map[(int)data->posx][(int)data->posy] == 9)
	{
		data->t = data->t + 1;
		tmp = ft_itoa(data->t);
		free(data->map_name);
		data->map_name = ft_strjoin("map", tmp);
		ft_bzero(data->data_img, data->h * data->w * 4);
		data->x = 0;
		wolf_start(data);
	}*/
	return (data);
}
