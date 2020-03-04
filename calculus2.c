/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:09:46 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/28 22:37:31 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	hit_point_pl(float *t0, t_strct *strct)
{
	t_vector p_hit;

	ft_memset(&p_hit, 0, sizeof(t_vector));
	p_hit.x = strct->ray->origin->x + (*t0 * strct->ray->dir->x);
	p_hit.y = strct->ray->origin->y + (*t0 * strct->ray->dir->y);
	p_hit.z = strct->ray->origin->z + (*t0 * strct->ray->dir->z);
	return (p_hit);
}

t_vector	norm_vec(t_vector vector)
{
	float	length;

	length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	vector.x = (vector.x / length);
	vector.y = (vector.y / length);
	vector.z = (vector.z / length);
	return (vector);
}

t_vector	vec_multi(t_vector a, t_vector b)
{
	t_vector c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.x * b.z) - (a.z * b.x);
	c.z = (a.z * b.y) - (a.y * b.z);
	return (c);
}

float		tri_hit(t_vector a, t_vector b, t_strct strct, t_vector v0)
{
	t_vector	take;
	t_vector	translation;
	float		alp;
	float		bet;
	float		deter;

	diff_vec(strct.ray->origin, &v0, &translation);
	v0 = neg_value(strct.ray->dir);
	take = vec_multi(v0, a);
	deter = dot_vec(&take, &b);
	take = vec_multi(v0, translation);
	alp = (1 / deter) * (dot_vec(&take, &b));
	if (alp >= 0.0 && alp <= 1.0)
	{
		take = vec_multi(v0, a);
		bet = (1 / deter) * (dot_vec(&take, &translation));
		if (bet >= 0 && (bet + alp) <= 1)
		{
			take = vec_multi(translation, a);
			bet = (1 / deter) * (dot_vec(&take, &b));
			return (bet);
		}
	}
	return (0);
}

float		cy_hit(t_strct strct, t_ray *ray)
{
	float		a;
	float		b;
	float		t1;
	float		t2;
	t_vector	new_pos;

	diff_vec(ray->origin, strct.cylindre->pos, &new_pos);
	for_cyhit(strct, ray, &a, &b);
	t2 = dot_vec(&new_pos, &new_pos) -
		pow(dot_vec(&new_pos, strct.cylindre->dir), 2) - strct.cylindre->diam;
	t1 = -b + sqrt(b * b - 4 * a * t2) / 2 * a;
	t2 = -b - sqrt(b * b - 4 * a * t2) / 2 * a;
	if ((t2 < t1 && t2 > 0 && t1 > 0) || (t2 > 0 && t1 < 0))
		t1 = t2;
	t2 = dot_vec(ray->dir, strct.cylindre->dir) * t1 +
		dot_vec(&new_pos, strct.cylindre->dir);
	if (t2 - strct.cylindre->height / 2 < -a && -a < t2 +
			strct.cylindre->height / 2)
	{
		if (t2 - strct.cylindre->height / 2 < -b && -b < t2 +
				strct.cylindre->height / 2)
			return (t1);
		return (t1);
	}
	return (-1);
}
