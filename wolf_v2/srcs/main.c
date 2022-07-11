/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:54:47 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/12 13:15:20 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/wolf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->map_name = ft_strdup("map");
	data->t = 1;
	wolf_start(data);
	free(data);
	return (0);
}
