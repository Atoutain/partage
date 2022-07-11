# include "../includes/fractol.h"

void		is_mandelbrot(t_data *data, char *name)
{
	data->x1 = -0.75;
	data->x2 = 0.5;
	data->y1 = -0.625;
	data->y2 = 0.625;
	data->stahp = 0;
	data->mlx = mlx_init();
	init_data_mandelbrot(data);
	data->win = mlx_new_window(data->mlx, data->image_x, data->image_y, name);
	draw_mandelbrot(data);
	mlx_mouse_hook(data->win, mouse_hook_all, data);
	mlx_key_hook(data->win, key_hook_all, data);
	mlx_expose_hook(data->win, expose_mandelbrot, data);
	mlx_loop(data->mlx);
}

void		is_julia(t_data *data, char *name)
{
	data->mlx = mlx_init();
	data->x1 = -0.75;
	data->x2 = 0.5;
	data->y1 = -0.625;
	data->y2 = 0.625;
	data->c_r = 0.285;
	data->c_i = 0.01;
	init_data_mandelbrot(data);
	data->win = mlx_new_window(data->mlx, data->image_x, data->image_y, name);
	draw_julia(data);
	mlx_hook(data->win, 6, (1L << 6), motion_hook, data);
	mlx_key_hook(data->win, key_hook_all, data);
	mlx_expose_hook(data->win, expose_julia, data);
	mlx_loop(data->mlx);
}
