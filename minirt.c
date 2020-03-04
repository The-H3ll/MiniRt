/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:43:30 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/26 16:31:59 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>

int				test(int x, t_create *display)
{
	if (x == 53)
	{
		mlx_clear_window(display->ptr, display->win);
		mlx_destroy_window(display->ptr, display->win);
	}
	return (0);
}

static void		create_window(t_display *display, t_create *create, int i)
{
	create->ptr = mlx_init();
	if (create->ptr == NULL)
		return ;
	if (i == 0)
		create->win = mlx_new_window(create->ptr, display->width,
				display->height, "MiniRT");
	if (create->win == NULL)
		return ;
}

static	void	take_height_width(t_strct *strct, char *str)
{
	int i;

	i = 1;
	while (!(ft_isdigit(str[i])))
		i++;
	strct->display->width = ft_atoi(str + i);
	if (str[i - 1] == '-')
		strct->display->width = -strct->display->width;
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	strct->display->height = ft_atoi(str + i);
	if (str[i - 1] == '-')
		strct->display->width = -strct->display->width;
	if (strct->display->width < 0 || strct->display->height < 0)
	{
		perror("ERROR 'positive pls'\n");
		exit(0);
	}
}

void			take_resolution(t_strct *strct, char *str, int i)
{
	take_height_width(strct, str);
	if (strct->display->width > 3000)
		strct->display->width = 3000;
	if (strct->display->height > 1600)
		strct->display->height = 1600;
	create_window(strct->display, strct->create, i);
}

int				minirt(int ac, char **av)
{
	t_strct		strct;
	int			i;

	i = 0;
	ft_memset(&strct, 0, sizeof(t_strct));
	if (ac < 2 || ac > 3)
	{
		ft_putstr("Usage ./a.out *.rt\n");
		return (-1);
	}
	if (check_rt(av[1]) == 0)
	{
		perror("ERROR\n");
		exit(0);
	}
	strct.save = 0;
	if (ac == 3)
		strct.save = check_save(av[2], strct.save, &i);
	object_allocation(&strct);
	object_allocation_two(&strct);
	take_coordinate(&strct, av, i);
	eye_view(strct, ac, 1);
	free_object(&strct);
	free_object_two(&strct);
	return (0);
}
