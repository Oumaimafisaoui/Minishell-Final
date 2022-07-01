/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:05 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 18:06:40 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_sympol_less(t_token **tokens, char **str, int *here)
{
	if (**str == '<' && *(*str + 1) != '\0' && *(*str + 1) == '<')
	{
		add_token_last(tokens, DLESS, ft_strdup("<<"));
		*here = 1;
		*str = *str + 2;
	}
	else
	{
		add_token_last(tokens, LESS, ft_strdup("<"));
		*str = *str + 1;
	}
}

void	get_token_utils(t_token **tokens, char **str, int *here, int *here2)
{
	t_token	*tmp;

	add_token_last(tokens, WORD, \
	ft_substr(*str, 0, get_word(str, here, here2)));
	if (*here2 == 1)
	{
		tmp = *tokens;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->old_data = ft_strdup(tmp->data);
		*here2 = 0;
	}
}
