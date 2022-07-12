/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_wolf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:47:57 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 13:23:29 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_data		*init_first(t_data *data)
{
	data->orien = 0;
	data->x = 0;
	data->h = 800;
	data->w = 1000;
	data->posx = 2;
	data->posy = 2;
	data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->time = 0;
	data->oldtime = 0;
	data->up = 119;
	data->down = 115;
	data->right = 100;
	data->left = 97;
	return (data);
}
