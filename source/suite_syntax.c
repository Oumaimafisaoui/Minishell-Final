/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:28:14 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 04:28:15 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_spaces2(t_token *c)
{
	t_token	*tmp;

	tmp = NULL;
	tmp = c;
	while (tmp && tmp->type == SPAACE)
		tmp = tmp->next;
	if ((tmp == NULL || is_other(tmp)))
	{
		error_free(tmp->data, tmp);
		return (0);
	}
	return (1);
}

int	is_other(t_token *c)
{
	if (c->type == LESS || c->type == DLESS \
	|| c->type == DGREAT || c->type == DQUOTE || c->type == QUOTE)
		return (1);
	return (0);
}

int	syntax_err(t_token *token)
{
	if (check_quotes(token) == 1 && check_newline(token) == 1 \
	&& check_inside(token) == 1)
		return (1);
	return (0);
}

int	is_other2(t_token *c)
{
	if (c->type == LESS || c->type == DLESS \
	|| c->type == DGREAT || c->type == GREAT || c->type == PIPE)
		return (1);
	return (0);
}

void	free_split(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}
