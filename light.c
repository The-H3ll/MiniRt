/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:37:46 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 16:41:28 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		ambiant_light(float k, t_strct strct, t_color *colore, float i)
{
	if (strct.sphere_nmbr == 1)
	{
		colore->red = strct.sphere->color->red;
		colore->blue = strct.sphere->color->blue;
		colore->green = strct.sphere->color->green;
	}
	colore->red += strct.ambiant->color->red * strct.ambiant->ratio;
	colore->green += strct.ambiant->color->green * strct.ambiant->ratio;
	colore->blue += strct.ambiant->color->blue * strct.ambiant->ratio;
	if (k > 0)
	{
		i = pow(i, 255);
		k += i;
		colore->red += k * strct.light->color->red * strct.light->ratio;
		colore->green += k * strct.light->color->green * strct.light->ratio;
		colore->blue += k * strct.light->color->blue * strct.light->ratio;
	}
	colore = color_limit(colore);
	return (*colore);
}

t_color		plan_color(float k, t_strct strct, t_color *colore, float i)
{
	if (strct.sphere_nmbr == 1)
	{
		colore->red = strct.plane->color->red;
		colore->blue = strct.plane->color->blue;
		colore->green = strct.plane->color->green;
	}
	colore->red += strct.ambiant->color->red * strct.ambiant->ratio;
	colore->green += strct.ambiant->color->green * strct.ambiant->ratio;
	colore->blue += strct.ambiant->color->blue * strct.ambiant->ratio;
	if (k > 0)
	{
		i = pow(i, 255);
		k += i;
		colore->red += k * strct.light->color->red * strct.light->ratio;
		colore->green += k * strct.light->color->green * strct.light->ratio;
		colore->blue += k * strct.light->color->blue * strct.light->ratio;
	}
	if (colore->blue < 0)
		colore->blue = 0;
	if (colore->green < 0)
		colore->green = 0;
	if (colore->red < 0)
		colore->red = 0;
	colore = color_limit(colore);
	return (*colore);
}

t_color		tri_color(float k, t_strct *strct, t_color *colore)
{
	colore->red = strct->triangle->color->red;
	colore->blue = strct->triangle->color->blue;
	colore->green = strct->triangle->color->green;
	colore->red += strct->ambiant->color->red * strct->ambiant->ratio;
	colore->blue += strct->ambiant->color->blue * strct->ambiant->ratio;
	colore->green += strct->ambiant->color->green * strct->ambiant->ratio;
	if (k > 0)
	{
		colore->red += k * strct->light->color->red * strct->light->ratio;
		colore->green += k * strct->light->color->green * strct->light->ratio;
		colore->blue += k * strct->light->color->blue * strct->light->ratio;
	}
	colore->red = (int)colore->red;
	colore->green = (int)colore->green;
	colore->blue = (int)colore->blue;
	if (colore->red > 255)
		colore->red = 255;
	if (colore->green > 255)
		colore->green = 255;
	if (colore->blue > 255)
		colore->blue = 255;
	return (*colore);
}

t_color		sq_color(float k, t_strct *strct, t_color *color)
{
	color->red = strct->square->color->red;
	color->blue = strct->square->color->blue;
	color->green = strct->square->color->green;
	color->red += strct->ambiant->color->red * strct->ambiant->ratio;
	color->blue += strct->ambiant->color->blue * strct->ambiant->ratio;
	color->green += strct->ambiant->color->green * strct->ambiant->ratio;
	if (k > 0)
	{
		color->red += k * strct->light->color->red * strct->light->ratio;
		color->blue += k * strct->light->color->blue * strct->light->ratio;
		color->green += k * strct->light->color->green * strct->light->ratio;
	}
	color->red = (int)color->red;
	color->blue = (int)color->blue;
	color->green = (int)color->green;
	if (color->red > 255)
		color->red = 255;
	if (color->green > 255)
		color->green = 255;
	if (color->blue > 255)
		color->blue = 255;
	return (*color);
}

t_color		cy_color(float k, t_strct *strct, t_color *color, float i)
{
	if (strct->sphere_nmbr == 1)
	{
		color->red = strct->cylindre->color->red;
		color->blue = strct->cylindre->color->blue;
		color->green = strct->cylindre->color->green;
	}
	color->red += strct->ambiant->color->red * strct->ambiant->ratio;
	color->blue += strct->ambiant->color->blue * strct->ambiant->ratio;
	color->green += strct->ambiant->color->green * strct->ambiant->ratio;
	if (k > 0)
	{
		i = pow(i, 255);
		k += i;
		color->red += k * strct->light->color->red * strct->light->ratio;
		color->green += k * strct->light->color->green * strct->light->ratio;
		color->blue += k * strct->light->color->blue * strct->light->ratio;
	}
	color = color_limit(color);
	return (*color);
}
