/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:50:41 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 13:22:26 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int			rgb(int x, int y, int z)
{
	int		color;

	color = 0;
	color += x << 16;
	color += y << 8;
	color += z;
	return (color);
}

t_data		*folow2(t_data *data)
{
	if (data->filed_map[data->mapx][data->mapy] == 5)
	{
		data->r = 124;
		data->g = 255;
		data->b = 0;
	}
	if (data->filed_map[data->mapx][data->mapy] == 6)
	{
		data->r = 123;
		data->g = 255;
		data->b = 123;
	}
	if (data->filed_map[data->mapx][data->mapy] == 7)
	{
		data->r = 187;
		data->g = 98;
		data->b = 150;
	}
	return (data);
}

t_data		*folow(t_data *data)
{
	if (data->filed_map[data->mapx][data->mapy] == 4)
	{
		data->r = 255;
		data->g = 255;
		data->b = 0;
	}
	if (data->filed_map[data->mapx][data->mapy] == 9)
	{
		data->r = 255;
		data->g = 255;
		data->b = 255;
	}
	if (data->murvertiouhori == 1)
	{
		data->r = data->r / 2;
		data->g = data->g / 2;
		data->b = data->b / 2;
	}
	data->color = rgb(data->r, data->g, data->b);
	data = folow2(data);
	return (data);
}

t_data		*choose_color(t_data *data)
{
	if (data->filed_map[data->mapx][data->mapy] == 1)
	{
		data->r = 255;
		data->g = 0;
		data->b = 0;
	}
	if (data->filed_map[data->mapx][data->mapy] == 2)
	{
		data->r = 0;
		data->g = 255;
		data->b = 0;
	}
	if (data->filed_map[data->mapx][data->mapy] == 3)
	{
		data->r = 0;
		data->g = 0;
		data->b = 255;
	}
	data = folow(data);
	return (data);
}
