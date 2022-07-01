/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:40 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 02:30:34 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_pipes(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens != NULL)
	{
		if (tokens->type == PIPE)
			i++;
		tokens = tokens->next;
	}
	return (i);
}

void	fail_to_generat_pipes(int **pipes, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(pipes[j]);
		j++;
	}
	free(pipes);
	exit (3);
}

void	free_pipes(int **pipes, int pipes_num)
{
	int	i;

	i = 0;
	if (pipes != NULL)
	{
		while (i < pipes_num)
		{
			free(pipes[i]);
			i++;
		}
		free(pipes);
	}
}

void	close_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	**creat_pipes(int pipes_num)
{
	int	**pipes;
	int	i;

	i = 0;
	pipes = malloc(sizeof(int *) * pipes_num);
	if (pipes == NULL)
		return (NULL);
	while (i < pipes_num)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipes[i] == NULL)
		{
			fail_to_generat_pipes(pipes, i);
			creat_pipes(pipes_num);
		}
		pipe(pipes[i]);
		i++;
	}
	return (pipes);
}
