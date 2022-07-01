/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:08:53 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/19 11:21:54 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	if ((!dest && !src) || !n)
		return (dest);
	cast_src = (unsigned char *)src;
	cast_dest = (unsigned char *)dest;
	if (cast_src < cast_dest)
	{
		while (n--)
		{
			cast_dest[n] = cast_src[n];
		}
	}
	else
	{
		ft_memcpy(cast_dest, cast_src, n);
	}
	return (dest);
}
