#include "../includes/fractol.h"

int		mouse_hook_all(int button,int x,int y,t_data *data)
{
	int		h;
	t_data	*tmp;

	tmp = data;
	h = 1;
	if (button == 1)
	{
		data->x1 = x - 0.5;
		data->x2 = x + 0.5;
		data->y1 = y - 0.5;
		data->y2 = y - 0.5;
		data->zoom = data->zoom + 50;
		data->max_iter = data->max_iter + 50;
		expose_mandelbrot(data);
	}
	return(0);
}

int		motion_hook(int x, int y, t_data *data)
{
	if ((x % 8 == 0) && (y % 15 == 0))
	{
		data->c_r = (x - data->image_x) / data->zoom;
		data->c_i = (y - data->image_y) / data->zoom;
		ft_bzero(data->data, data->image_x * data->image_y * 4);
	//	init_data_mandelbrot(data);
		draw_julia(data);
	}
	return(0);
}
