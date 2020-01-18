/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:46:23 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/21 14:53:44 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * (-1);
	}
	if (i >= 0 && i <= 9)
		ft_putchar_fd(i + '0', fd);
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		i = i % 10;
		ft_putchar_fd(i + '0', fd);
	}
}
