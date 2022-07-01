/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:41:09 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/19 11:22:37 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	if ((!dest && !src) || !n)
		return (dest);
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		*(cast_dest + index) = *(cast_src + index);
		index++;
	}
	return (dest);
}
