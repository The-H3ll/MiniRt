/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:50:57 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/23 01:53:03 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		j;
	char	m;

	m = (unsigned char)c;
	i = 0;
	j = 0;
	while (n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		if (((const char *)src)[i] == m)
		{
			while (((char *)dst)[j] != '\0')
			{
				if (((char *)dst)[j] == m)
					return ((void *)dst + j + 1);
				j++;
			}
		}
		i++;
		n--;
	}
	return (NULL);
}
