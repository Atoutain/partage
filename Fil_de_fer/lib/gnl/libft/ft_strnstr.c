/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:14:50 by bmartins          #+#    #+#             */
/*   Updated: 2015/10/08 22:13:46 by atoutain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	if (i > (size_t)ft_strlen(s1) || i > n)
		return (NULL);
	while (*s1 && i <= n)
	{
		if (!ft_memcmp(s1, s2, i))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
