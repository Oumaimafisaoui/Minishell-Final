/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:19 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 15:23:13 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cmd_path(char *path, char *cmd)
{
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	if (ft_strcmp(cmd, "") == 0)
		return (NULL);
	paths = ft_split(path, ':');
	if (paths == NULL)
		return (NULL);
	while (paths[i] != NULL)
	{
		cmd_path = join_cmd(paths[i], cmd);
		if (cmd_path == NULL)
			return_path(&cmd_path, paths);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (return_path(&cmd_path, paths));
		free(cmd_path);
		i++;
	}
	free_arr(paths);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

void	get_cmds_paht_err(t_cmd **cmds, int i)
{
	if ((*cmds)[i].cmd_args[0] != NULL)
		cmd_not_found((*cmds)[i].cmd_args[0]);
	if ((*cmds)[i].cmd_args[0] != NULL)
		(*cmds)[i].exec = 127;
	else
		g_gen.exec = 1;
}

int	is_directory_check(t_cmd **cmds, int i)
{
	int	status;

	status = 0;
	if (is_directory((*cmds)[i].cmd_args[0]))
	{
		if ((*cmds)[i].exec == 0)
			is_a_dir((*cmds)[i].cmd_args[0]);
		status = 1;
	}
	return (status);
}

int	get_cmds_path(t_cmd **cmds, int pipes)
{
	int		i;
	int		status;
	char	*path;

	status = 0;
	i = 0;
	path = find_value("PATH", g_gen.env);
	if (path == NULL)
		return (1);
	while (i <= pipes)
	{
		if (is_directory_check(cmds, i))
			(*cmds)[i].exec = 126;
		else if ((*cmds)[i].cmd_args[0] != NULL)
			(*cmds)[i].cmd_path = get_cmd_path(path, (*cmds)[i].cmd_args[0]);
		else
			(*cmds)[i].cmd_path = NULL;
		if (((*cmds)[i].cmd_path == NULL) &&
		!is_buit_in((*cmds)[i].cmd_args[0]) && (*cmds)[i].exec == 0)
			get_cmds_paht_err(cmds, i);
		i++;
	}
	free(path);
	return (status);
}
