/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:37:46 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/17 22:38:51 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

t_color         ambiant_light(float k, t_strct strct)
{
    t_color light;
    t_color colore;
    t_color ambiant;

    ft_memset(&light, 0, sizeof(t_color));
    ft_memset(&ambiant, 0, sizeof(t_color));
    ft_memset(&colore, 0, sizeof(t_color));
    light.red = strct.light->color->red * strct.light->ratio;
    light.green = strct.light->color->green * strct.light->ratio;
    light.blue = strct.light->color->blue * strct.light->ratio;
    colore.red = strct.sphere->color->red;
    colore.blue = strct.sphere->color->blue;
    colore.green = strct.sphere->color->green; 
    ambiant.red = strct.ambiant->color->red * strct.ambiant->ratio ;
    ambiant.green = strct.ambiant->color->green * strct.ambiant->ratio;
    ambiant.blue = strct.ambiant->color->blue * strct.ambiant->ratio;
    colore.red += ambiant.red;
    colore.green += ambiant.green;
    colore.blue += ambiant.blue;
    if (k > 0)
    {
        colore.red += k * light.red;
        colore.green += k * light.green;
        colore.blue += k * light.blue;
    }
    colore.red = (int)colore.red;
    colore.green = (int)colore.green;
    colore.blue = (int)colore.blue; 
    if (colore.red > 255)
        colore.red = 255;
    if (colore.green > 255)
        colore.green = 255;
    if (colore.blue > 255)
        colore.blue = 255;
    return (colore);
}

t_color     plan_color(float k, t_strct strct)
{
    t_color light;
    t_color colore;
    t_color ambiant;

    ft_memset(&light, 0, sizeof(t_color));
    ft_memset(&ambiant, 0, sizeof(t_color));
    ft_memset(&colore, 0, sizeof(t_color));
    light.red = strct.light->color->red * strct.light->ratio;
    light.green = strct.light->color->green * strct.light->ratio;
    light.blue = strct.light->color->blue * strct.light->ratio;
    colore.red = strct.plane->color->red;
    colore.blue = strct.plane->color->blue;
    colore.green = strct.plane->color->green; 
    ambiant.red = strct.ambiant->color->red * strct.ambiant->ratio ;
    ambiant.green = strct.ambiant->color->green * strct.ambiant->ratio;
    ambiant.blue = strct.ambiant->color->blue * strct.ambiant->ratio;
    colore.red += ambiant.red + light.red;
    colore.green += ambiant.green + light.green;
    colore.blue += ambiant.blue + light.blue;
    if (k > 0)
    {
        colore.red *= k;
        colore.green *= k;
        colore.blue *= k;
    }
    colore.red = (int)colore.red;
    colore.green = (int)colore.green;
    colore.blue = (int)colore.blue; 
    if (colore.red > 255)
        colore.red = 255;
    if (colore.green > 255)
        colore.green = 255;
    if (colore.blue > 255)
        colore.blue = 255;
    return (colore);
}
