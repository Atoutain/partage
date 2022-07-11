/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:56:27 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 13:25:59 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_data		*cond_forest(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->etapex = -1;
		data->distmurx = (data->rayposx - data->mapx) * data->dist2murx;
	}
	else
	{
		data->etapex = 1;
		data->distmurx = (data->mapx + 1.0 - data->rayposx) * data->dist2murx;
	}
	if (data->raydiry < 0)
	{
		data->etapey = -1;
		data->distmury = (data->rayposy - data->mapy) * data->dist2mury;
	}
	else
	{
		data->etapey = 1;
		data->distmury = (data->mapy + 1.0 - data->rayposy) * data->dist2mury;
	}
	return (data);
}

t_data		*wall_detect(t_data *data)
{
	while (data->touche == 0 && data->mapx >= 0 && data->mapy >= 0)
	{
		if (data->distmurx < data->distmury)
		{
			data->distmurx += data->dist2murx;
			data->mapx += data->etapex;
			data->murvertiouhori = 0;
		}
		else
		{
			data->distmury += data->dist2mury;
			data->mapy += data->etapey;
			data->murvertiouhori = 1;
		}
		if (data->filed_map[data->mapx][data->mapy] > 0 &&
		data->mapx >= 0 && data->mapy >= 0)
		{
			data->touche = 1;
		}
	}
	return (data);
}

t_data		*wall_height(t_data *data)
{
	if (data->murvertiouhori == 0)
	{
		data->longueurmur = fabs((data->mapx - data->rayposx +
		(1 - data->etapex) / 2) / data->raydirx);
	}
	else
	{
		data->longueurmur = fabs((data->mapy - data->rayposy +
		(1 - data->etapey) / 2) / data->raydiry);
	}
	data->hauteurmur = abs((int)(data->h / data->longueurmur));
	data->drawstart = (-data->hauteurmur / 2 + data->h / 2) + data->orien;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = (data->hauteurmur / 2 + data->h / 2) + data->orien;
	if (data->drawend >= data->h)
		data->drawend = data->h - 1;
	return (data);
}
