/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:59:27 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/12 14:22:22 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <stdbool.h>

int			key_hook(int keycode, t_data *data)
{
	double		ms;
	double		rs;

	data->frametime = 0.03;
	ms = data->frametime * 30.0;
	rs = data->frametime * 3.0;
	if (keycode == 53)
	{
		mlx_clear_window ( data->mlx, data->win);
		mlx_destroy_window ( data->mlx, data->win);
		ft_bzero(data->data_img, data->h * data->w * 4);
		free(data);
		exit(0);
	}
	if (keycode == 65362)
		data->orien = data->orien + 10;
	if (keycode == 65364)
		data->orien = data->orien - 10;
	if (keycode == data->down)
	{
		if (data->filed_map[(int)(data->posx - data->dirx * ms)]
			[(int)(data->posy)] == 0)
			data->posx -= data->dirx * ms;
		if (data->filed_map[(int)(data->posx)][(int)(data->posy -
			data->diry * ms)] == 0)
			data->posy -= data->diry * ms;
	}
	data = key_hook2(keycode, data, ms, rs);
	expose_wolf(data);
	return (0);
}

t_data		*key_hook2(int keycode, t_data *data, double ms, double rs)
{
	data->frametime = 0.03;
	if (keycode == data->right)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(-rs) - data->diry * sin(-rs);
		data->diry = data->olddirx * sin(-rs) + data->diry * cos(-rs);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(-rs) - data->planey * sin(-rs);
		data->planey = data->oldplanex * sin(-rs) + data->planey * cos(-rs);
	}
	if (keycode == data->left)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(rs) - data->diry * sin(rs);
		data->diry = data->olddirx * sin(rs) + data->diry * cos(rs);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(rs) - data->planey * sin(rs);
		data->planey = data->oldplanex * sin(rs) + data->planey * cos(rs);
	}
	data = key_hook3(keycode, data, ms);
	return (data);
}

t_data		*key_hook3(int keycode, t_data *data, double ms)
{
	if (keycode == data->up)
	{
		if (data->filed_map[(int)(data->posx + data->dirx * ms)]
			[(int)(data->posy)] == 0 || data->filed_map[(int)(data->posx +
			data->dirx * ms)][(int)(data->posy)] == 9)
		{
			data->posx += (data->dirx * ms);
		}
		if (data->filed_map[(int)(data->posx)][(int)(data->posy +
			data->diry * ms)] == 0 || data->filed_map[(int)(data->posx)]
			[(int)(data->posy + data->diry * ms)] == 9)
		{
			data->posy += data->diry * ms;
		}
	}
	return (data);
}

int		motion_hook(int x, int y, t_data *data)
{
	double		ms;
	double		rs;

	data->frametime = 0.03;
	ms = data->frametime * 5.0;
	rs = data->frametime * 4.0;
	if(x > data->old_pos_mous)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(-rs) - data->diry * sin(-rs);
		data->diry = data->olddirx * sin(-rs) + data->diry * cos(-rs);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(-rs) - data->planey * sin(-rs);
		data->planey = data->oldplanex * sin(-rs) + data->planey * cos(-rs);
	}
	if(x < data->old_pos_mous)
	{
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(rs) - data->diry * sin(rs);
		data->diry = data->olddirx * sin(rs) + data->diry * cos(rs);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(rs) - data->planey * sin(rs);
		data->planey = data->oldplanex * sin(rs) + data->planey * cos(rs);
	}
/*	if(y < data->old_pos_mous_y)
	{
		data->orien = data->orien + 20;
	}
	if(y > data->old_pos_mous_y)
	{
		data->orien = data->orien - 20;
	}*/
	data->old_pos_mous_y = y;
	data->old_pos_mous = x;
	expose_wolf(data);
	return(0);
}
