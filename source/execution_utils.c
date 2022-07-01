/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:46 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:09:08 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_cmd_files(t_cmd *cmds, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		close(cmds[i].infile);
		close(cmds[i].outfile);
		i++;
	}
}

void	free_envp(void)
{
	int	i;

	i = 0;
	if (g_gen.envp != NULL)
	{
		while (g_gen.envp[i] != NULL)
		{
			free(g_gen.envp[i]);
			i++;
		}
		free(g_gen.envp);
	}
}

char	*str_to_lower(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (str != NULL)
	{
		new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
		while (str[i] != '\0')
		{
			new_str[i] = ft_tolower(str[i]);
			i++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}

void	free_cmds(t_cmd *cmds, int pipes_num)
{
	int	i;
	int	j;

	i = 0;
	if (cmds != NULL)
	{
		while (i <= pipes_num)
		{
			j = 0;
			if (cmds[i].cmd_args != NULL)
			{
				while (cmds[i].cmd_args[j] != NULL)
				{
					free(cmds[i].cmd_args[j]);
					j++;
				}
				free(cmds[i].cmd_args);
			}
			if (cmds[i].cmd_path != NULL)
				free(cmds[i].cmd_path);
			i++;
		}
		free(cmds);
	}
}
