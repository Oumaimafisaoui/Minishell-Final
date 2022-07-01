/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:59 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 02:27:41 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_data(t_token **tokens, char *data)
{
	(*tokens)->old_data = ft_strjoin("$", (*tokens)->next->data);
	free((*tokens)->data);
	(*tokens)->data = data;
	(*tokens)->type = WORD;
}

void	play_with_tokens(t_token **tokens, char *str, t_list *env)
{
	char	*env_var;

	env_var = get_env_var(str, env);
	if ((*tokens)->next->type == WORD)
	{
		if (env_var != NULL)
			change_data(tokens, env_var);
	}
	else if ((*tokens)->next->type == DOLLAR)
	{
		free((*tokens)->data);
		(*tokens)->data = ft_strdup("$$");
		(*tokens)->type = WORD;
	}
	else if ((*tokens)->next->type == DQUOTE)
	{
		free((*tokens)->data);
		(*tokens)->data = ft_strdup((*tokens)->next->data);
		(*tokens)->type = DQUOTE;
	}
	free(str);
	rm_token(&((*tokens)->next));
}

char	*get_var_utils(char **str, int *i, t_list *env)
{
	char	*env_var;
	char	*to_free;

	while ((*str)[*i] != '\0' && (*str)[*i] != ' ' \
	&& (*str)[*i] != '\t' \
	&& (*str)[*i] != '\v' && (*str)[*i] != '\f' && \
	(ft_isalnum((*str)[*i]) || (*str)[*i] == '?' || (*str)[*i] == '_'))
	{
		if (*i == 1 && (ft_isdigit((*str)[*i]) || (*str)[*i] == '?'))
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	to_free = ft_substr(*str, 1, *i - 1);
	env_var = find_value(to_free, env);
	free(to_free);
	return (env_var);
}

char	*get_var(char **str, char *final_quote, t_list *env)
{
	int		i;
	char	*env_var;

	i = 1;
	if ((*str)[0] == '$' && (*str)[1] != '\0'
	&& ((ft_isalnum((*str)[1]) || (*str)[1] == '?' || (*str)[1] == '_')))
	{
		env_var = get_var_utils(str, &i, env);
	}
	else
	{
		i = get_dollars(*str);
		env_var = ft_substr(*str, 0, i);
	}
	*str = *str + i;
	return (join(final_quote, env_var));
}
