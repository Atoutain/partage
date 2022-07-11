/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:52:38 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 11:28:58 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_put_pixel_to_image(t_data *data, int x, int y, int color)
{
	int			in;

	in = (x * (data->bpp >> 3)) + (y * data->size_line);
	data->data_img[in] = color & 0xff;
	data->data_img[in + 1] = (color & 0xff00) >> 8;
	data->data_img[in + 2] = (color & 0xff0000) >> 16;
}
