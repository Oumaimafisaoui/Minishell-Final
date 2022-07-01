/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:50:58 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 20:08:19 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <limits.h>

static int	ft_intlen(long long n)
{
	long long	counter;

	counter = 0;
	if (n <= 0)
		++counter;
	while (n != 0)
	{
		++counter;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa1(long long n)
{
	long long	nbr;
	char		*s;
	int			l_s;

	nbr = n;
	l_s = ft_intlen(nbr);
	s = malloc(sizeof(char) * (l_s + 1));
	if (s == NULL)
		return (NULL);
	s[l_s--] = '\0';
	if (nbr == 0)
		s[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		s[0] = '-';
	}
	while (nbr > 0)
	{
		s[l_s--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (s);
}

int	to_num(char c)
{
	return (c -= 48);
}

int	is_long(char *next)
{
	int		index;
	char	*str;

	index = 0;
	str = ft_itoa1(LONG_MAX);
	if (ft_strlen(str) > ft_strlen(next))
		return (0);
	else if (ft_strlen(str) > ft_strlen(next))
		return (1);
	while (next[index])
	{
		if ((to_num(next[index]) > to_num(str[index])))
			return (1);
		index++;
	}
	return (0);
}
