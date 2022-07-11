# include "../includes/fractol.h"

int		rgb(int x, int y, int z)
{
	int		color;

	color = 0;
	color += x << 16;
	color += y << 8;
	color += z;
	return(color);
}

t_data		degrade(t_data *data, int color, int max, int min)
{
if (color == max)
		data->way = 1;
	else if (color == min)
		data->way = 0;
	if (data->way == 0)
		color = color + 1;
	else if (data->way == 1)
		color = color - 1;
	data->color_degrade = color;
	return(*data);
}
