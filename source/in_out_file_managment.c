/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_file_managment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:14 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:09:33 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	rm_redi_utils(t_token **token1, t_token **token2)
{
	rm_token(token1);
	rm_token(token2);
}

static int	check_con_redi(t_cmd **cmds, int i)
{
	if (((*cmds)[i].tokens_cmd) != NULL
		&& ((((*cmds)[i].tokens_cmd))->type == LESS
		|| ((*cmds)[i].tokens_cmd)->type == GREAT
		|| (((*cmds)[i].tokens_cmd))->type == DLESS
		|| ((*cmds)[i].tokens_cmd)->type == DGREAT))
		return (1);
	return (0);
}

void	rm_redirecitons(t_cmd **cmds, int pipes)
{
	int		i;
	t_token	*tmp;

	i = 0;
	while (i <= pipes)
	{
		while (check_con_redi(cmds, i))
			rm_redi_utils(&((*cmds)[i].tokens_cmd), &((*cmds)[i].tokens_cmd));
		tmp = ((*cmds)[i].tokens_cmd);
		while (tmp != NULL)
		{
			if ((tmp->next != NULL) && (tmp->next->type == LESS \
			|| tmp->next->type == GREAT \
			|| tmp->next->type == DLESS || tmp->next->type == DGREAT))
			{
				rm_redi_utils(&(tmp->next), &(tmp->next));
				continue ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void	check_file_direcitons(t_cmd **cmds, int pipes)
{
	int		i;
	t_token	*tokens;
	int		fd;

	i = 0;
	while (i <= pipes)
	{
		tokens = (*cmds)[i].tokens_cmd;
		while (tokens != NULL)
		{
			if (tokens->type == LESS || tokens->type == DLESS)
				fd = creat_in_files(cmds, tokens, i);
			else if (tokens->type == GREAT || tokens->type == DGREAT)
				fd = creat_out_files(cmds, tokens, i);
			if (fd == -1)
				return ;
			tokens = tokens->next;
		}
		i++;
	}
}
