/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:12 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:03:49 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_cmds(t_token *tokens)
{
	char	**cmds;
	int		i;

	i = 0;
	cmds = (char **)malloc(sizeof(char *) * (count_tokens(tokens) + 1));
	if (cmds == NULL)
		return (NULL);
	while (tokens)
	{
		cmds[i] = ft_strdup(tokens->data);
		tokens = tokens->next;
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

void	creat_cmd_args(t_cmd **cmds, int pipe)
{
	int	i;

	i = 0;
	while (i <= pipe)
	{
		(*cmds)[i].cmd_args = get_cmds((*cmds)[i].tokens_cmd);
		clear_tokens(&((*cmds)[i].tokens_cmd));
		i++;
	}
}

t_cmd	*cmds_and_redirections(t_token **tokens, int *pipes)
{
	t_cmd	*cmds;
	int		status;

	*pipes = count_pipes(*tokens);
	cmds = creat_cmds(tokens);
	check_file_direcitons(&cmds, *pipes);
	rm_redirecitons(&cmds, *pipes);
	creat_cmd_args(&cmds, *pipes);
	return (cmds);
}

void	get_path_and_execute(t_token **toknes)
{
	t_cmd	*cmds;
	int		pipes_num;

	cmds = cmds_and_redirections(toknes, &pipes_num);
	if ((get_cmds_path(&cmds, pipes_num) == 0) && (g_gen.skip_all == 0))
		execution(cmds, pipes_num);
	free_cmds(cmds, pipes_num);
}
