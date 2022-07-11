# include "../includes/fractol.h"

int		key_hook_all(int keycode, t_data *data)
{
	key_hook_1(keycode, data);
	return(0);
}

int		key_hook_1(int keycode, t_data *data)
{
	t_data	*tmp;
	tmp = data;
	if (keycode == 53)
		exit(0);
	return(0);
}
