# include "../includes/fractol.h"

int		rgb(int x, int y, int z)
{
	int		color;

	color += x << 8;
	color += y << 4;
	color += z;
	return(color);
}
