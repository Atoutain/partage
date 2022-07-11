#include "../includes/fdf.h"

int		key_hook(int keycode, t_lol *lol)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 45)
	{
		if (lol->segment_long > 5)
		{
			lol->segment_long = lol->segment_long - 5;
			mlx_clear_window(lol->mlx, lol->win);
			expose_hook(lol);
			lol->ecart_x = lol->ecart_x - 1;
			mlx_clear_window(lol->mlx, lol->win);
			expose_hook(lol);
			lol->ecart_x = lol->ecart_x + 1;
			mlx_clear_window(lol->mlx, lol->win);
			expose_hook(lol);
		}
	}
	ft_hook2(keycode, lol);
	printf("%d\n", keycode);
	return(0);
}

int		ft_hook2(int keycode, t_lol *lol)
{
if (keycode == 61)
	{
		lol->segment_long = lol->segment_long + 5;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x - 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x + 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	if (keycode == 65361)
	{
		lol->ecart_x = lol->ecart_x - 61;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x + 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	ft_hook3(keycode, lol);
	return(0);
}

int		ft_hook3(int keycode, t_lol *lol)
{
if (keycode == 65364)
	{
		lol->ecart_y = lol->ecart_y + 60;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x - 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x + 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	if (keycode == 97)
	{
		lol->zoom = lol->zoom - 0.1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	if (keycode == 100)
	{
		lol->zoom = lol->zoom + 0.1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	ft_hook4(keycode, lol);
	return(0);
}

int		ft_hook4(int keycode, t_lol *lol)
{
if (keycode == 65362)
	{
		lol->ecart_y = lol->ecart_y - 60;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x - 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x + 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	if (keycode == 65363)
	{
		lol->ecart_x = lol->ecart_x + 60;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x - 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
		lol->ecart_x = lol->ecart_x + 1;
		mlx_clear_window(lol->mlx, lol->win);
		expose_hook(lol);
	}
	return(0);
}
