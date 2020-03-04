/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:11:42 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 16:43:38 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		plane_intersect(t_strct *strct, t_ray *ray)
{
	t_vector	new_pos;
	float		a;
	float		b;
	float		t;

	ft_memset(&new_pos, 0, sizeof(t_vector));
	diff_vec(strct->plane->pos, ray->origin, &new_pos);
	a = dot_vec(strct->plane->pos, strct->plane->dir);
	b = dot_vec(ray->dir, strct->plane->dir);
	t = a / b;
	if (t >= 0)
		return (t);
	return (-1);
}

float		plane_intersect_sq(t_strct *strct, t_ray *ray)
{
	t_vector	new_pos;
	float		a;
	float		b;
	float		t;

	ft_memset(&new_pos, 0, sizeof(t_vector));
	diff_vec(strct->square->pos, ray->origin, &new_pos);
	a = dot_vec(strct->square->pos, strct->square->dir);
	b = dot_vec(ray->dir, strct->square->dir);
	t = a / b;
	if (t >= 0)
		return (t);
	return (-1);
}

float		sphere_intersect(t_ray *ray, t_sphere *center, float *t0)
{
	t_vector	len_c_o;
	float		a;
	float		b;
	float		d;
	float		c;

	diff_vec(ray->origin, center->axe, &len_c_o);
	a = dot_vec(ray->dir, ray->dir);
	b = 2.0 * dot_vec(&len_c_o, ray->dir);
	c = dot_vec(&len_c_o, &len_c_o) - (center->radius);
	d = b * b - (4 * a * c);
	if (d > 0)
	{
		c = -b - sqrt(d);
		if (c > 0)
			if ((*t0 = c / 2.0 * a) > 0)
				return (*t0);
	}
	return (-1);
}

void		plan_hit_point(float t1, t_strct strct, int i, int j)
{
	t_vector	p_hit;
	t_vector	normal_p;
	t_vector	normal_s;
	float		k;
	int			colore;

	p_hit = hit_point_pl(&t1, &strct);
	diff_vec(strct.light->pos, &p_hit, &normal_p);
	p_hit.x += 0.0001;
	p_hit.y += 0.0001;
	p_hit.z += 0.0001;
	normal_p = *normalize(&normal_p);
	normal_s = *normalize(&p_hit);
	normal_s = specular_light(normal_s, normal_p);
	k = dot_vec(&normal_p, strct.ray->dir);
	k = -k;
	t1 = dot_vec(&normal_s, strct.ray->dir);
	if (t1 < 0)
		t1 = -t1;
	colore = rgb_to_int(plan_color(k, strct, strct.object_color, t1));
	k = object_shadow(strct, normal_p, p_hit);
	if (k == 0 && strct.save == 0 && strct.wich_object == 2)
		mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
	else if (k != 0)
		for_plane(strct, i, j);
}

void		sphere_hit_point(float t0, t_strct strct, int i, int j)
{
	t_vector	s_hit;
	t_vector	normal_s;
	t_vector	normal;
	int			colore;
	float		o;

	s_hit = hit_point_sp(&t0, strct.ray->dir, &strct);
	diff_vec(&s_hit, strct.sphere->axe, &normal_s);
	diff_vec(strct.light->pos, &normal_s, &normal);
	s_hit.x += 0.0001;
	s_hit.y += 0.0001;
	s_hit.z += 0.0001;
	normal = *normalize(&normal);
	normal_s = *normalize(&normal_s);
	normal_s = specular_light(normal_s, normal);
	o = dot_vec(&normal, strct.ray->dir);
	t0 = dot_vec(&normal_s, strct.ray->dir);
	if (t0 < 0)
		t0 = -t0;
	colore = rgb_to_int(ambiant_light(o, strct, strct.object_color, t0));
	o = object_shadow(strct, normal, s_hit);
	if ((o == 1 || o == 0) && strct.save == 0)
		mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
}
