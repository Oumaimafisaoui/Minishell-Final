/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:23:50 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 18:52:44 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	open_file_err(t_token **tokens, int fd, int status)
{
	if ((*tokens)->next->old_data == NULL && (fd == -1 && status != 1))
		perror("minishell");
	else
	{
		if ((ft_strcmp((*tokens)->next->data, "") == 0) \
		&& (*tokens)->next->old_data != NULL)
			printf("minishell: %s: ambiguous redirect\n", \
			(*tokens)->next->old_data);
		else if ((*tokens)->next->old_data != NULL && status != 1)
			perror("minishelll");
	}
}

void	open_rest(t_token *token)
{
	int	ingnor;

	while (token)
	{
		if (token->type == DLESS)
		{
			if (token->next->old_data)
				heredoc(ft_strdup(token->next->old_data), &ingnor);
			else
				heredoc(ft_strdup(token->next->data), &ingnor);
		}
		token = token->next;
	}
}

int	open_file(t_token **tokens, int type)
{
	int	fd;
	int	status;

	status = 0;
	if (type == GREAT)
		fd = open((*tokens)->next->data, O_RDWR | O_CREAT | O_TRUNC, 0777);
	else if (type == LESS)
		fd = open((*tokens)->next->data, O_RDWR, 0777);
	else if (type == DGREAT)
		fd = open((*tokens)->next->data, O_RDWR | O_CREAT | O_APPEND, 0777);
	else if (type == DLESS)
	{
		if ((*tokens)->next->old_data)
			fd = heredoc(ft_strdup((*tokens)->next->old_data), &status);
		else
			fd = heredoc(ft_strdup((*tokens)->next->data), &status);
		if (status)
			fd = status * (-1);
	}
	if (fd < 0)
	{
		open_rest((*tokens)->next);
		open_file_err(tokens, fd, status);
	}
	return (fd);
}

int	creat_in_files(t_cmd **cmds, t_token *tokens, int i)
{
	int	fd;

	fd = open_file(&tokens, tokens->type);
	if ((*cmds)[i].infile > -1)
	{
		if (close((*cmds)[i].infile) == -1)
			perror("close : ");
	}
	if (fd <= -1)
		(*cmds)[i].exec = fd * (-1);
	(*cmds)[i].infile = fd;
	return (fd);
}

int	creat_out_files(t_cmd **cmds, t_token *tokens, int i)
{
	int	fd;

	fd = open_file(&tokens, tokens->type);
	if ((*cmds)[i].outfile != -1)
	{
		if (close((*cmds)[i].outfile) == -1)
		{
			perror("close : ");
			exit(3);
		}
	}
	if (fd <= -1)
		(*cmds)[i].exec = fd * (-1);
	(*cmds)[i].outfile = fd;
	return (fd);
}
