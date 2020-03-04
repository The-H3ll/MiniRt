/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:56:57 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/25 15:11:02 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	neg_value(t_vector *vec)
{
	t_vector neg_vec;

	neg_vec.x = -vec->x;
	neg_vec.y = -vec->y;
	neg_vec.z = -vec->z;
	return (neg_vec);
}

void		object_allocation(t_strct *strct)
{
	strct->ray = (t_ray *)malloc(sizeof(t_ray));
	strct->ray->origin = (t_vector *)malloc(sizeof(t_vector));
	strct->ray->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->vec_dir = (t_vector *)malloc(sizeof(t_vector));
	strct->sphere = (t_sphere *)malloc(sizeof(t_sphere));
	strct->sphere->axe = (t_vector *)malloc(sizeof(t_vector));
	strct->display = (t_display *)malloc(sizeof(t_display));
	strct->sphere->color = (t_color *)malloc(sizeof(t_color));
	strct->ambiant = (t_ambiant *)malloc(sizeof(t_ambiant));
	strct->ambiant->color = (t_color *)malloc(sizeof(t_color));
	strct->color = (t_color *)malloc(sizeof(t_color));
	strct->light = (t_light *)malloc(sizeof(t_light));
	strct->light->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->light->color = (t_color *)malloc(sizeof(t_color));
	strct->plane = (t_plane *)malloc(sizeof(t_plane));
	strct->plane->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->plane->color = (t_color *)malloc(sizeof(t_color));
	strct->plane->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->object_color = (t_color *)malloc(sizeof(t_color));
	strct->sphere->next = NULL;
	strct->plane->next = NULL;
	strct->light->next = NULL;
}

void		object_allocation_two(t_strct *strct)
{
	strct->create = (t_create *)malloc(sizeof(t_create));
	strct->triangle = (t_triangle *)malloc(sizeof(t_triangle));
	strct->triangle->vert1 = (t_vector *)malloc(sizeof(t_vector));
	strct->triangle->vert2 = (t_vector *)malloc(sizeof(t_vector));
	strct->triangle->vert3 = (t_vector *)malloc(sizeof(t_vector));
	strct->triangle->color = (t_color *)malloc(sizeof(t_color));
	strct->square = (t_square *)malloc(sizeof(t_square));
	strct->square->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->square->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->square->color = (t_color *)malloc(sizeof(t_color));
	strct->cylindre = (t_cylindre *)malloc(sizeof(t_cylindre));
	strct->cylindre->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->cylindre->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->cylindre->color = (t_color *)malloc(sizeof(t_color));
	strct->cylindre->next = NULL;
}

void		free_object(t_strct *strct)
{
	free(strct->ray);
	free(strct->ray->origin);
	free(strct->ray->dir);
	free(strct->sphere);
	free(strct->sphere->axe);
	free(strct->sphere->color);
	free(strct->display);
	free(strct->ambiant);
	free(strct->ambiant->color);
	free(strct->color);
	free(strct->light);
	free(strct->light->pos);
	free(strct->light->color);
	free(strct->plane);
	free(strct->plane->dir);
	free(strct->plane->color);
	free(strct->plane->pos);
	free(strct->vec_dir);
}

void		free_object_two(t_strct *strct)
{
	free(strct->triangle);
	free(strct->create);
	free(strct->triangle->vert1);
	free(strct->triangle->vert2);
	free(strct->triangle->vert3);
	free(strct->triangle->color);
	free(strct->square);
	free(strct->square->pos);
	free(strct->square->dir);
	free(strct->square->color);
	free(strct->cylindre);
	free(strct->cylindre->pos);
	free(strct->cylindre->dir);
	free(strct->cylindre->color);
	free(strct->object_color);
}
