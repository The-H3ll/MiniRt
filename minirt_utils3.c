/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:01:48 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/20 17:50:32 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		sphere_next_allocation(t_strct *strct)
{
	strct->sphere = (t_sphere *)malloc(sizeof(t_sphere));
	strct->sphere->axe = (t_vector *)malloc(sizeof(t_vector));
	strct->sphere->color = (t_color *)malloc(sizeof(t_color));
	strct->sphere->next = NULL;
}

void		plane_next_allocation(t_strct *strct)
{
	strct->plane = (t_plane *)malloc(sizeof(t_plane));
	strct->plane->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->plane->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->plane->color = (t_color *)malloc(sizeof(t_color));
	strct->plane->next = NULL;
}

void		cylindre_next_allocation(t_strct *strct)
{
	strct->cylindre = (t_cylindre *)malloc(sizeof(t_cylindre));
	strct->cylindre->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->cylindre->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->cylindre->color = (t_color *)malloc(sizeof(t_color));
	strct->cylindre->next = NULL;
}

t_sphere	*sphere_coordinate(t_strct *strct, char *str, int i)
{
	strct->sphere->axe = take_pos(strct->sphere->axe, &i, str);
	while (!(ft_isdigit(str[i])))
		i++;
	strct->sphere->radius = ft_atoi_float(str + i);
	if (str[i - 1] == '-')
		strct->sphere->radius = -strct->sphere->radius;
	if (strct->sphere->radius < 0)
	{
		perror("WTF negatif radius");
		exit(-1);
	}
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	strct->sphere->color = take_color(strct->sphere->color, &i, str);
	return (strct->sphere);
}

void		set_object_to_null(t_strct *strct)
{
	strct->ray = NULL;
	strct->ray->origin = NULL;
}
