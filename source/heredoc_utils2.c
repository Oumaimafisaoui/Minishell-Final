/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:31:43 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:09:28 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expander_heredoc(char *line)
{
	char	*str;
	int		i;
	char	*final_quote;
	char	*tmp;

	str = line;
	i = 0;
	final_quote = ft_strdup("");
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, 0, i);
			final_quote = join(final_quote, tmp);
			str = str + i;
			final_quote = get_var(&str, final_quote, g_gen.env);
			i = -1;
		}
		i++;
	}
	tmp = ft_substr(str, 0, i);
	final_quote = join(final_quote, tmp);
	free(line);
	return (final_quote);
}

void	wait_heredoc(int *exit_status, int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	signal(SIGINT, handler);
	*exit_status = WEXITSTATUS(status);
	g_gen.skip_all = *exit_status;
	g_gen.exit_status = g_gen.skip_all;
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			*exit_status = 1;
	}
}

void	handler1(int sig)
{
	if (sig == SIGINT)
		exit(1);
}
