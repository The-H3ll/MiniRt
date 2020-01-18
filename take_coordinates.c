/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:18:36 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/15 17:51:27 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		take_camera(char *str, t_strct 	*strct)
{
	int i;

	i = 1;
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			strct->ray->origin->x = ft_atoi_float(str + i);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			if (str[i] == ',')
				i++;
			strct->ray->origin->y = ft_atoi_float(str + i);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			if (str[i] == ',')
				i++;
			strct->ray->origin->z = ft_atoi_float(str + i);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			while (!(ft_isdigit(str[i])))
				i++;
			strct->ray->dir->x = ft_atoi_float(str + i);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			if (str[i] == ',')
				i++;
			strct->ray->dir->y = ft_atoi_float(str + i);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			if (str[i] == ',')
				i++;
			strct->ray->dir->z = ft_atoi_float(str + i);
			i++;
			strct->ray->fov = ft_atoi_float(str + i);		
			return ;
		}
		i++;
	}
}	

static void		take_sphere(char *str,	t_strct *strct)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			strct->sphere->axe->x = ft_atoi_float(str + i);
			printf("x === %f\n", strct->sphere->axe->x);
            while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			if (str[i] == ',')
				i++;
			strct->sphere->axe->y = ft_atoi_float(str + i);
			printf("y === %f\n", strct->sphere->axe->y);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			if (str[i] == ',')
				i++;
			strct->sphere->axe->z = ft_atoi_float(str + i);
			printf("y === %f\n", strct->sphere->axe->z);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			while (!(ft_isdigit(str[i])))
				i++;
			strct->sphere->radius = ft_atoi_float(str + i);
			printf("rad === %f\n", strct->sphere->radius);
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			strct->sphere->color->red = ft_atoi(str + i);
			printf("red === %f\n", strct->sphere->color->red);
			while (!(ft_isdigit(str[i])))
				i++;
			while (ft_isdigit(str[i]))
				i++;
			if (str[i] == ',')
				i++;
			strct->sphere->color->green = ft_atoi(str + i);
			printf("green === %f\n", strct->sphere->color->green);
			while (ft_isdigit(str[i]))
				i++;
			if (str[i] == ',')
				i++;
			strct->sphere->color->blue = ft_atoi(str + i);
			printf("blue === %f\n", strct->sphere->color->blue);
			return ;
		}
		i++;
	}
}

static void         take_ambiant(t_strct *strct, char *str)
{
    int i;

    i = 1;
    while (str[i] != '\n')
    {
        if (ft_isdigit(str[i]))
        {
            strct->ambiant->ratio = ft_atoi_float(str + i);
            while (ft_isdigit(str[i]) || str[i] == '.')
                i++;
            while (!ft_isdigit(str[i]))
                i++;
            strct->ambiant->color->red = ft_atoi(str + i);
            while (ft_isdigit(str[i]))
                i++;
           if (str[i] == ',')
               i++;
           strct->ambiant->color->green = ft_atoi(str + i);
           while (ft_isdigit(str[i]))
               i++;
           if (str[i] == ',')
               i++;
           strct->ambiant->color->blue = ft_atoi(str + i);
           return ;
        }
        i++;
    }
}

//	the use of this function is to take the coordinate from *.rt
void		take_coordinate(t_strct *strct, char **av)
{
	int fd;
	char *str;

	fd = open(av[1], O_RDONLY);
	str = (char *) calloc(sizeof(char) , 100);
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == 'R')
			take_resolution(strct, str);
        else if (str[0] == 'A')
            take_ambiant(strct, str);
		else if (str[0] == 'c')
			take_camera(str, strct);
        else if (str[0] == 'l')
            take_light(str, strct);
        else if (str[0] == 'p')
            take_plane(str, strct);
        else if (str[0] == 's')
			take_sphere(str, strct);
		free(str);
	}
	free(str);
	str = NULL;
}

int		rgb_to_int(t_color color)
{
	return ((color.red * 256 * 256) + (color.green * 256) + color.blue);
}
