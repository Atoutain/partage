/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:55:33 by atoutain          #+#    #+#             */
/*   Updated: 2022/07/12 00:09:44 by tbrowang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <fcntl.h>

t_data		*parsing(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	data->map = open(data->map_name, O_RDONLY);
	while (get_next_line(data->map, &data->line))
	{
		x = 0;
		data->tab = ft_strsplit(data->line, ' ');
		while (data->tab[x])
		{
			data->filed_map[y][x] = ft_atoi(data->tab[x]);
			free(data->tab[x]);
			x++;
			if (!data->tab[x])
				y++;
		}
		free(data->tab);
		free(data->line);
	}
	close(data->map);
	return (data);
}
