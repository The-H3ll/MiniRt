/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:10:28 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/10 21:32:09 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <mlx.h>
#include "minirt.h"

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}


static int		go_next(char str)
{
	if ((str >= 9 && str <= 13) || str == ' ')
		return (1);
	return (0);
}

static float	take_the_float(char *str, int i, float res, int neg)
{
	int car;
	float after_dot;


	after_dot = 0.0;
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.')
		{
			i++;
			car = str[i] - '0';
			if (car >= 10)
				after_dot = (float)car / (float)100;
			else
				after_dot = (float)car / (float)10;
			res += after_dot;
			if (neg == 1)
				res = -res;
			return (res);
		}
		car = str[i] - '0';
		res = (car % 10 + res * 10);
		res += after_dot;
		if ((!(ft_isdigit(str[i]))) && str[i] != '.')
		{
			if (neg == 1)
				res = -res;
			return (res);
			}
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}

float	ft_atoi_float(char *str)
{
	float res;
	int i;
	int neg;

	 i = 0;
	 neg = 0;
	 res = 0.0;
	 while (go_next(str[i]))
		 i++;
	 if (str[i] == '-')
	 {
		neg = 1;
		i++;
	 }
	 else if (str[i] == '+')
		 i++;
	 res = take_the_float(str, i, res, neg);
	 return (res);
}
