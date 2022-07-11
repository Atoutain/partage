/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:27:52 by atoutain          #+#    #+#             */
/*   Updated: 2015/02/18 06:01:44 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>

void		ft_tableur(t_lel **lel, t_lol *lol)
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
			lol->z = ft_atoi(tab[x]);
			ft_listadd(x, y, lel, lol);
			x++;
			if (!tab[x])
				y++;
		}
	}
}

void		ft_listadd(int x, int y, t_lel **lel, t_lol *lol)
{
	float	const1;
	float	const2;
	t_lel	*new;
	float	hauteur;

	hauteur = 10;
	const1 = 0.5 + lol->zoom;
	const2 = 0.5 + lol->zoom;
	new = (t_lel *)malloc(sizeof(t_lel));
	new->x = x;
	new->y = y;
	new->z = lel->z;
	new->x_amp = const1 * x - const2 * y;
	new->x_amp = new->x_amp * lol->segment_long + lol->ecart_x;
	new->y_amp = ((float)-lel->z) / (hauteur) + (const1 / 2)
	* x + (const2 / 2) * y;
	new->y_amp = new->y_amp * lol->segment_long + lol->ecart_y;
	if (new->x_max < new->x)
		new->x_max = new->x;
	if(new->y_max < new->y)
		new->y_max = new->y;
	new->next = *lel;
	*lel = new;
}
