/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:25:30 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:59:17 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	l_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (*s1 && ft_strchr(s2, *s1))
		s1++;
	l_s1 = ft_strlen((char *)s1);
	while (l_s1 != 0 && ft_strchr(s2, s1[l_s1]))
		l_s1--;
	return (ft_substr((char *)s1, 0, l_s1 + 1));
}
