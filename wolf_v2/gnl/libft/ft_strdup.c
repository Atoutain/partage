/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:32:20 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 20:12:53 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	s2 = ft_strnew(i);
	while (j <= i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && n >= i)
		i++;
	s2 = ft_strnew(i);
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
