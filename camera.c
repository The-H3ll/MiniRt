/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:36:35 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 18:39:57 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*normalize(t_vector *dir)
{
	float		length;
	t_vector	*dire;

	dire = (t_vector *)malloc(sizeof(t_vector));
	length = sqrt(pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2));
	dire->x = (dir->x / length);
	dire->y = (dir->y / length);
	dire->z = (dir->z / length);
	return (dire);
}

float		dot_product(t_vector *vec, t_ray *ray)
{
	float	dot_product;

	dot_product = (vec->x * ray->dir->x) + (vec->y * ray->dir->y) +
		(vec->z * ray->dir->z);
	return (dot_product);
}

int			close_window(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}

void		eye_view(t_strct strct, int ac, int h)
{
	int				i;
	int				j;
	unsigned char	*buf;
	static t_strct	*head;

	strct.width_in_bytes = ((strct.display->width * 24 + 31) / 32) * 4;
	strct.image_size = strct.width_in_bytes * strct.display->height;
	if (h == 1)
		head = take_heads(strct);
	strct.shadow = malloc(sizeof(float));
	buf = malloc(strct.image_size * 2);
	i = 0;
	while (i < strct.display->height)
	{
		j = 0;
		while (j < strct.display->width)
		{
			ray_tracing(strct, head, i, j);
			buf = buf_for_image(strct, buf, strct.display->height - i, j);
			ft_memset(strct.object_color, 0, sizeof(t_color));
			j += 1;
		}
		i += 1;
	}
	ray_end(strct, buf, ac, head);
}
