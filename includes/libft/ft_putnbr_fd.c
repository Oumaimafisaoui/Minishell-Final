/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:15:14 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/19 07:50:41 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	res;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = (n * (-1));
	}
	else
	{
		res = n;
	}
	if (res >= 10)
	{
		ft_putnbr_fd(res / 10, fd);
	}
	ft_putchar_fd(res % 10 + '0', fd);
}
