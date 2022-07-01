/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:01:04 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/14 16:01:34 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str, const void *ptr, size_t n)
{
	size_t			index;
	unsigned char	*cast_str;
	unsigned char	*cast_ptr;

	cast_str = (unsigned char *)str;
	cast_ptr = (unsigned char *)ptr;
	if (str == NULL && ptr == NULL)
		return (0);
	index = 0;
	while (index < n)
	{
		if (cast_str[index] != cast_ptr[index])
			return (*(cast_str + index) - *(cast_ptr + index));
		index++;
	}
	return (0);
}
