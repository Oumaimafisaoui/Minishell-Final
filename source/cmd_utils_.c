/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:23 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 14:34:35 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_not_found(char *cmd)
{
	char	*built_in;

	built_in = str_to_lower(cmd);
	if ((ft_strcmp(built_in, "echo") && ft_strcmp(built_in, "cd") \
		&& ft_strcmp(built_in, "env") && ft_strcmp(built_in, "exit") \
		&& ft_strcmp(built_in, "export") && ft_strcmp(built_in, "pwd") \
		&& ft_strcmp(built_in, "unset")))
		printf("minishell: %s: command not found\n", cmd);
	free(built_in);
}

int	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void	is_a_dir(char *dir)
{
	printf("minishell: %s is a directory\n", dir);
}

char	*return_path(char **cmd_path, char **paths)
{
	free_arr(paths);
	return (*cmd_path);
}
