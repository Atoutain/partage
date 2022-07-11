# include "../includes/fractol.h"
# include <math.h>

void		draw_mandelbrot(t_data *data)
{
	double		x;
	double		y;
	int			i;

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
			while((data->z_r * data->z_r + data->z_i * data->z_i) < 4
			&& i < data->max_iter)
			{
				data->tmp = data->z_r;
				data->z_r = pow(data->z_r, 2) - pow(data->z_i, 2)
				+ data->c_r;
				data->z_i = 2 * data->z_i * data->tmp + data->c_i;
				i++;
			}
			if (i == data->max_iter)
			{
				ft_put_pixel_to_image(data, x, y, rgb(0, 0, 0));
			}
			else
			{
				ft_put_pixel_to_image(data, x, y, rgb(0, 0, i*255 / data->max_iter));
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

