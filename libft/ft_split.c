/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:42:10 by molabhai          #+#    #+#             */
/*   Updated: 2019/10/23 01:41:49 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			part_num(char const *s, char c)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[0] != '\0')
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

static int			word_num(char const *s, char c, int i)
{
	int j;

	j = i;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i - j);
}

static char			**fill(char const *s, char c, int i, char **str)
{
	int	p;
	int l;
	int k;
	int j;

	p = 0;
	l = 0;
	while (p < i)
	{
		while (s[l] == c)
			l++;
		if (s[l] == '\0')
			break ;
		k = word_num(s, c, l);
		if (!(str[p] = (char *)ft_calloc((k + 1), sizeof(char))))
			return (NULL);
		j = 0;
		while (j < k && s[l] != c)
			str[p][j++] = s[l++];
		str[p][j] = '\0';
		p++;
	}
	str[p] = NULL;
	return (str);
}

static char			**free_all(char **s, int pos)
{
	while (pos > 0)
	{
		free(s[pos]);
		pos--;
	}
	free(s);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = part_num(s, c);
	if (!(str = (char **)ft_calloc((i + 4), sizeof(char *))))
		return (NULL);
	if (!(str = fill(s, c, i, str)))
		return (str = free_all(str, i));
	return (str);
}
