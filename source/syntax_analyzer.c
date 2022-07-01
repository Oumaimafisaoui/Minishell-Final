/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:28:07 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 21:58:46 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_pairs1(char *s)
{
	int	q;

	q = 0;
	while (*s)
	{
		if (q == 0 && (*s == '\"' || *s == '\''))
		{
			if (*(s++) == '\'')
				q = 2;
			else
				q = 3;
		}
		while (*s && ((q == 3 && *s != '\"') || (q == 2 && *s != '\'')))
			s++;
		if ((q == 3 && *s == '\"') || (q == 2 && *s == '\''))
			q = 0;
		s++;
	}
	return (!q);
}

int	check_quotes(t_token *token)
{
	t_token	*tmp;
	char	*s;

	tmp = token;
	while (tmp)
	{
		s = tmp->data;
		if (!check_pairs1(s))
		{
			error_free(tmp->data, tmp);
			g_gen.exit_status = 258;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_inside(t_token *tmp)
{
	t_token	*p1;
	t_token	*p2;

	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			p1 = tmp->next;
			p2 = tmp->prev;
			while (p1 && p1->type == SPAACE)
				p1 = p1->next;
			while (p2 && p2->type == SPAACE)
				p2 = p2->prev;
			if (!p2 || (p2 && p2->type != WORD)
				|| !p1 || (p1 && p1->type != WORD))
			{
				error_free(tmp->data, tmp);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_newline(t_token *c)
{
	t_token	*tmp;

	tmp = NULL;
	tmp = c;
	while (tmp)
	{
		if ((tmp->type == LESS) || (tmp->type == GREAT) \
		|| (tmp->type == DGREAT) || (tmp->type == DLESS))
		{
			tmp = tmp->next;
			while (tmp && tmp->type == SPAACE)
				tmp = tmp->next;
			if ((tmp && is_other2(tmp)) || (tmp == NULL))
			{
				ft_putstr_fd("syntax error near unexpected", 2);
				ft_putstr_fd("  token : 'newline'\n", 2);
				g_gen.exit_status = 258;
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	handle_spaces(t_token *c)
{
	t_token	*tmp;

	tmp = NULL;
	tmp = c;
	while (tmp && tmp->type == SPAACE)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		ft_putstr_fd("syntax error near unexpected", 2);
		ft_putstr_fd("  token : 'newline'\n", 2);
		g_gen.exit_status = 258;
		return (0);
	}
	else if (is_other(tmp))
	{
		error_free(tmp->data, tmp);
		g_gen.exit_status = 258;
		return (0);
	}
	return (1);
}
