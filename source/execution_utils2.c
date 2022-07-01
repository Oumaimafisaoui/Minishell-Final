/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:49 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/02 00:56:17 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_ign(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_dfl(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	sig_handler(void)
{
	signal(SIGQUIT, handler);
	signal(SIGINT, handler);
}

int	run_cmd(t_cmd *cmds, int **pipes, int pipes_num, int *i)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork : ");
		return (-1);
	}
	if (pid == 0)
	{
		sig_dfl();
		execut(cmds, pipes, pipes_num, *i);
	}
	(*i)++;
	return (pid);
}

void	wait_all(int pid, int i, int pipes_num)
{
	int	status;

	if (i == pipes_num + 1)
	{
		waitpid(pid, &status, 0);
	}
	while (waitpid(-1, 0, 0) != -1)
		;
	g_gen.exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 3)
			printf("Quit: 3\n");
		g_gen.exit_status = 128 + WTERMSIG(status);
	}
}
