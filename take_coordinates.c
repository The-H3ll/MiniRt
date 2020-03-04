/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:18:36 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 20:56:48 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		take_camera(char *str, t_strct *strct, t_strct *head)
{
	int i;

	i = 1;
	if (strct->camera_nmbr >= 1)
	{
		strct->ray = strct->ray->next;
		strct->vec_dir = strct->vec_dir->next;
		ray_next_allocation(strct);
		vec_next_allocation(strct);
		next_(strct, head);
	}
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			return_camera(strct, str, i);
			return ;
		}
		i++;
	}
}

void		take_sphere(char *str, t_strct *strct, t_strct *head)
{
	int	i;

	i = 0;
	if (strct->sphere_nmbr >= 1)
	{
		strct->sphere = strct->sphere->next;
		sphere_next_allocation(strct);
		if (head->sphere->next == NULL)
			head->sphere->next = strct->sphere;
		else if (head->sphere->next->next == NULL)
			head->sphere->next->next = strct->sphere;
		else if (head->sphere->next->next->next == NULL)
			head->sphere->next->next->next = strct->sphere;
		else if (head->sphere->next->next->next->next == NULL)
			head->sphere->next->next->next->next = strct->sphere;
	}
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			strct->sphere = sphere_coordinate(strct, str, i);
			return ;
		}
		i++;
	}
}

void		take_ambiant(t_strct *strct, char *str)
{
	int i;

	i = 1;
	while (str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			strct->ambiant->ratio = ft_atoi_float(str + i);
			if (str[i - 1] == '-')
				strct->ambiant->ratio = -strct->ambiant->ratio;
			if (strct->ambiant->ratio < 0 || strct->ambiant->ratio > 1)
			{
				perror("Please insert nmbr between [0,1]\n");
				exit(-1);
			}
			while (ft_isdigit(str[i]) || str[i] == '.')
				i++;
			while (!ft_isdigit(str[i]))
				i++;
			strct->ambiant->color = take_color(strct->ambiant->color, &i, str);
			return ;
		}
		i++;
	}
}

void		take_coordinate(t_strct *strct, char **av, int i)
{
	int			fd;
	char		*str;
	t_strct		*head;

	fd = open(av[1], O_RDONLY);
	str = (char *)calloc(sizeof(char), 100);
	head = (t_strct *)malloc(sizeof(t_strct));
	heads_point_to(strct, head);
	head->cylindre->next = NULL;
	head->ray->next = NULL;
	head->vec_dir->next = NULL;
	reset(strct);
	while (get_next_line(fd, &str) > 0)
	{
		take_object(strct, str, head, i);
		free(str);
	}
	free(str);
	strct->sphere = head->sphere;
	strct->plane = head->plane;
	strct->cylindre = head->cylindre;
	strct->light = head->light;
	strct->ray = head->ray;
	strct->vec_dir = head->vec_dir;
	str = NULL;
}

int			rgb_to_int(t_color color)
{
	return ((color.red * 256 * 256) + (color.green * 256) + color.blue);
}
