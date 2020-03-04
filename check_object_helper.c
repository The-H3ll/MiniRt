/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:41:17 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/28 23:23:40 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned char	*buf_for_image(t_strct strct, unsigned char *buf, int k, int j)
{
	buf[k * strct.width_in_bytes + j * 3 + 0] = strct.object_color->blue;
	buf[k * strct.width_in_bytes + j * 3 + 1] = strct.object_color->green;
	buf[k * strct.width_in_bytes + j * 3 + 2] = strct.object_color->red;
	return (buf);
}

int				key_hook(int key_code, void *param)
{
	t_strct *strct;

	strct = (t_strct *)param;
	if (key_code == 126)
		eye_view(*strct, 2, 0);
	else if (key_code == 53)
		exit(0);
	return (0);
}

void			ray_end(t_strct strct, unsigned char *buf, int ac,
		t_strct *head)
{
	if (ac == 3)
	{
		save_image(strct, buf);
		exit(0);
	}
	if (strct.ray->next != NULL && strct.vec_dir->next != NULL)
	{
		strct.ray = strct.ray->next;
		strct.vec_dir = strct.vec_dir->next;
	}
	else
	{
		strct.ray = head->ray;
		strct.vec_dir = head->vec_dir;
	}
	mlx_key_hook(strct.create->win, key_hook, &strct);
	mlx_hook(strct.create->win, 17, 2, close_window, (void *)0);
	mlx_loop(strct.create->ptr);
}

t_strct			*take_heads(t_strct strct)
{
	t_strct *head;

	head = (t_strct *)malloc(sizeof(t_strct));
	head->sphere = strct.sphere;
	head->plane = strct.plane;
	head->cylindre = strct.cylindre;
	head->light = strct.light;
	head->ray = strct.ray;
	head->vec_dir = strct.vec_dir;
	return (head);
}

t_strct			return_object(t_strct strct, t_strct *head, int i, int j)
{
	strct.ray->dir = camera_dir(i, j, strct);
	strct.sphere = wich_sphere(strct, head);
	strct.plane = wich_plane(strct, head);
	strct.cylindre = wich_cylindre(strct, head);
	return (strct);
}
