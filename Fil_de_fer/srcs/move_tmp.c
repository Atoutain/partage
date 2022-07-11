/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <atoutain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:37:34 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 11:48:36 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_data		move_tmp(t_data *data)
{
	if (data->tmp->x > data->daata->x)
	{
		while (data->tmp->x > data->daata->x)
			data->tmp = data->tmp->next;
	}
	if (data->tmp->x < data->daata->x)
	{
		while (data->tmp->x < data->daata->x)
			data->daata = data->daata->next;
	}
	return (*data);
}

t_data		move_tmp_first(int y, int x, t_data *data)
{
	while (y != x)
	{
		data->tmp = data->tmp->next;
		y--;
	}
	return (*data);
}
