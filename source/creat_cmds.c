/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:35 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:01:46 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	creat_cmds_utils2(t_cmd **cmds, \
t_token **new_head, int i, t_token **tmp)
{
	rm_token(&((*tmp)->next));
	(*cmds)[i].tokens_cmd = *new_head;
	(*cmds)[i].infile = -1;
	(*cmds)[i].outfile = -1;
	(*cmds)[i].exec = 0;
	(*cmds)[i].cmd_args = NULL;
	(*cmds)[i].cmd_path = NULL;
	(*new_head) = (*tmp)->next;
	(*new_head)->prev = NULL;
	(*tmp)->next = NULL;
	(*tmp) = (*new_head);
}

static t_cmd	*creat_cmds_utils(t_token **tokens, t_cmd **cmds)
{
	t_token	*tmp;
	t_token	*new_head;
	int		i;

	i = 0;
	tmp = *tokens;
	new_head = tmp;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->next->type == PIPE)
		{
			creat_cmds_utils2(cmds, &new_head, i, &tmp);
			i++;
		}
		else
			tmp = tmp->next;
	}
	new_head->prev = NULL;
	(*cmds)[i].tokens_cmd = new_head;
	(*cmds)[i].infile = -1;
	(*cmds)[i].outfile = -1;
	(*cmds)[i].cmd_args = NULL;
	(*cmds)[i].cmd_path = NULL;
	(*cmds)[i].exec = 0;
	return (*cmds);
}

t_cmd	*creat_cmds(t_token **tokens)
{
	int		pipes;
	t_cmd	*cmds;
	int		i;

	i = 0;
	pipes = count_pipes(*tokens);
	cmds = malloc(sizeof(t_cmd) * (pipes + 1));
	if (cmds == NULL)
		return (NULL);
	if (pipes == 0)
	{
		cmds[i].tokens_cmd = *tokens;
		cmds[i].infile = -1;
		cmds[i].outfile = -1;
		cmds[i].exec = 0;
		cmds[i].cmd_args = NULL;
		cmds[i].cmd_path = NULL;
		return (cmds);
	}
	return (creat_cmds_utils(tokens, &cmds));
}
