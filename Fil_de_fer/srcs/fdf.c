/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 01:09:00 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 12:29:18 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/mlx.h"
#include "../includes/fdf.h"
#include <unistd.h>
#include <stdio.h>

void		set_point(t_data *data)
{
	int		x;
	int		y;
	int		x1;

	x = 4242;
	y = 0;
	while (data->daata != NULL)
	{
		if (x != 4242)
		{
			x1 = x;
//			while (x >= data->daata->x_amp && data->daata->y_amp > 40 && 
//			data->daata->x_amp < 1560 && data->daata->y_amp < 960 && 
//			data->daata->x_amp > 40)
			while (x >= data->daata->x_amp && y > 40 && x < 1560 && y < 960 && x > 40)
			{
				ft_put_pixel_to_image(data, x, y + ((data->daata->y_amp - y)
				* (x - x1)) / (data->daata->x_amp - x1), 0x00FF84);
				x--;
			}
		}
//		ft_put_pixel_to_image(data, (int)data->daata->x_amp,
//		(int)data->daata->y_amp, 0xF9009F);
		x = data->daata->x_amp;
		y = data->daata->y_amp;
		data->daata = data->daata->next;
	}
}

void		draw_finish(t_data *data)
{
	int		x;
	int		y;
	int		x1;

	x = 0;
	y = data->daata->x;
	data->tmp = data->tmp->next;
	move_tmp_first(y, x, data);
	while (data->tmp != NULL)
	{
		move_tmp(data);
		x = data->daata->x_amp;
		y = data->daata->y_amp;
		x1 = x;
//		while (x <= data->tmp->x_amp && data->daata->y_amp > 40 && 
//		data->daata->x_amp < 1560 && data->daata->y_amp < 960 && 
//		data->daata->x_amp > 40)
		while (x <= data->tmp->x_amp && y > 40 && x < 1560 && y < 960 && x > 40)
		{
			ft_put_pixel_to_image(data, x, y + ((data->tmp->y_amp - y) *
			(x - x1)) / (data->tmp->x_amp - x1), 0x00FF84);
			x++;
		}
		data->daata = data->daata->next;
		data->tmp = data->tmp->next;
	}
}

int			expose_hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_bzero(data->data_img, 2000 * 2000 * 4);
	data->daata = NULL;
	data->tmp = NULL;
	ft_tableur(&data->daata, data);
	set_point(data);
	data->daata = NULL;
	ft_tableur(&data->daata, data);
	ft_tableur(&data->tmp, data);
	draw_finish(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int			main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->segment_long = 5;
	data->zoom = 3;
	data->start = 900;
	data->ecart_x = 1200;
	data->ecart_y = 600;
	data = open_window(data);
	data->daata = (t_daata *)malloc(sizeof(t_daata));
	data->daata = NULL;
	ft_tableur(&data->daata, data);
	data->tmp = (t_daata *)malloc(sizeof(t_daata));
	data->tmp = NULL;
	ft_tableur(&data->tmp, data);
//	set_point(data);
//	ft_tableur(&data->daata, data);
	draw_finish(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}
