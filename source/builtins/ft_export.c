/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:42 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 22:50:51 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	suite3(char *str)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

int	has_equal(char *str)
{
	if (!ft_strchr(str, '='))
	{
		return (1);
	}
	return (0);
}

void	suite4(char *str)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", 1);
	if (has_equal(str))
		return ;
	while (str[i] && (str[i] == '_' || ft_isalnum(str[i])))
		ft_putchar_fd(str[i++], 1);
	ft_putchar_fd(str[i++], 1);
	ft_putchar_fd('"', 1);
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	ft_putstr_fd("\"\n", 1);
}

void	print_export(t_list *env)
{
	int		index;

	index = 0;
	if (!env)
		return ;
	while (env && env->content)
	{
		if (!ft_strchr(((char *)env->content), '='))
			suite3((char *)env->content);
		else
			suite4((char *)env->content);
		env = env->next;
	}
}

int	ft_export(char **next)
{
	int	index;

	if (ft_strlen2(next) == 1)
	{
		ft_sort(&g_gen);
		return (0);
	}
	index = 1;
	while (next[index])
	{
		if (check_arg(next[index]))
		{
			print_err_exp(next[index]);
		}
		else if (!ft_add_list(&g_gen.env, next[index]))
			ft_lstadd_back(&g_gen.env, ft_lstnew(ft_strdup(next[index])));
		index++;
	}
	return (0);
}
