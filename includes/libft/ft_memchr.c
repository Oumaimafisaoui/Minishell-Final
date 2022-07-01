/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:57:45 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:57:48 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*str, int c, size_t n)
{
	size_t			index;
	unsigned char	*s;

	s = (unsigned char *)str;
	index = 0;
	while (index < n)
	{
		if (*(s + index) == (unsigned char)c)
			return (&s[index]);
		index++;
	}
	return (NULL);
}
