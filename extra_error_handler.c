/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:30:53 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 22:23:32 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	help_eroor(char *str)
{
	if (str[0] == 's' && (str[1] != 'p' && str[1] != 'q') && str[2] == ' ')
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
	if (str[0] == 'l' && str[1] != ' ')
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
	if (str[0] == 'p' && (str[1] != 'l' || str[2] != ' '))
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
}

void	just_some_error(char *str)
{
	if (str[0] == 'R' && str[1] != ' ')
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
	if (str[0] == 'A' && str[1] != ' ')
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
	if (str[0] == 'c' && (str[1] != ' ' && str[1] != 'y'))
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
	help_eroor(str);
}
