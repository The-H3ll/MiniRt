/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_inter2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:13:33 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 16:21:56 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		last_in_first_out(t_strct strct, float *t0, t_ray *ray, int j)
{
	float	lower;
	float	lower_p;
	float	lower_cy;
	int		i;

	i = 0;
	lower = sphere_intersect(ray, strct.sphere, t0);
	if (lower > 0 && strct.sphere_nmbr > 0)
		i = 1;
	lower_p = plane_intersect(&strct, ray);
	if (lower_p > 0 && lower_p < *t0 && j == 0 && strct.plan_nmbr > 0)
	{
		*t0 = lower_p;
		i = 2;
	}
	lower_cy = cy_hit(strct, ray);
	if (lower_cy > 0 && lower_cy < *t0 && strct.cylindre_nmbr > 0)
	{
		*t0 = lower_cy;
		i = 3;
	}
	return (i);
}

void		object_draw(t_strct strct, float t, int i, int j)
{
	if (strct.wich_object == 1)
		sphere_hit_point(t, strct, i, j);
	else if (strct.wich_object == 2)
		plan_hit_point(t, strct, i, j);
	else if (strct.wich_object == 3)
		cy_colo(strct, i, j, t);
}

float		object_shadow(t_strct strct, t_vector normal, t_vector p_hit)
{
	float t0;
	t_ray ray;

	t0 = 2147483647;
	ray.dir = (t_vector *)malloc(sizeof(t_vector));
	ray.origin = (t_vector *)malloc(sizeof(t_vector));
	ray.dir->x = normal.x;
	ray.dir->y = normal.y;
	ray.dir->z = normal.z;
	ray.origin->x = p_hit.x;
	ray.origin->y = p_hit.y;
	ray.origin->z = p_hit.z;
	t0 = last_in_first_out(strct, &t0, &ray, 1);
	free(ray.dir);
	free(ray.origin);
	return (t0);
}

t_vector	specular_light(t_vector normal_s, t_vector normal)
{
	t_vector	normal_k;

	ft_memset(&normal_k, 0, sizeof(t_vector));
	normal_k.x = (2 * (dot_vec(&normal_s, &normal))) * (normal_s.x - normal.x);
	normal_k.y = (2 * (dot_vec(&normal_s, &normal))) * (normal_s.y - normal.y);
	normal_k.z = (2 * (dot_vec(&normal_s, &normal))) * (normal_s.z - normal.z);
	normal_k = *normalize(&normal_k);
	return (normal_k);
}

int			inter_or_not(t_strct strct, t_vector normal, float width)
{
	t_vector	b;
	t_vector	d;
	float		height;
	float		proj1;
	float		proj2;

	b.x = strct.square->pos->x + strct.square->rad;
	b.y = strct.square->pos->y;
	b.z = strct.square->pos->z;
	d.x = strct.square->pos->x;
	d.y = strct.square->pos->y - strct.square->rad;
	d.z = strct.square->pos->z;
	diff_vec(strct.square->pos, &b, &b);
	diff_vec(strct.square->pos, &d, &d);
	width = sqrt(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2));
	height = sqrt(pow(d.x, 2) + pow(d.y, 2) + pow(d.z, 2));
	proj1 = dot_vec(&b, &normal) / width;
	proj2 = dot_vec(&d, &normal) / height;
	if ((proj1 < width && proj1 > 0) && (proj2 < height && proj2 > 0))
		return (1);
	return (0);
}
