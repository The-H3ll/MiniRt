/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:25:32 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 15:50:04 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		dot_v(t_vector *vec, t_vector *ray)
{
	float	dot_product;

	dot_product = (vec->x * ray->x) + (vec->y * ray->y) +
		(vec->z * ray->z);
	return (dot_product);
}

t_vector	*camera_dir(int i, int j, t_strct strct)
{
	float	imag_ratio;

	imag_ratio = strct.display->width / (float)strct.display->height;
	if (strct.vec_dir->z != 0)
	{
		strct.ray->dir->x = (2 * ((j + 0.5) / (float)strct.display->width) - 1)
			* imag_ratio * tan(strct.ray->fov * M_PI / 360);
		strct.ray->dir->y = (1 - 2 * ((i + 0.5) / (float)strct.display->height))
			* tan(strct.ray->fov * M_PI / 360);
		strct.ray->dir->z = strct.vec_dir->z;
	}
	else if (strct.vec_dir->x != 0)
		strct.ray->dir = for_camera(strct, i, j, imag_ratio);
	else if (strct.vec_dir->y != 0)
	{
		strct.ray->dir->x = (2 * ((j + 0.5) / (float)strct.display->width) - 1)
			* imag_ratio * tan(strct.ray->fov * M_PI / 360);
		strct.ray->dir->y = strct.vec_dir->y;
		strct.ray->dir->z = (1 - 2 * ((i + 0.5) / (float)strct.display->height))
			* tan(strct.ray->fov * M_PI / 360);
	}
	strct.ray->dir = normalize(strct.ray->dir);
	return (strct.ray->dir);
}

t_strct		add_all(t_strct strct, t_strct *head, int i, int j)
{
	if (strct.light != NULL && strct.wich_object != 2)
		apply_light(strct, head, i, j);
	if (strct.wich_object == 2)
		apply(strct, head, i, j);
	return (strct);
}

void		ray_tracing(t_strct strct, t_strct *head, int i, int j)
{
	strct.t0 = 2147483647;
	strct = return_object(strct, head, i, j);
	strct.wich_object = last_in_first_out(strct, &strct.t0, strct.ray, 0);
	triangle_hit_point(strct, i, j, strct.t0);
	hit_square(strct, i, j, strct.t0);
	strct = add_all(strct, head, i, j);
}
