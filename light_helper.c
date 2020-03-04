/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:27:06 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/28 23:45:20 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		*color_limit(t_color *colore)
{
	colore->red = (int)colore->red;
	colore->green = (int)colore->green;
	colore->blue = (int)colore->blue;
	if (colore->red > 255)
		colore->red = 255;
	if (colore->green > 255)
		colore->green = 255;
	if (colore->blue > 255)
		colore->blue = 255;
	return (colore);
}

void		heads_point_to(t_strct *strct, t_strct *head)
{
	head->sphere = strct->sphere;
	head->light = strct->light;
	head->plane = strct->plane;
	head->ray = strct->ray;
	head->vec_dir = strct->vec_dir;
	head->cylindre = strct->cylindre;
}
