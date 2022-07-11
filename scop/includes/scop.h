/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <atoutain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 01:04:01 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/09 02:56:52 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

typedef struct s_data		t_data;
typedef struct s_vector		t_vector;

struct			s_data
{
	char	*line;
	char	**tab;
	int		map;
	int		vector_number;
	int		start_vector;
};

struct			s_vector
{
	float	x;
	float	y;
	float	z;
};

int			get_next_line(int fd, char **line);

#endif
