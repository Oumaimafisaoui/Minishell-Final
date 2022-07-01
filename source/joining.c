/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joining.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:18 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 02:30:22 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*join_mix(t_token *token1, t_token *token2)
{
	char	*tmp;

	if (token1->data[0] == '\"' || token1->data[0] == '\'')
	{
		token1->data = rm_quotes(token1->data, token1->data[0]);
	}
	if (token2->data[0] == '\"' || token2->data[0] == '\'')
	{
		token2->data = rm_quotes(token2->data, token2->data[0]);
	}
	tmp = ft_strjoin(token1->data, token2->data);
	free(token1->data);
	return (tmp);
}

void	join_word(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp != NULL)
	{
		if (tmp->type == WORD || tmp->type == DQUOTE || tmp->type == QUOTE)
		{
			while (tmp->next != NULL && \
			(tmp->next->type == WORD || tmp->next->type == DQUOTE \
			|| tmp->next->type == QUOTE))
			{
				tmp->data = join_mix(tmp, tmp->next);
				tmp->type = WORD;
				rm_token(&(tmp->next));
			}
		}
		tmp = tmp->next;
	}
}

char	*join(char *final_quote, char *tmp)
{
	char	*to_free;

	to_free = final_quote;
	final_quote = ft_strjoin(final_quote, tmp);
	free(tmp);
	free(to_free);
	return (final_quote);
}
