/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:32:16 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 18:57:19 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		take_object(t_strct *strct, char *str, t_strct *head, int i)
{
	if (str[0] == 'R')
		take_resolution(strct, str, i);
	else if (str[0] == 'A')
		take_ambiant(strct, str);
	else if (str[0] == 'c' && str[1] == ' ')
	{
		take_camera(str, strct, head);
		strct->camera_nmbr += 1;
	}
	else if (str[0] == 'l')
	{
		take_light(str, strct, head);
		strct->light_color_nmbr += 1;
	}
	else if (str[0] == 'p')
	{
		take_plane(str, strct, head);
		strct->plan_nmbr += 1;
	}
	just_take(str, strct, head);
}

void		light_next_alocation(t_strct *strct)
{
	strct->light = (t_light *)malloc(sizeof(t_light));
	strct->light->pos = (t_vector *)malloc(sizeof(t_vector));
	strct->light->color = (t_color *)malloc(sizeof(t_color));
	strct->light->next = NULL;
}

t_light		*light_coordinate(t_strct *strct, char *str, int i)
{
	strct->light->pos = take_pos(strct->light->pos, &i, str);
	while (!(ft_isdigit(str[i])))
		i++;
	strct->light->ratio = ft_atoi_float(str + i);
	if (str[i - 1] == '-')
		strct->light->ratio = -strct->light->ratio;
	if (strct->light->ratio < 0 || strct->light->ratio > 1)
	{
		perror("Please insert a number between [0, 1]");
		exit(-1);
	}
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	strct->light->color = take_color(strct->light->color, &i, str);
	return (strct->light);
}

t_square	*square_coordinate(t_strct *strct, char *str, int i)
{
	strct->square->pos = take_pos(strct->square->pos, &i, str);
	while (!ft_isdigit(str[i]))
		i++;
	strct->square->dir = take_pos(strct->square->dir, &i, str);
	while (!ft_isdigit(str[i]))
		i++;
	strct->square->rad = ft_atoi_float(str + i);
	if (str[i - 1] == '-')
		strct->square->rad = -strct->square->rad;
	if (strct->square->rad < 0)
	{
		perror(".....JUST POSITIVE NUMBER IN RADIUS");
		exit(-1);
	}
	while (ft_isdigit(str[i]) || str[i] == ',' || str[i] == '.')
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	strct->square->color = take_color(strct->square->color, &i, str);
	return (strct->square);
}

t_cylindre	*cylindre_coordinate(t_strct *strct, char *str, int i)
{
	strct->cylindre->pos = take_pos(strct->cylindre->pos, &i, str);
	while (!ft_isdigit(str[i]))
		i++;
	strct->cylindre->dir = take_pos(strct->cylindre->dir, &i, str);
	while (!ft_isdigit(str[i]))
		i++;
	strct->cylindre->color = take_color(strct->cylindre->color, &i,
			str);
	while (!ft_isdigit(str[i]))
		i++;
	strct->cylindre->diam = ft_atoi_float(str + i);
	if (str[i - 1] == '-')
		strct->cylindre->diam = -strct->cylindre->diam;
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	strct->cylindre->height = ft_atoi_float(str + i);
	if (str[i - 1] == '-')
		strct->cylindre->height = -strct->cylindre->height;
	if (strct->cylindre->diam < 0 || strct->cylindre->height < 0)
		cy_err();
	return (strct->cylindre);
}
