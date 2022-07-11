# include "../includes/fractol.h"

int		expose_mandelbrot(t_data *data)
{
//	init_data_mandelbrot(data);
	draw_mandelbrot(data);
	return(0);
}

int		expose_julia(t_data *data)
{
	init_data_mandelbrot(data);
	draw_julia(data);
	return(0);
}
