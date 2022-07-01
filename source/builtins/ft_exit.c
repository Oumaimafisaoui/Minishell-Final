/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:38 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 20:08:41 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	suite9(char *str)
{
	if (check_valid(str) == 1)
		g_gen.exit_status = ft_atoll(str);
	if (check_valid(str) == 0 || is_long(str))
	{
		suite7(str);
		exit(255);
	}
}

int	ft_exit(char **next)
{
	if (ft_strlen2(next) == 1)
	{
		ft_putstr_fd("exit\n", 2);
		g_gen.exit_status = ft_atoll(*next);
	}
	if (ft_strlen2(next) == 2)
	{
		suite9(*(next + 1));
	}
	if (ft_strlen2(next) > 2)
	{
		if (check_valid(*(next + 1)) == 0)
		{
			suite8(*(next + 1));
			exit(255);
		}
		else if (check_valid(*(next + 1)) == 1)
		{
			suite8(*(next + 1));
			return (1);
		}
	}
	free_split(next);
	exit(g_gen.exit_status);
	return (0);
}

int	check_valid(char *next)
{
	int	index;

	index = 0;
	while (next[index])
	{
		if (!ft_isdigit(next[index]))
		{
			if ((next[index] == '+' || next[index] == '-') && index == 0)
			{
				index++;
				continue ;
			}
			return (0);
		}
		index++;
	}
	return (1);
}

void	suite7(char *str)
{
	ft_putstr_fd("Minishell : exit : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("  numeric argument required\n", 2);
	g_gen.exit_status = 255;
}

void	suite8(char *str)
{
	ft_putstr_fd("Minishell : exit : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("  Too many arguments\n", 2);
	g_gen.exit_status = 255;
}
