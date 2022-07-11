/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:56:00 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/06 05:18:41 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_data		*open_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w, data->h, "wolf_v2");
	data->img = mlx_new_image(data->mlx, data->w, data->h);
	data->data_img = mlx_get_data_addr(data->img, &(data->bpp),
	&(data->size_line), &(data->endian));
	return (data);
}
