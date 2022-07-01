/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:31 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 20:22:23 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	suite(char **str)
{
	int	index;
	int	flag;

	index = 1;
	flag = 0;
	while (str[index] && set_flag(str[index]))
	{
		flag = 1;
		index++;
	}
	while (str[index])
	{
		ft_putstr_fd(str[index], 1);
		index++;
		if (str[index])
			ft_putchar_fd(' ', 1);
	}
	if (flag == 0)
		ft_putchar_fd('\n', 1);
	g_gen.exit_status = 0;
}

void	ft_echo(char **str)
{
	int	index;

	index = 0;
	if ((ft_strlen2(str) == 1) || (ft_strlen2(str) != 1 \
	&& !ft_strcmp(str[index + 1], "\0") && !str[index + 2]))
	{
		ft_putchar_fd('\n', 1);
		g_gen.exit_status = 0;
		return ;
	}
	suite(str);
	return ;
}

int	set_flag(char *s)
{
	int	index;
	int	size;

	if (!s)
		return (0);
	index = 0;
	size = ft_strlen(s);
	if (s[index] == '-')
	{
		index++;
		while (s[index] == 'n')
			index++;
	}
	if (index == size && (index != 1 && index != 0))
	{
		return (1);
	}
	return (0);
}
