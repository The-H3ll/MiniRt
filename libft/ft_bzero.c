/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:03:45 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/24 22:05:35 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned long	*str;
	size_t			j;
	unsigned char	*p;

	j = n;
	str = s;
	p = s;
	i = 0;
	if (n == 0)
		return ;
	n = n / 8;
	while (i < n)
	{
		(str)[i] = 0;
		i++;
	}
	i = n * 8;
	n = j % 8;
	j = 0;
	while (j < n)
	{
		p[i++] = 0;
		j++;
	}
}
