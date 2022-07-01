/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:08 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 18:06:48 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_quote(char **str, char c)
{
	int	i;

	i = 1;
	while ((*str)[i] != '\0' && (*str)[i] != c)
		i++;
	*str = *str + i + 1;
	return (i + 1);
}

int	get_word(char **str, int *here, int *here2)
{
	int	i;

	i = 0;
	if (*here)
	{
		while (((*str)[i] != '\0' && (*str)[i] != ' ' \
			&& (*str)[i] != '\t' && (*str)[i] != '\v' && (*str)[i] != '\f' \
			&& (*str)[i] != '<' && (*str)[i] != '>' && (*str)[i] != '|'
		))
			i++;
		*here = 0;
		*here2 = 1;
	}
	else
	{
		while ((*str)[i] != '\0' && ((*str)[i] != ' ' \
		&& (*str)[i] != '\t' && (*str)[i] != '\v' && (*str)[i] != '\f' \
		&& (*str)[i] != '<' && (*str)[i] != '>' && (*str)[i] != '\"'
		&& (*str)[i] != '\'' && (*str)[i] != '|' && (*str)[i] != '$'
		))
			i++;
	}
	*str = *str + i;
	return (i);
}

char	*get_char(char **str, char *c, int increment)
{
	*str = *str + increment;
	return (ft_strdup(c));
}

void	get_sympol_great(t_token **tokens, char **str)
{
	if (**str == '>' && *(*str + 1) != '\0' && *(*str + 1) == '>')
	{
		add_token_last(tokens, DGREAT, ft_strdup(">>"));
		*str = *str + 2;
	}
	else
	{
		add_token_last(tokens, GREAT, ft_strdup(">"));
		*str = *str + 1;
	}
}
