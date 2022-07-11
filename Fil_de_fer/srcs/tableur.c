/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:27:52 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/07 11:48:50 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>

void		ft_tableur(t_daata **daata, t_data *data)
{
	char		**tab;
	int			map;
	char		*line;
	int			x;
	int			y;

	y = 0;
	map = open("map", O_RDONLY, S_IREAD);
	while (get_next_line(map, &line))
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[x])
		{
			data->z = ft_atoi(tab[x]);
			ft_listadd(x, y, daata, data);
			x++;
			if (!tab[x])
				y++;
		}
		free(tab);
		free(line);
	}
	close(map);
}

void		ft_listadd(int x, int y, t_daata **daata, t_data *data)
{
	float	const1;
	float	const2;
	t_daata	*new;
	float	hauteur;
	float	z_neg;

	z_neg = (float)data->z;
	hauteur = 10;
	const1 = 0.5 + data->zoom;
	const2 = 0.5 + data->zoom;
	new = (t_daata *)malloc(sizeof(t_daata));
	new->x = x;
	new->y = y;
	new->z = data->z;
	new->x_amp = const1 * x - const2 * y;
	new->x_amp = new->x_amp * data->segment_long + data->ecart_x;
	new->y_amp = -z_neg / (hauteur) + (const1 / 2) * x + (const2 / 2) * y;
	new->y_amp = new->y_amp * data->segment_long + data->ecart_y;
	if (new->x_max < new->x)
		new->x_max = new->x;
	if (new->y_max < new->y)
		new->y_max = new->y;
	new->next = *daata;
	*daata = new;
}
