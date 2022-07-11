# include "../includes/fractol.h"

void		is_mandelbrot(t_data *data, char *name)
{
	init_data_mandelbrot(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->image_x, data->image_y, name);
	draw_mandelbrot(data);
	mlx_loop(data->mlx);
}
