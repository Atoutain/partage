#include "../includes/fractol.h"

int		main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(sizeof(t_data));
	i = 1;
	if (!av[i])
	{
		ft_putendl("un argument minimum pls");
	}
	while(av[i])
	{
		check_1(data, av[i]);
		i++;
	}
}
