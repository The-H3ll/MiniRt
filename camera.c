/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:36:35 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/18 13:59:30 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector		*normalize(t_vector *dir)
{
    float	length;
    t_vector    *dire;

    dire = (t_vector *) malloc(sizeof(t_vector));
    length = sqrt(pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2));
    dire->x = (dir->x / length);
    dire->y = (dir->y / length);
    dire->z = (dir->z / length);
    return (dire);
}

float		dot_product(t_vector *vec, t_ray *ray)
{
    float	dot_product;


    dot_product = (vec->x * ray->dir->x) + (vec->y * ray->dir->y) +
        (vec->z * ray->dir->z);
    return (dot_product);
}

float		dot_v(t_vector *vec, t_vector *ray)
{
    float	dot_product;

    dot_product = (vec->x * ray->x) + (vec->y * ray->y) +
        (vec->z * ray->z);
    return (dot_product);
}

static float			sphere_intersect(t_ray *ray, t_sphere *center, float *t0)
{
    t_vector len_c_o;
    float	a;
    float   b;
    float	d;
    float   c;

    diff_vec(ray->origin, center->axe, &len_c_o);
    a = dot_product(ray->dir, ray);
    b = 2.0 * dot_v(&len_c_o, ray->dir);
    c = dot_v(&len_c_o, &len_c_o) - (center->radius * center->radius);
    d = b * b - (4 * a * c);
    if (d < 0)
        return (-1.0);
    else
    {
        *t0 = -b -sqrt(d);
        if (*t0 > 0)
            return (*t0 = *t0 / 2.0 * a);
        *t0 = -b + sqrt(d);
        if (*t0 > 0)
            return (*t0 = *t0 / 2.0 * a);
        else
            return (-1);
    }
    return (0);
}

void		eye_view(t_strct strct)
{
    int	    i;
    int	    j;
    int     colore;
    float	imag_ratio;
    float	fov;
    float   t0;
    float k;
    t_vector     normal_p;
    t_vector    normal_s;
    t_vector    p_hit;
    t_vector    s_hit;
    float   t1;
    float   o;
    float   t2;

    i = 0;
    j = 0;
    k = 0;
    o = 0;
    imag_ratio = strct.display->width / (float)strct.display->height;
    fov = tan(strct.ray->fov * M_PI /360);
    t_ray ray_shad;

    ray_shad.dir = (t_vector *) malloc(sizeof(t_vector));
    while (i < strct.display->height)
    {
        j = 0;
        t1 = INFINITY;
        while (j < strct.display->width)
        {
            strct.ray->dir->x = (2 * ((j + 0.5) / (float)strct.display->width) - 1)  * imag_ratio * fov;
            strct.ray->dir->y = (1 - 2 * ((i + 0.5) / (float)strct.display->height)) * fov;
            strct.ray->dir->z = 1;
            strct.ray->dir = normalize(strct.ray->dir);
            //mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, 0xffffff);
            t0 = sphere_intersect(strct.ray, strct.sphere, &t0);
            t1 = plane_intersect(&strct, &t1);
            if (t0 > 0)
            {
                s_hit = hit_point_sp(&t0, strct.ray->dir, &strct);
                //                printf("-- %f -- %f -- %f\n", strct.light->)
                diff_vec(&s_hit, strct.sphere->axe, &normal_s);
                normal_s = *normalize(&normal_s);
                //             printf("nor -- %f | -- %f | -- %f\n", normal.x, normal.y, normal.z);
                o = dot_vec(&normal_s, strct.ray->dir);
                colore = rgb_to_int(ambiant_light(o, strct));
                mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
            }
            else if (t1 > 0)
            {
                p_hit = hit_point_pl(&t1, &strct);
                diff_vec(strct.light->pos, &p_hit, &normal_p);
                normal_p = *normalize(&normal_p);
                ray_shad.dir->x = -normal_p.x;
                ray_shad.dir->y = -normal_p.y;
                ray_shad.dir->z = -normal_p.z;
                t2 = sphere_intersect(&ray_shad, strct.sphere, &t2);
                k = dot_v(&normal_p, strct.plane->dir);
                if (t2 < 0)
                {
                    colore = rgb_to_int(plan_color(k, strct));
                    mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
                }
                //else
               // {
                 //   k = 0;
                  //  colore = rgb_to_int(plan_color(k, strct));
                   // mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, colore);
               // }

            }
            j++;
        }
        i++;
    }
}
