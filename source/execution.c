/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:52 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 17:48:24 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execut(t_cmd *cmds, int **pipes, int pipes_num, int i)
{
	dup2(cmds[i].infile, STDIN_FILENO);
	dup2(cmds[i].outfile, STDOUT_FILENO);
	close_pipes(pipes, pipes_num);
	if (cmds[i].infile != STDIN_FILENO)
		close(cmds[i].infile);
	if (cmds[i].outfile != STDOUT_FILENO)
		close(cmds[i].outfile);
	if ((cmds[i].exec == 0) && is_buit_in(cmds[i].cmd_args[0]))
		go_commands(cmds[i].cmd_args);
	else if (cmds[i].exec == 0 && g_gen.exec == 0)
	{
		free_envp();
		g_gen.envp = convert_to_array(&g_gen.env);
		execve(cmds[i].cmd_path, cmds[i].cmd_args, g_gen.envp);
		perror("execve : ");
	}
	exit(cmds[i].exec);
}

void	execution(t_cmd *cmds, int pipes_num)
{
	int		i;
	int		pid;
	int		**pipes;
	char	*built_in;

	i = 0;
	pipes = creat_pipes(pipes_num);
	assign_pipes(pipes, &cmds, pipes_num);
	sig_ign();
	if (cmds[i].exec == 0 && pipes_num == 0 && is_buit_in(cmds[i].cmd_args[0]))
		exec_built_in(cmds, i);
	else
	{
		while (i <= pipes_num)
			pid = run_cmd(cmds, pipes, pipes_num, &i);
		close_pipes(pipes, pipes_num);
		wait_all(pid, i, pipes_num);
	}
	free_pipes(pipes, pipes_num);
	sig_handler();
}
