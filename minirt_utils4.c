/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:57:55 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 21:38:50 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		just_take(char *str, t_strct *strct, t_strct *head)
{
	if (str[0] == 's' && str[1] == 'p')
	{
		take_sphere(str, strct, head);
		strct->sphere_nmbr += 1;
	}
	else if (str[0] == 't')
		take_triangle(str, strct);
	else if (str[0] == 's' && str[1] == 'q')
		take_square(str, strct);
	else if (str[0] == 'c' && str[1] == 'y')
	{
		take_cylindre(str, strct, head);
		strct->cylindre_nmbr += 1;
	}
	if (str[0] != 's' && str[0] != 'c' && str[0] != 'R' && str[0] != 'A' &&
			str[0] != 'l' && str[0] != 'p' && str[0] != 0 && str[0] != 't')
	{
		perror("Error just let him enter the coordinate\n");
		exit(1);
	}
	just_some_error(str);
}

void		cy_err(void)
{
	perror(".....JUST POSITIVE NUMBER");
	exit(-1);
}

void		for_plane(t_strct strct, int i, int j)
{
	*(strct.shadow) = 1;
	if (strct.save == 0)
		mlx_pixel_put(strct.create->ptr, strct.create->win, j, i, 0);
}
