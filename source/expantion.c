/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:55 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 04:57:44 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expander(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp != NULL)
	{
		if (tmp->type == DOLLAR)
		{
			if (tmp->next != NULL && tmp->next->type != SPAACE && \
				(tmp->next->type == WORD || tmp->next->type == DQUOTE \
				|| tmp->next->type == DOLLAR))
				play_with_tokens(&tmp, ft_strdup(tmp->next->data), g_gen.env);
			else if ((tmp->next != NULL && tmp->next->type == SPAACE) \
			|| (tmp->next == NULL))
				tmp->type = WORD;
		}
		tmp = tmp->next;
	}
}

void	expander_in_quotes_utils(t_token **token, t_list *env)
{
	char	*str;
	int		i;
	char	*final_quote;
	char	*tmp;

	str = (*token)->data;
	i = 0;
	final_quote = ft_strdup("");
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, 0, i);
			final_quote = join(final_quote, tmp);
			str = str + i;
			final_quote = get_var(&str, final_quote, env);
			i = -1;
		}
		i++;
	}
	tmp = ft_substr(str, 0, i);
	final_quote = join(final_quote, tmp);
	free((*token)->data);
	(*token)->data = final_quote;
}

void	expander_in_quotes(t_token **tokens)
{
	t_token	*token;

	token = *tokens;
	while (token != NULL)
	{
		if (token->type == DQUOTE)
		{
			expander_in_quotes_utils(&token, g_gen.env);
		}
		token = token->next;
	}
}
