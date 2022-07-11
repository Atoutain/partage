/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 01:09:00 by atoutain          #+#    #+#             */
/*   Updated: 2015/02/18 06:53:42 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minilibx/mlx.h"
#include "../includes/fdf.h"
#include <unistd.h>
#include <stdio.h>

void		set_point(t_lol *lol, void *win, void *mlx)
{
	int		x;
	int		y;
	int		x1;

	x = 4242;
	y= 0;
	while(lol->lel != NULL)
	{
		if (x != 4242)
		{
			x1 = x;
			while(x >= lol->lel->x_amp)
			{
				mlx_pixel_put(mlx, win, x, y+((lol->lel->y_amp - y) * (x - x1)) / (lol->lel->x_amp - x1), 0x00FF84);
				x--;
			}
		}
		mlx_pixel_put(mlx, win, (int)lol->lel->x_amp, (int)lol->lel->y_amp, 0xF9009F);
		x = lol->lel->x_amp;
		y= lol->lel->y_amp;
		lol->lel = lol->lel->next;
	}
}

t_lol		move_tmp(t_lol *lol)
{
		if (lol->tmp->x > lol->lel->x)
		{
		while (lol->tmp->x > lol->lel->x)
				lol->tmp = lol->tmp->next;
		}
		if (lol->tmp->x < lol->lel->x)
		{
			while (lol->tmp->x < lol->lel->x)
				lol->lel = lol->lel->next;
		}
	return (*lol);
}

t_lol		move_tmp_first(int y, int x, t_lol *lol)
{
	while (y != x)
	{
		lol->tmp = lol->tmp->next;
		y--;
	}
	return(*lol);
}

void		draw_finish(t_lol *lol, void *win, void *mlx)
{
	int		x;
	int		y;
	int		x1;

	x = 0;
	y = lol->lel->x;
	lol->tmp = lol->tmp->next;
	move_tmp_first(y, x, lol);
	while (lol->tmp != NULL)
	{
		move_tmp(lol);
		x = lol->lel->x_amp;
		y = lol->lel->y_amp;
		x1 = x;
		while (x <= lol->tmp->x_amp)
		{
			mlx_pixel_put(mlx, win, x, y+((lol->tmp->y_amp - y) * (x - x1)) / (lol->tmp->x_amp - x1), 0x00FF84);
			x++;
		}
		lol->lel = lol->lel->next;
		lol->tmp = lol->tmp->next;
	}
}


int		expose_hook(t_lol *lol)
{
	ft_tableur(&lol->lel, lol);
	set_point(lol, lol->win, lol->mlx);
	ft_tableur(&lol->lel, lol);
	ft_tableur(&lol->tmp, lol);
	draw_finish(lol, lol->win, lol->mlx);
	return(0);
}




int			main(void)
{
	t_lol	*lol;

	lol = (t_lol *)malloc(sizeof(t_lol));
	lol->segment_long = 5;
	lol->zoom = 0;
	lol->start = 600;
	lol->ecart_x = 1200;
	lol->ecart_y = 600;
	lol->mlx = mlx_init();
	lol->win = mlx_new_window(lol->mlx, 2000, 2000, "lel");

	lol->lel = (t_lel *)malloc(sizeof(t_lel));
	lol->lel = NULL;
	ft_tableur(&lol->lel, lol);
	lol->tmp = (t_lel *)malloc(sizeof(t_lel));
	lol->tmp = NULL;
	ft_tableur(&lol->tmp, lol);
	set_point(lol, lol->win, lol->mlx);
	ft_tableur(&lol->lel, lol);
	draw_finish(lol, lol->win, lol->mlx);
	mlx_key_hook(lol->win, key_hook, lol);
	mlx_expose_hook(lol->win, expose_hook, lol);
	mlx_loop(lol->mlx);
	free(lol);
	return (0);
}
