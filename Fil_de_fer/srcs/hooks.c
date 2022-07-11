/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <atoutain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:41:54 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 12:26:05 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../lib/minilibx/mlx.h"

int		key_hook(int keycode, t_data *data)
{
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 27)
	{
		if (data->segment_long > 5)
		{
			data->segment_long = data->segment_long - 5;
			expose_hook(data);
		}
	}
	ft_hook2(keycode, data);
	return (0);
}

int		ft_hook2(int keycode, t_data *data)
{
	if (keycode == 24)
	{
		data->segment_long = data->segment_long + 5;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	if (keycode == 123)
	{
		data->ecart_x = data->ecart_x - 60;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	ft_hook3(keycode, data);
	return (0);
}

void	ft_hook3(int keycode, t_data *data)
{
	if (keycode == 125)
	{
		data->ecart_y = data->ecart_y + 60;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	if (keycode == 97)
	{
		data->zoom = data->zoom - 0.1;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	if (keycode == 100)
	{
		data->zoom = data->zoom + 0.1;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	ft_hook4(keycode, data);
}

int		ft_hook4(int keycode, t_data *data)
{
	if (keycode == 126)
	{
		data->ecart_y = data->ecart_y - 60;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	if (keycode == 124)
	{
		data->ecart_x = data->ecart_x + 60;
		mlx_clear_window(data->mlx, data->win);
		expose_hook(data);
	}
	return (0);
}
