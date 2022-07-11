# include "../includes/fractol.h"

void		draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while(x < data->image_x)
	{
		y = 0;
		while(y < data->image_y)
		{
			data->c_r = x / data->zoom + data->x1;
			data->c_i = y / data->zoom + data->y1;
			data->z_r = 0;
			data->z_i = 0;
			i = 0;
			while(data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& i < data->max_iter)
			{
				data->tmp = data->z_r;
				data->z_r = data->z_r * data->z_r - data->z_i * data->z_i
				+ data->c_i;
				data->z_i = 2 * data->z_i * data->tmp + data->c_i;
				i++;
			}
			if (i == data->max_iter)
			{
				mlx_pixel_put(data->mlx, data->win ,x, y, rgb(0, 255, x / 500));
			}
			y++;
		}
		x++;
	}
}
