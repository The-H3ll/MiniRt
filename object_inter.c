/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:11:42 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/15 21:07:51 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


float       plane_intersect(t_strct *strct, float *t)
{
    float   d;
    float   a;
    float   b;
    t_vector    vec;
    t_vector    or;

    d = 0;
    ft_memset(&or, 0, sizeof(t_vector));
    diff_vec(&or, strct->plane->pos, &vec);
    a = dot_v(&vec, strct->plane->dir);
    b = dot_v(strct->plane->dir, strct->ray->dir);
    if (b != 0)
        d = a / b;
    if (d < *t)
    {
        *t = d;
        return (d);
    }
    return (d);
}
