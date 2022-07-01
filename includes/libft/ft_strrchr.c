/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:50:55 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:57:10 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	l_str;

	l_str = ft_strlen(str);
	while (l_str >= 0)
	{
		if (str[l_str] == (char)n)
			return ((char *)str + l_str);
		l_str--;
	}
	return (0);
}
