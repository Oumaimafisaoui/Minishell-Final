/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:31:20 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 02:31:22 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	write_to_fd(int fd, char *str)
{
	int	status;

	status = write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}

int	expand_y_n(char **str)
{
	char	c;

	c = (*str)[0];
	if ((*str)[0] != '\0' && ((*str)[0] == '\'' || (*str)[0] == '\"'))
	{
		*str = rm_quotes(*str, c);
		return (0);
	}
	return (1);
}
