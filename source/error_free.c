/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:18:42 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 22:00:14 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_free(char *str, t_token *tokens)
{
	ft_putstr_fd("Minishell: syntax error near unexpected token ", 2);
	ft_putstr_fd("\'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\'", 2);
	ft_putstr_fd("\n", 2);
}
