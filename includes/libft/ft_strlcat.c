/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:17:18 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:56:46 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	des_i;
	size_t	src_i;

	des_i = 0;
	src_i = 0;
	while (dest[des_i] && des_i < size)
		des_i++;
	while (src[src_i] && ((des_i + src_i + 1) < size))
	{
		dest[des_i + src_i] = src[src_i];
		src_i++;
	}
	if (des_i != size)
		dest[des_i + src_i] = '\0';
	return (des_i + ft_strlen(src));
}
