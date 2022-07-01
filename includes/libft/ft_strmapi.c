/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:51:57 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 18:29:30 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	c;

	if (!s || !f)
		return (NULL);
	c = 0;
	res = ft_strdup(s);
	if (res == NULL)
		return (NULL);
	while (res[c] != 0)
	{
		res[c] = f(c, res[c]);
		c++;
	}
	return (res);
}
