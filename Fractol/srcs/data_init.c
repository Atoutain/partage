# include "../includes/fractol.h"
#include <stdio.h>

t_data		init_data_mandelbrot(t_data *data)
{
	data->zoom = 500;
	data->max_iter = 50;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	data->img = mlx_new_image(data->mlx, data->image_x, data->image_y);
	data->data = mlx_get_data_addr(data->img, &(data->bpp),
	&(data->size_line), &(data->endian));
	data->color_degrade = 1;
	data->way = 1;
	return(*data);
}
