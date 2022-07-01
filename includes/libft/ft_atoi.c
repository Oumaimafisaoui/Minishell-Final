/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:15:26 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 16:58:23 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *dest)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	if (*dest == 0)
		return (0);
	while (dest[i] == ' ' || (dest[i] >= 9 && dest[i] <= 13))
		i++;
	if (dest[i] == '-' || dest[i] == '+')
	{
		if (dest[i] == '-')
			sign *= -1;
		i++;
	}
	while (dest[i] && dest[i] <= '9' && dest[i] >= '0')
	{
		result *= 10;
		result += (dest[i] - 48);
		i++;
	}
	return (result * sign);
}
