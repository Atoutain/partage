# include "../includes/fractol.h"

void		check_1(t_data *data, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		is_mandelbrot(data, name);
}
