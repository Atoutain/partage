# include "../includes/fractol.h"

void		*check_1(void *cur_data)
{
	t_data		*data;

	data = (t_data *)cur_data;
	if (!ft_strcmp(data->name, "Mandelbrot"))
		is_mandelbrot(data, data->name);
	else if (!ft_strcmp(data->name, "Julia"))
		is_julia(data, data->name);
return(0);
}
