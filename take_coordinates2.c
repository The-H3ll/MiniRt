/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_coordinates2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:01:09 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/20 18:48:22 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		take_light(char *str, t_strct *strct, t_strct *head)
{
	int	i;

	i = 1;
	if (strct->light_color_nmbr >= 1)
	{
		strct->light = strct->light->next;
		light_next_alocation(strct);
		if (head->light->next == NULL)
			head->light->next = strct->light;
		else if (head->light->next->next == NULL)
			head->light->next->next = strct->light;
		else if (head->light->next->next->next == NULL)
			head->light->next->next->next = strct->light;
		else if (head->light->next->next->next->next == NULL)
			head->light->next->next->next->next = strct->light;
	}
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			strct->light = light_coordinate(strct, str, i);
			return ;
		}
		i++;
	}
}

void		take_plane(char *str, t_strct *strct, t_strct *head)
{
	int i;

	i = 1;
	if (strct->plan_nmbr >= 1)
	{
		strct->plane = strct->plane->next;
		plane_next_allocation(strct);
		if (head->plane->next == NULL)
			head->plane->next = strct->plane;
		else if (head->plane->next->next == NULL)
			head->plane->next->next = strct->plane;
		else if (head->plane->next->next->next == NULL)
			head->plane->next->next->next = strct->plane;
		else if (head->plane->next->next->next->next == NULL)
			head->plane->next->next->next->next = strct->plane;
	}
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			strct->plane = plane_coordinate(strct, str, i);
			return ;
		}
		i++;
	}
}

void		take_triangle(char *str, t_strct *strct)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			strct->triangle->vert1 = take_pos(strct->triangle->vert1, &i, str);
			while (!ft_isdigit(str[i]))
				i++;
			strct->triangle->vert2 = take_pos(strct->triangle->vert2, &i, str);
			while (!ft_isdigit(str[i]))
				i++;
			strct->triangle->vert3 = take_pos(strct->triangle->vert3, &i, str);
			while (!ft_isdigit(str[i]))
				i++;
			strct->triangle->color = take_color(strct->triangle->color, &i,
					str);
			return ;
		}
		i++;
	}
}

void		take_square(char *str, t_strct *strct)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			strct->square = square_coordinate(strct, str, i);
			return ;
		}
		i++;
	}
}

void		take_cylindre(char *str, t_strct *strct, t_strct *head)
{
	int i;

	i = 0;
	if (strct->cylindre_nmbr >= 1)
	{
		strct->cylindre = strct->cylindre->next;
		cylindre_next_allocation(strct);
		go_next_(strct, head);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			strct->cylindre = cylindre_coordinate(strct, str, i);
			return ;
		}
		i++;
	}
}
