/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:26:27 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/24 15:10:42 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

char	*return_line(char **ptr, char **o_tmp, char **line, char *str)
{
	char *tmp;

	if (search(*o_tmp) == TRUE)
	{
		tmp = *ptr;
		*ptr = ft_strdup(*o_tmp + word_len(*o_tmp, 1) + 1);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		*line = ft_strdup(*o_tmp);
		free(*o_tmp);
		free(str);
		return (*line);
	}
	return (NULL);
}

char	*return_rest(char **ptr, char **line, char **o_tmp, char **tmp)
{
	if (*ptr)
	{
		if (search(*ptr) == TRUE)
		{
			*line = ft_strdup(*ptr);
			*tmp = *ptr;
			*ptr = ft_strdup(*ptr + word_len(*ptr, 1) + 1);
			if (*tmp)
			{
				free(*tmp);
				tmp = NULL;
			}
			return (*line);
		}
		else
			*o_tmp = ft_strdup(*ptr);
	}
	return (NULL);
}

void	return_free_last(char **tmp, char **ptr, char **o_tmp, char **line)
{
	*tmp = *ptr;
	if (tmp)
	{
		free(*tmp);
		*tmp = NULL;
		*ptr = NULL;
	}
	if (*o_tmp)
		*line = ft_strdup(*o_tmp);
	else
		*line = ft_strdup("");
}
