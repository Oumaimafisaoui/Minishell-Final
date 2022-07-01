/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:31 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:08:40 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_strcat(char *s1, const char *s2)
{
	while (*s1)
		s1++;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char	*ft_strjoin_1(char const *s1, char const *s2)
{
	int		total_len;
	char	*allocat;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	allocat = (char *)malloc(total_len);
	if (!allocat)
		return (0);
	*allocat = '\0';
	ft_strcat(allocat, s1);
	ft_strcat(allocat, s2);
	return (allocat);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

char	*join_cmd(char *path, char *cmd)
{
	char	*cmd_path;
	char	*to_free;

	to_free = ft_strjoin_1("/", cmd);
	if (to_free == NULL)
		return (NULL);
	cmd_path = ft_strjoin_1(path, to_free);
	if (cmd_path == NULL)
		return (NULL);
	free(to_free);
	return (cmd_path);
}
