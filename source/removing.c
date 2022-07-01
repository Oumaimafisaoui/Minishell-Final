/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:43 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 02:26:28 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*rm_quotes(char *str, char c)
{
	int		i;
	char	*new;

	if (str[0] == c)
	{
		str[ft_strlen(str) - 1] = '\0';
		new = ft_strdup(&str[1]);
		free(str);
	}
	else
		new = str;
	return (new);
}

void	rm_quotes_tokens(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp != NULL)
	{
		if (tmp->type == QUOTE || tmp->type == DQUOTE)
		{
			tmp->data = rm_quotes(tmp->data, tmp->data[0]);
			tmp->type = WORD;
		}
		tmp = tmp->next;
	}
}

void	rm_token(t_token **tokens)
{
	t_token	*token;

	token = *tokens;
	if (token->prev == NULL && token->next == NULL)
		*tokens = NULL;
	else if (token->prev == NULL)
	{
		*tokens = token->next;
		(*tokens)->prev = NULL;
	}
	else if (token->next == NULL)
		(*tokens)->prev->next = NULL;
	else
	{
		(*tokens)->next->prev = token->prev;
		(*tokens)->prev->next = token->next;
	}
	if (token->old_data != NULL)
		free(token->old_data);
	free(token->data);
	free(token);
}

void	rm_spaces(t_token **tokens)
{
	t_token	*tmp;
	int		i;

	i = 0;
	while ((*tokens) != NULL && (*tokens)->type == SPAACE)
	{
		rm_token(tokens);
		i++;
	}
	tmp = *tokens;
	while (tmp != NULL)
	{
		if (tmp->type == SPAACE)
		{
			rm_token(&tmp);
			i++;
		}
		tmp = tmp->next;
	}
}
