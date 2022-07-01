/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:47:24 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:57:02 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int	l_str;

	l_str = ft_strlen(str);
	while (l_str >= 0)
	{
		if (*str == (char)n)
			return ((char *)str);
		str++;
		l_str--;
	}
	return (NULL);
}
