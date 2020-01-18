/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:01:37 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/17 16:15:01 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector            hit_point_pl(float *t0, t_strct *strct)
{
    t_vector p_hit;

    ft_memset(&p_hit, 0, sizeof(t_vector));
    p_hit.x = *t0 * strct->ray->dir->x;
    p_hit.y = *t0 * strct->ray->dir->y;
    p_hit.z = *t0 * strct->ray->dir->z; 
    return (p_hit);
}

t_vector    norm_vec(t_vector vector)
{
	float	length;

	length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	vector.x = (vector.x / length);
	vector.y = (vector.y / length);
	vector.z = (vector.z / length);
	return (vector);
}
