/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:51:39 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:58:45 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	l_str;
	char	*p;

	l_str = ft_strlen(str) + 1;
	p = ft_calloc(l_str, sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, str, l_str);
	return (p);
}
