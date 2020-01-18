/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:10:43 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/21 14:52:58 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		i = len + i - 1;
		while (len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
			len--;
		}
		return ((unsigned char *)dst);
	}
	while (len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		len--;
	}
	return ((void *)dst);
}
