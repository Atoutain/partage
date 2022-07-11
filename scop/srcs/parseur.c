/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <atoutain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 00:38:55 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/09 03:46:52 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../lib/libft/includes/libft.h"
#include "../includes/scop.h"

t_data		*number_of_vector(t_data *data)
{
	int		vector_s;

	vector_s = 0;
	data->vector_number = 0;
	data->start_vector = 0;
	if((data->map = open("obj/teapot.obj", O_RDONLY, S_IREAD)) > 0)
	{
		while (get_next_line(data->map, &data->line))
		{
			if (data->line[0] == 'v')
			{
				vector_s = 1;
				data->vector_number++;
			}
			if (vector_s == 0)
			{
				data->start_vector++;
			}
		}
	}
	return(data);
}

t_vector	*parsing_vector(t_vector *vector, t_data *data)
{
	int		i;

	i = 0;
	if((data->map = open("obj/teapot.obj", O_RDONLY, S_IREAD)) > 0)
	{
		while (get_next_line(data->map, &data->line))
		{
			data->tab = ft_strsplit(data->line, ' ');
			if (data->line[0] == 'v')
			{
				vector[i].x = ft_atoi(data->tab[1]);
				vector[i].y = ft_atoi(data->tab[2]);
				vector[i].z = ft_atoi(data->tab[3]);
				i++;
			}
		}
	}
	return(vector);
}

int		main()
{
	t_data		*data;
	t_vector	*vector;
//	int		i = 0;

	data = (t_data *)malloc(sizeof(t_data));
	data = number_of_vector(data);
	vector = malloc(data->vector_number * sizeof(t_vector));
/*	while(i != data->vector_number)
	{
		vector[i].x = i;
		vector[i].y = i + 1;
		vector[i].z = i + 2;
		printf("x = %f \n", vector[i].x);
		printf("y = %f \n", vector[i].y);
		i++;
	}

	ft_putnbr(data->start_vector);*/
	vector = parsing_vector(vector, data);
	printf("z = %f \n", vector[1670].y);
	return(0);
}
