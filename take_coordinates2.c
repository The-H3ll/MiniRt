/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_coordinates2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:01:09 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/14 16:33:00 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void        take_light(char *str, t_strct *strct)
{
    int i;

    i = 1;
    while (str[i] != '\n')
    {
        if (ft_isdigit(str[i]))
        {
            strct->light->pos->x = ft_atoi_float(str + i);
            if (str[i - 1] == '-')
                strct->light->pos->x =  -strct->light->pos->x;
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            if (str[i] == ',')
                i++;
            strct->light->pos->y = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            if (str[i] == ',')
                i++;
            strct->light->pos->z = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            while (!(ft_isdigit(str[i])))
                i++;
            strct->light->ratio = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.')
                i++;
            while (!(ft_isdigit(str[i])))
                i++;
            strct->light->color->red = ft_atoi(str + i);
            while (ft_isdigit(str[i]))
                i++;
            if (str[i] == ',')
                i++;
            strct->light->color->green = ft_atoi(str + i);
            while (ft_isdigit(str[i]))
                i++;
            if (str[i] == ',')
                i++;
            strct->light->color->blue = ft_atoi(str + i);
            return ;
        }
        i++;
    }
}

void    take_plane(char *str, t_strct *strct)
{
    int i;

    i = 1;
    while (str[i] != '\n')
    {
        if (ft_isdigit(str[i]))
        {
            strct->plane->pos->x = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.')
                i++;
            if (str[i] == ',')
                i++;
            strct->plane->pos->y = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            if (str[i] == ',')
                i++;
            strct->plane->pos->z = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            while (!(ft_isdigit(str[i])))
                i++;
            strct->plane->dir->x = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            if (str[i] == ',')
                i++;
            strct->plane->dir->y = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
            if (str[i] == ',')
                i++;
            strct->plane->dir->z = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
                i++;
           while (!ft_isdigit(str[i]))
               i++;
           strct->plane->color->red = ft_atoi(str + i);
           while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
               i++;
           if (str[i] == ',')
               i++;
           strct->plane->color->green = ft_atoi(str + i);
           while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
               i++;
          if (str[i] == ',')
              i++;
          strct->plane->color->blue = ft_atoi(str + i);
          return ;
        }
        i++;
    }
}
