/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 04:33:16 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_arg(char *next)
{
	int	index;

	index = 0;
	if (!next)
		return (0);
	if (ft_isdigit(next[0]) || next[0] == '=')
		return (1);
	while (next[index])
	{
		if (next[index] == '=')
			break ;
		if (!ft_isalnum(next[index]) && next[index] != '_')
			return (1);
		index++;
	}
	return (0);
}

int	check_arg2(char *next)
{
	int	index;

	index = 0;
	if (!next)
		return (0);
	if (!next[index] || (!ft_isalpha(next[index]) && next[index] != '_'))
		return (1);
	index++;
	while (next[index])
	{
		if ((next[index] != '_' && !ft_isalnum(next[index])))
			return (1);
		index++;
	}
	return (0);
}

int	array_len(char **array)
{
	int	index;

	index = 0;
	while (array[index + 1])
		index++ ;
	return (index);
}

char	*ft_to_lower(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	return (str);
}
