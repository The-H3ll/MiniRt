/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:35:07 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/23 03:50:05 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(needle);
	j = ft_strlen(haystack);
	if (i == 0 || (i == 0 & j == 0))
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && len)
	{
		k = i;
		while (haystack[k] == needle[j] && needle[j] != '\0')
		{
			k++;
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + (k - j));
		}
		i++;
		len--;
	}
	return (NULL);
}
