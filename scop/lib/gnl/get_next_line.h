/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 21:37:06 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/09 01:14:11 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 4096

int		get_next_line(int const fd, char **line);

#endif
