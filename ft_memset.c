/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:24:04 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/21 14:50:15 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i != len)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}
