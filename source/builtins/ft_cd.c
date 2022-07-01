/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:27:27 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 23:59:39 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	modify_env(char *pwd)
{
	if (!ft_add_list(&g_gen.env, pwd))
		ft_lstadd_back(&g_gen.env, ft_lstnew(pwd));
	return (1);
}

int	ft_cd(char **path)
{
	char	*p;

	if (!ft_strncmp(path[0], "CD", 2))
		return (0);
	if (!path[1] || !ft_strncmp(path[1], "--", 2) || \
	(!ft_strncmp(path[1], "~", 2) && !path[2]))
	{
		if (small(&p))
			return (1);
	}
	else if (!strncmp(path[1], "-", 1))
	{
		if (small2(&p))
			return (1);
	}
	else if (ft_strlen2(path) == 2)
		p = ft_strdup(path[1]);
	change_env(p);
	free(p);
	return (0);
}

int	change_env(char *p)
{
	char	*pwd;
	int		var;

	pwd = join_str("OLDPWD=", g_gen.pwd);
	var = chdir(p);
	if (var != -1)
	{
		if (small3(&pwd))
			return (1);
	}
	else if (var == -1)
		perror("cd");
	if (g_gen.pwd != NULL)
		free(g_gen.pwd);
	g_gen.pwd = getcwd(NULL, 0);
	g_gen.exit_status = 0;
	free(pwd);
	return (0);
}

int	ft_add_list(t_list **env_list, char *str)
{
	t_list	*tmp;
	size_t	index2;

	tmp = *env_list;
	if (!tmp)
		return (0);
	while (tmp)
	{
		index2 = s1(str);
		if (!ft_strncmp(tmp->content, str, index2))
		{
			if (ft_strchr(str, '='))
			{
				free(tmp->content);
				tmp->content = ft_strdup(str);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	free(tmp);
	g_gen.exit_status = 0;
	return (0);
}
