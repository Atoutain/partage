/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_wolf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:53:03 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 13:21:22 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_data		*calcul_un(t_data *data)
{
	data->camerax = 2 * data->x / (double)data->w - 1;
	data->rayposx = data->posx;
	data->rayposy = data->posy;
	data->raydirx = data->dirx + data->planex * data->camerax;
	data->raydiry = data->diry + data->planey * data->camerax;
	data->mapx = (int)data->rayposx;
	data->mapy = (int)data->rayposy;
	data->dist2murx = sqrt(1 + (data->raydiry * data->raydiry) /
	(data->raydirx * data->raydirx));
	data->dist2mury = sqrt(1 + (data->raydirx * data->raydirx) /
	(data->raydiry * data->raydiry));
	data->touche = 0;
	return (data);
}
