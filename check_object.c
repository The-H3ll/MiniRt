/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:36:12 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/21 15:51:01 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere		*wich_sphere(t_strct strct, t_strct *head)
{
	float t0;

	strct.sphere = head->sphere;
	while (strct.sphere != NULL)
	{
		t0 = sphere_intersect(strct.ray, strct.sphere, &t0);
		if (t0 > 0)
			return (strct.sphere);
		strct.sphere = strct.sphere->next;
	}
	if (strct.sphere == NULL)
		strct.sphere = head->sphere;
	return (strct.sphere);
}

t_plane			*wich_plane(t_strct strct, t_strct *head)
{
	float t0;

	strct.plane = head->plane;
	while (strct.plane->next != NULL)
	{
		t0 = plane_intersect(&strct, strct.ray);
		if (t0 > 0)
			return (strct.plane);
		strct.plane = strct.plane->next;
	}
	return (strct.plane);
}

t_cylindre		*wich_cylindre(t_strct strct, t_strct *head)
{
	float t0;

	strct.cylindre = head->cylindre;
	while (strct.cylindre->next != NULL)
	{
		t0 = cy_hit(strct, strct.ray);
		if (t0 > 0)
			return (strct.cylindre);
		strct.cylindre = strct.cylindre->next;
	}
	return (strct.cylindre);
}

void			apply(t_strct strct, t_strct *head, int i, int j)
{
	while (strct.light != NULL)
	{
		(*strct.shadow) = 0;
		while (strct.sphere != NULL)
		{
			object_draw(strct, strct.t0, i, j);
			if (*(strct.shadow) == 1)
				return ;
			strct.sphere = strct.sphere->next;
		}
		strct.sphere = head->sphere;
		while (strct.cylindre != NULL)
		{
			object_draw(strct, strct.t0, i, j);
			if (*(strct.shadow) == 1)
				return ;
			strct.cylindre = strct.cylindre->next;
		}
		strct.cylindre = head->cylindre;
		strct.light = strct.light->next;
	}
	strct.light = head->light;
}

void			apply_light(t_strct strct, t_strct *head, int i, int j)
{
	strct.sphere_nmbr = 1;
	while (strct.light != NULL)
	{
		object_draw(strct, strct.t0, i, j);
		if (*(strct.shadow) == 1)
		{
			*(strct.shadow) = 0;
			break ;
		}
		strct.sphere_nmbr = 0;
		strct.light = strct.light->next;
	}
	strct.light = head->light;
}
