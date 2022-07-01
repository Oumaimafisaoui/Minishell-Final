/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:19 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 04:33:51 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strlen2(char **str)
{
	int	index;

	index = 0;
	if (str)
		while (str[index])
			index++;
	return (index);
}

char	*join_str(const char *s1, const char *s2)
{
	int		index;
	int		len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	index = 0;
	while (s1 && s1[index])
	{
		s[index] = s1[index];
		index++;
	}
	while (s2 && s2[index - len])
	{
		s[index] = s2[index - len];
		index++;
	}
	s[index] = '\0';
	return (s);
}

long long	ft_atoll(const char *dest)
{
	int			sign;
	long long	result;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	while (((dest[i] == ' ') || (dest[i] >= 9 && dest[i] <= 13)) \
	&& !(dest[i] == '-' || dest[i] == '+'))
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

void	print_err_exp(char *next)
{
	ft_putstr_fd("Minishell: export: `", 2);
	ft_putstr_fd(next, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	print_err_uns(char *next)
{
	ft_putstr_fd("Minishell: unset: `", 2);
	ft_putstr_fd(next, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}
