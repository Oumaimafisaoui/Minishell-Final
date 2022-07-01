/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:52:02 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/07/01 05:09:18 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_value(char *str, t_list *env_l)
{
	char	*tmp;

	if (strcmp(str, "?") == 0)
		return (ft_itoa(g_gen.exit_status));
	while (env_l != NULL)
	{
		tmp = ft_strjoin(str, "=");
		if (ft_strncmp(tmp, env_l->content, ft_strlen(tmp)) == 0)
		{
			free(tmp);
			return (ft_strdup(&(env_l->content[ft_strlen(str) + 1])));
		}
		free(tmp);
		env_l = env_l->next;
	}
	return (ft_strdup(""));
}

char	*get_var_str(char *str, int *i)
{
	*i = 0;
	while (ft_isalnum(str[*i]) || str[*i] == '_' || str[*i] == '?')
	{
		if ((*i == 0) && (ft_isdigit(str[*i]) || str[*i] == '?'))
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	return (ft_substr(str, 0, *i));
}

char	*get_env_var(char *str, t_list *env)
{
	char	*second_part;
	char	*new_str;
	char	*env_var;
	int		i;

	new_str = get_var_str(str, &i);
	second_part = ft_substr(str, i, ft_strlen(str + i));
	env_var = find_value(new_str, env);
	free(new_str);
	new_str = env_var;
	env_var = ft_strjoin(env_var, second_part);
	free(new_str);
	free(second_part);
	return (env_var);
}

int	get_dollars(char *str)
{
	int	j;
	int	count;

	j = 0;
	while (str[j] != '\0' && str[j] == '$')
			j++;
	if ((j % 2 != 0) && str[j] != '\0' && j != 1)
		return (j - 1);
	else
		return (j);
}
