# include "../includes/fractol.h"

t_data		init_data_mandelbrot(t_data *data)
{
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->zoom = 100;
	data->max_iter = 50;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	return(*data);
}
