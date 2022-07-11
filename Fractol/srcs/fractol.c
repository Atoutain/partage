#include "../includes/fractol.h"
int		main(int ac, char **av)
{
	t_data	*data;
	t_data	*tmp;
	int		i;

	ac = 0;
	tmp = (t_data *)malloc(sizeof(t_data));
	data = (t_data *)malloc(sizeof(t_data));
	i = 1;
	if (!av[i])
	{
		ft_putendl("un argument minimum pls");
	}
	while(av[i])
	{
		*tmp = *data;
		tmp->name = av[i];
		check_1(tmp);
		i++;
	}
}
