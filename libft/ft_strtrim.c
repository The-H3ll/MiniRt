/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:23:59 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/21 17:00:48 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nobody(char const *s, char const *set, int i, int j)
{
	int k;

	k = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s[j])
			k = 1;
		i++;
	}
	return (k);
}

static	int		check_backward(char const *s, char const *set, int i)
{
	int		check;
	int		j;
	int		m;

	j = 0;
	check = 0;
	while (i >= 0)
	{
		check = 0;
		m = nobody(s, set, 0, i);
		if (m == 0)
			return (j);
		while (set[check] != '\0')
		{
			if (set[check] == s[i])
			{
				j++;
				break ;
			}
			check++;
		}
		i--;
	}
	return (j);
}

static int		check_forward(char const *s, char const *set, int i)
{
	int		check;
	int		j;
	int		k;

	check = 0;
	j = 0;
	while (s[i] != '\0')
	{
		check = 0;
		k = nobody(s, set, 0, i);
		if (k == 0)
			return (j);
		while (set[check] != '\0')
		{
			if (set[check] == s[i])
			{
				j++;
				break ;
			}
			check++;
		}
		i++;
	}
	return (j);
}

char			*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	int		j;
	int		k;
	int		l;
	int		sign;

	sign = 1;
	if (s == NULL)
		return (NULL);
	k = check_forward(s, set, 0);
	j = check_backward(s, set, ft_strlen(s) - 1);
	if (k == 0 && j == 0)
		return (ft_strdup(s));
	if (k == j)
		return (str = ft_substr(s, 0, 0));
	if (k > ((int)ft_strlen(s) - j))
		sign = -1;
	l = (ft_strlen(s) - j) * sign - k;
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	j = 0;
	while (j < l)
		str[j++] = s[k++];
	str[j] = '\0';
	return (str);
}
