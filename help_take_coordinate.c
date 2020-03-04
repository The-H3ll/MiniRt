/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_take_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:59:05 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/20 17:48:03 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*take_pos(t_vector *s, int *i, char *str)
{
	s->x = ft_atoi_float(str + *i);
	if (str[*i - 1] == '-')
		s->x = -s->x;
	while (ft_isdigit(str[*i]) || str[*i] == '.' || str[*i] == '-')
		*i += 1;
	while (str[*i] == ',')
		*i += 1;
	s->y = ft_atoi_float(str + *i);
	if (str[*i - 1] == '-')
		s->y = -s->y;
	while (ft_isdigit(str[*i]) || str[*i] == '.' || str[*i] == '-')
		*i += 1;
	if (str[*i] == ',')
		*i += 1;
	s->z = ft_atoi_float(str + *i);
	if (str[*i - 1] == '-')
		s->z = -s->z;
	while (ft_isdigit(str[*i]) || str[*i] == '.' || str[*i] == '-')
		*i += 1;
	return (s);
}

void		error_handler(void)
{
	perror("Please insert a nmbr between [0, 255]");
	exit(-1);
}

t_color		*take_color(t_color *s, int *i, char *str)
{
	s->red = ft_atoi(str + *i);
	if (str[*i - 1] == '-')
		s->red = -s->red;
	while (ft_isdigit(str[*i]))
		*i += 1;
	if (str[*i] == ',')
		*i += 1;
	s->green = ft_atoi(str + *i);
	if (str[*i - 1] == '-')
		s->green = -s->green;
	while (ft_isdigit(str[*i]))
		*i += 1;
	if (str[*i] == ',')
		*i += 1;
	s->blue = ft_atoi(str + *i);
	if (str[*i - 1] == '-')
		s->blue = -s->blue;
	while (ft_isdigit(str[*i]) || str[*i] == ',')
		*i += 1;
	if (s->red < 0 || s->red > 255 || s->green < 0 || s->green > 255 ||
			s->blue < 0 || s->blue > 255)
		error_handler();
	return (s);
}
