/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_asign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:36 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 02:25:54 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	assign_f(t_cmd **cmds, int i, int pipes_num, int **pipes)
{
	if ((*cmds)[i].infile == -1)
		(*cmds)[i].infile = STDIN_FILENO;
	if ((*cmds)[i].outfile == -1)
	{
		if (pipes_num == 0)
		{
			(*cmds)[i].outfile = STDOUT_FILENO;
			return ;
		}
		else
			(*cmds)[i].outfile = pipes[i][1];
	}
}

void	assign_pipes(int **pipes, t_cmd **cmds, int pipes_num)
{
	int	i;

	i = 0;
	while (i <= pipes_num)
	{
		if (i == 0)
			assign_f(cmds, i, pipes_num, pipes);
		if (i == pipes_num)
		{
			if ((*cmds)[i].infile == -1)
				(*cmds)[i].infile = pipes[i - 1][0];
			if ((*cmds)[i].outfile == -1)
				(*cmds)[i].outfile = STDOUT_FILENO;
		}
		if (i < pipes_num)
		{
			if ((*cmds)[i].infile == -1)
				(*cmds)[i].infile = pipes[i - 1][0];
			if ((*cmds)[i].outfile == -1)
				(*cmds)[i].outfile = pipes[i][1];
		}
		i++;
	}
}
