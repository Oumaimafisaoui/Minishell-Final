/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:47 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 18:16:28 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_token_check(t_token **tokens, char **str, int *here, int *here2)
{
	if (**str == '\"' && *here == 0)
		add_token_last(tokens, DQUOTE, \
		ft_substr(*str, 0, get_quote(str, '\"')));
	else if (**str == '\'' && *here == 0)
		add_token_last(tokens, QUOTE, \
		ft_substr(*str, 0, get_quote(str, '\'')));
	else if (**str == ' ' || **str == '\t' \
	|| **str == '\v' || **str == '\f')
		add_token_last(tokens, SPAACE, get_char(str, " ", 1));
	else if (**str == '>')
		get_sympol_great(tokens, str);
	else if (**str == '<')
		get_sympol_less(tokens, str, here);
	else if (**str == '|')
		add_token_last(tokens, PIPE, get_char(str, "|", 1));
	else if (**str == '$' && *here == 0)
		add_token_last(tokens, DOLLAR, get_char(str, "$", 1));
	else
		get_token_utils(tokens, str, here, here2);
}

void	get_token(t_token **tokens, char **str)
{
	int		here;
	int		here2;
	t_token	*tmp;

	here = 0;
	here2 = 0;
	while (**str != '\0')
	{
		get_token_check(tokens, str, &here, &here2);
	}
}

int	count_tokens(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens)
	{
		tokens = tokens->next;
		count++;
	}
	return (count);
}

void	clear_tokens(t_token **tokens)
{
	if (*tokens == NULL)
		return ;
	if ((*tokens)->next == NULL)
		rm_token(tokens);
	else
		rm_token(&((*tokens)->next));
	clear_tokens(tokens);
}

t_token	*tokenize(char *line)
{
	t_token	*tokens;
	t_token	*tmp;

	tokens = NULL;
	get_token(&tokens, &line);
	return (tokens);
}
