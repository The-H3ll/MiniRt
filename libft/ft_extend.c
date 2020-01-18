/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:55:10 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/26 23:11:07 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extend(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!(s = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) +
						(s2 ? ft_strlen(s2) : 0) + 1))))
		return (NULL);
	i = 0;
	while (s2 && s2[i])
	{
		s[i] = s2[i];
		i++;
	}
	j = 0;
	while (s1[j])
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	free(s1);
	free(s2);
	return (s1);
}
