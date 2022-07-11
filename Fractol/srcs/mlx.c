#include "../includes/fractol.h"

void		ft_put_pixel_to_image(t_data *data, int x, int y, int color)
{
	int			in;

	in = (x * (data->bpp >> 3)) + (y * data->size_line);
	data->data[in] = color & 0xff;
	data->data[in + 1] = (color & 0xff00) >> 8;
	data->data[in + 2] = (color & 0xff0000) >> 16;
}
