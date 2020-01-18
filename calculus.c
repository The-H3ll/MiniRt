/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:09:20 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/17 14:09:29 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector    scal_calculus(float *t0, t_vector *vector)
{
    t_vector    v;

    ft_memset(&v, 0, sizeof(t_vector));
    v.x = *t0 * vector->x;
    v.y = *t0 * vector->y;
    v.z = *t0 * vector->z;
    return (v);
}

t_vector    vec_plus(t_vector *t_v, t_vector *vector)
{
    t_vector    plus;

    ft_memset(&plus, 0, sizeof(t_vector));
    plus.x = t_v->x + vector->x;
    plus.y = t_v->x + vector->y;
    plus.z = t_v->x + vector->z;
    return (plus);
}

float            dot_vec(t_vector *first, t_vector *second)
{
    float   dot_vec;

    dot_vec = (first->x * (second->x)) + (first->y * (second->y)) + (first->z * (second->z));
    dot_vec = -dot_vec;
    return (dot_vec);
}

void            diff_vec(t_vector *first, t_vector *second, t_vector *diff)
{
    diff->x = first->x - second->x;
    diff->y = first->y - second->y;
    diff->z = first->z - second->z;
}

t_vector            hit_point_sp(float *t0, t_vector *strct, t_strct *str)
{
    t_vector    s_hit;

    ft_memset(&s_hit, 0, sizeof(t_vector));
    s_hit.x = (*t0 * strct->x) + str->light->pos->x; 
    s_hit.y = (*t0 * strct->y) + str->light->pos->y; 
    s_hit.z = (*t0 * strct->z) + str->light->pos->z; 
    return (s_hit);
}
