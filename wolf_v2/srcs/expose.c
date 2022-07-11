/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:54:16 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/08 20:40:29 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		expose_wolf(t_data *data)
{
	mlx_clear_window ( data->mlx, data->win);
	ft_bzero(data->data_img, data->h * data->w * 4);
	data->x = 0;
	wolf_midlend(data);
	return (0);
}
