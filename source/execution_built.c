/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_built.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:42 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 01:53:14 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_buit_in(char *cmd)
{
	char	*built_in;

	if (cmd == NULL)
		return (0);
	built_in = str_to_lower(cmd);
	if ((ft_strcmp(built_in, "echo") && ft_strcmp(built_in, "cd") \
	&& ft_strcmp(built_in, "env") && ft_strcmp(built_in, "exit") \
	&& ft_strcmp(built_in, "export") && ft_strcmp(built_in, "pwd") \
	&& ft_strcmp(built_in, "unset")))
	{
		free(built_in);
		return (0);
	}
	else
	{
		free(built_in);
		return (1);
	}
}

void	exec_built_in(t_cmd *cmds, int i)
{
	int	in;
	int	out;

	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	dup2(cmds[i].infile, STDIN_FILENO);
	dup2(cmds[i].outfile, STDOUT_FILENO);
	go_commands(cmds[i].cmd_args);
	close(cmds[i].infile);
	close(cmds[i].outfile);
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(in);
	close(out);
}
