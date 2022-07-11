/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <atoutain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 11:20:19 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 12:26:24 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_data		*open_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1600, 1000, "fdf");
	data->img = mlx_new_image(data->mlx, 1600, 1000);
	data->data_img = mlx_get_data_addr(data->img, &(data->bpp),
	&(data->size_line), &(data->endian));
	return (data);
}
