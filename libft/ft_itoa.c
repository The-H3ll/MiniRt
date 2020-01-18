/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <molabhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:59:48 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/24 14:49:30 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sign(int c)
{
	int i;

	i = 0;
	if (c < 0)
		i = 1;
	return (i);
}

static int		how_mutch(unsigned int c)
{
	int i;
	int j;

	i = 0;
	j = c;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (c == 0)
		i++;
	return (i);
}

static char		*conversion(char x, unsigned int c, long n)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = how_mutch(c);
	if (n < 0)
		j = how_mutch(c) + 1;
	if (!(str = (char *)ft_calloc(j + 1, sizeof(char))))
		return (NULL);
	while (c > 0)
	{
		x = (c % 10) + '0';
		str[j - 1] = x;
		c = c / 10;
		j--;
	}
	if (n < 0)
	{
		str[0] = '-';
		str[how_mutch(n) + 1] = '\0';
	}
	else
		str[how_mutch(n)] = '\0';
	return (str);
}

char			*ft_itoa(long n)
{
	char			*str;
	unsigned int	i;
	char			x;

	if (n == 0)
		return (ft_strdup("0"));
	i = n;
	if (sign(i) == 1)
		i = i * (-1);
	x = 0;
	str = conversion(x, i, n);
	return (str);
}
