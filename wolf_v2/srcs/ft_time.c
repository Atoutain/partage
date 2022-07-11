/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoutain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 00:57:41 by atoutain          #+#    #+#             */
/*   Updated: 2015/10/06 00:59:01 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../includes/wolf.h"

long double		ft_time(void)
{
	struct timeval		time;
	long				microsec;

	gettimeofday(&time, NULL);
	microsec = ((unsigned long long)time.tv_sec * 1000000) + time.tv_usec;
	return (microsec);
}
