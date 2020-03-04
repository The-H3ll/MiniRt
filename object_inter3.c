/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_inter3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:31:19 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/26 18:55:33 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		hit_square(t_strct strct, int i, int j, float t0)
{
	float				width;
	t_vector			p_hit;
	float				k;
	t_vector			normal;
	float				colore;

	width = 0;
	t0 = plane_intersect_sq(&strct, strct.ray);
	if (t0 > 0)
	{
		p_hit = hit_point_pl(&t0, &strct);
		diff_vec(&p_hit, strct.square->pos, &normal);
		if (inter_or_not(strct, normal, width))
		{
			diff_vec(strct.light->pos, &p_hit, &normal);
			normal = *normalize(&normal);
			k = dot_vec(&normal, strct.square->dir);
			colore = rgb_to_int(sq_color(k, &strct, strct.object_color));
			if (strct.save == 0)
				mlx_pixel_put(strct.create->ptr, strct.create->win, j, i,
						colore);
		}
	}
}

void		cy_colo(t_strct strct, int i, int j, float t0)
{
	t_vector	p_hit;
	t_vector	normal_cy;
	t_vector	normal;
	float		k;
	int			colore;

	p_hit = hit_point_pl(&t0, &strct);
	p_hit.x += 0.0001;
	p_hit.y += 0.0001;
	p_hit.z += 0.0001;
	normal_cy.x = -(strct.cylindre->pos->x) + p_hit.x;
	normal_cy.y = -(strct.cylindre->pos->y) + p_hit.y;
	normal_cy.z = -(strct.cylindre->pos->z + strct.cylindre->height) + p_hit.z;
	diff_vec(strct.light->pos, &normal_cy, &normal);
	normal = *normalize(&normal);
	normal_cy = *normalize(&normal_cy);
	normal_cy = specular_light(normal_cy, normal);
	k = dot_vec(&normal, strct.ray->dir);
	t0 = dot_vec(&normal_cy, strct.ray->dir);
	if (t0 < 0)
		t0 = -t0;
	colore = rgb_to_int(cy_color(k, &strct, strct.object_color, t0));
	k = object_shadow(strct, normal, p_hit);
	if ((k == 3 || k == 0) && strct.save == 0)
		mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
}

void		triangle_hit_point(t_strct strct, int i, int j, float t)
{
	t_vector	a;
	int			colore;
	t_vector	p_hit;
	t_vector	normal_t;

	ft_memset(&a, 0, sizeof(t_vector));
	ft_memset(&p_hit, 0, sizeof(t_vector));
	diff_vec(strct.triangle->vert2, strct.triangle->vert1, &a);
	diff_vec(strct.triangle->vert3, strct.triangle->vert1, &normal_t);
	normal_t = vec_multi(a, normal_t);
	normal_t = *normalize(&normal_t);
	t = tri_hit(a, normal_t, strct, *strct.triangle->vert1);
	colore = rgb_to_int(tri_color(t, &strct, strct.object_color));
	if (t > 0 && strct.save == 0)
		mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
}
