/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:43:30 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/15 17:38:27 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>

int			test(int x, t_create *display)
{
	if (x == 53)
	{
		mlx_clear_window(display->ptr, display->win);
		mlx_destroy_window(display->ptr, display->win);
	}
	return (0);
}

static void		create_window(t_display *display, t_create *create)
{
	create->ptr = mlx_init();
	if (create->ptr == NULL)
		return ;
	create->win = mlx_new_window(create->ptr, display->width, display->height, "MiniRT");
	if (create->win == NULL)
		return ;
}

static	void			take_height_width(t_strct *strct, char *str)
{
	int i;

	i = 1;
	while (!(ft_isdigit(str[i])))
		i++;
	strct->display->width = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	strct->display->height = ft_atoi(str + i);
}

void	take_resolution(t_strct	*strct, char *str)
{
	strct->display = (t_display *) malloc(sizeof(t_display));
	strct->create = (t_create *) malloc(sizeof(t_create));
	take_height_width(strct, str);
	create_window(strct->display, strct->create);
}

int		minirt(int ac, char **av)
{
	char 		*str;
	t_strct		strct;

	ft_memset(&strct, 0, sizeof(t_strct));
	str = (char *)calloc(sizeof(char), 50);
	if (ac < 2)
	{
		ft_putstr("Usage ./a.out *.rt\n");
		return (-1);
	}
    strct.ray = (t_ray *) malloc(sizeof(t_ray));
    strct.ray->origin = (t_vector *) malloc(sizeof(t_vector));
    strct.ray->dir = (t_vector *) malloc(sizeof(t_vector));
    strct.sphere = (t_sphere *) malloc(sizeof(t_sphere));
    strct.sphere->axe = (t_vector *) malloc(sizeof(t_vector));
    strct.display = (t_display *) malloc(sizeof(t_display));
    strct.sphere->color = (t_color *) malloc(sizeof(t_color));
	strct.ambiant = (t_ambiant *) malloc(sizeof(t_ambiant));
    strct.ambiant->color = (t_color *) malloc(sizeof(t_color));
    strct.color = (t_color *) malloc(sizeof(t_color));
    strct.light = (t_light *) malloc(sizeof(t_light));
    strct.light->pos = (t_vector *) malloc(sizeof(t_vector));
    strct.light->color = (t_color *) malloc(sizeof(t_color));
    strct.plane = (t_plane *) malloc(sizeof(t_plane));
    strct.plane->pos = (t_vector *) malloc(sizeof(t_vector));
    strct.plane->color = (t_color *) malloc(sizeof(t_color));
    strct.plane->dir = (t_vector *) malloc(sizeof(t_vector));
    take_coordinate(&strct, av); 
    eye_view(strct);
    mlx_loop(strct.create->ptr);
	return (0);
}
