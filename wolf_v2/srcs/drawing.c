/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:51:27 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/12 13:20:20 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_data		*draw_vert_line(int drawstart, int drawend, int x, t_data *data)
{
	int		y;

	y = 0;
	data = choose_color(data);
	while (y < drawstart)
	{
		ft_put_pixel_to_image(data, x, y, rgb(119, 51, 0));
		y++;
	}
	while (y < drawend)
	{
		ft_put_pixel_to_image(data, x, y, data->color);
		y++;
	}
	while (y < data->h)
	{
		ft_put_pixel_to_image(data, x, y, rgb(87, 51, 0));
		y++;
	}
	return (data);
}
