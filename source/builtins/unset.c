/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:58 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 04:27:59 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unset(char **next)
{
	int	index;

	if (!g_gen.env)
		return (0);
	if (ft_strlen2(next) == 1)
		return (0);
	index = 1;
	while (next[index])
	{
		if (check_arg2(next[index]))
		{
			print_err_uns(next[index]);
			g_gen.exit_status = 1;
		}
		else
		{
			start_unset(g_gen.env, next[index]);
			g_gen.exit_status = 0;
		}
		index++;
	}
	return (0);
}

int	start_unset(t_list *env, char *next)
{
	size_t	len;
	t_list	*bef;
	t_list	*tmp;

	len = ft_strlen(next);
	tmp = env;
	bef = (t_list *) NULL;
	while (tmp)
	{
		if (!ft_strncmp((char *)tmp->content, next, len))
			break ;
		bef = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (bef)
			bef->next = tmp->next;
		else
			env = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	g_gen.env = env;
	return (0);
}
