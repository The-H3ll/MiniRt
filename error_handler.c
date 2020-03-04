/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:48:46 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 18:37:05 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_save(char *av, int save, int *i)
{
	if (strcmp(av, "--save") == 0)
	{
		*i = 1;
		save = 1;
	}
	else
	{
		perror("Enter '--save'\n");
		exit(0);
	}
	return (save);
}

int		check_rt(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if (av[i + 1] == 'r' && av[i + 2] == 't' && av[i + 3] == 0)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
