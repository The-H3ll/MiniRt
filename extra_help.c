/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:06:13 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/28 23:26:58 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		for_cyhit(t_strct strct, t_ray *ray, float *a, float *b)
{
	t_vector	new_pos;

	diff_vec(ray->origin, strct.cylindre->pos, &new_pos);
	*a = dot_vec(ray->dir, ray->dir) -
		pow(dot_vec(ray->dir, strct.cylindre->dir), 2);
	*b = 2 * dot_vec(ray->dir, &new_pos) -
		(dot_vec(ray->dir, strct.cylindre->dir) *
		dot_vec(&new_pos, strct.cylindre->dir));
}

t_vector	*for_camera(t_strct strct, int i, int j, float imag_ratio)
{
	strct.ray->dir->x = strct.vec_dir->x;
	strct.ray->dir->y = (1 - 2 * ((i + 0.5) / (float)strct.display->height))
		* tan(strct.ray->fov * M_PI / 360);
	strct.ray->dir->z = (2 * ((j + 0.5) / (float)strct.display->width) - 1)
		* imag_ratio * tan(strct.ray->fov * M_PI / 360);
	return (strct.ray->dir);
}

void		return_camera(t_strct *strct, char *str, int i)
{
	strct->ray->origin = take_pos(strct->ray->origin, &i, str);
	while (!(ft_isdigit(str[i])))
		i++;
	strct->vec_dir = take_pos(strct->vec_dir, &i, str);
	while (!(ft_isdigit(str[i])))
		i++;
	strct->ray->fov = ft_atoi_float(str + i);
	if (str[i - 1] == '-')
		strct->ray->fov = -strct->ray->fov;
	if (strct->ray->fov < 0 || strct->ray->fov > 180)
	{
		perror("Please just let him insert the coordinate");
		exit(-1);
	}
}

void		next_(t_strct *strct, t_strct *head)
{
	if (head->ray->next == NULL)
		head->ray->next = strct->ray;
	else if (head->ray->next->next == NULL)
		head->ray->next->next = strct->ray;
	else if (head->ray->next->next->next == NULL)
		head->ray->next->next->next = strct->ray;
	else if (head->ray->next->next->next->next == NULL)
		head->ray->next->next->next->next = strct->ray;
	if (head->vec_dir->next == NULL)
		head->vec_dir->next = strct->vec_dir;
	else if (head->vec_dir->next->next == NULL)
		head->vec_dir->next->next = strct->vec_dir;
	else if (head->vec_dir->next->next->next == NULL)
		head->vec_dir->next->next->next = strct->vec_dir;
	else if (head->vec_dir->next->next->next->next == NULL)
		head->vec_dir->next->next->next->next = strct->vec_dir;
}

void		reset(t_strct *strct)
{
	put_to_zero(strct->plane->pos);
	put_to_zero(strct->sphere->axe);
	put_to_zero(strct->cylindre->pos);
	put_to_zero(strct->triangle->vert1);
	put_to_zero(strct->triangle->vert2);
	put_to_zero(strct->triangle->vert3);
	put_to_zero(strct->square->pos);
}
