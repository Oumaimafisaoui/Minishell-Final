/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:47 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 04:27:48 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	ft_putstr_fd(pwd, 1);
	ft_putchar_fd('\n', 1);
	if (g_gen.pwd != NULL)
		free(g_gen.pwd);
	g_gen.pwd = ft_strdup(pwd);
	g_gen.exit_status = 0;
}
