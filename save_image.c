/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:35:50 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/25 21:42:27 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	save_image(t_strct strct, unsigned char *buf)
{
	uint16_t			bitcount;
	uint32_t			bisize;
	uint32_t			bfoffbits;
	unsigned char		header[54];
	int					fout;

	bisize = 40;
	bfoffbits = 54;
	bitcount = 24;
	strct.filesize = 54 + strct.image_size;
	strct.biplanes = 1;
	ft_memset(header, 0, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &strct.filesize, 4);
	ft_memcpy(header + 10, &bfoffbits, 4);
	ft_memcpy(header + 14, &bisize, 4);
	ft_memcpy(header + 18, &strct.display->width, 4);
	ft_memcpy(header + 22, &strct.display->height, 4);
	ft_memcpy(header + 26, &strct.biplanes, 2);
	ft_memcpy(header + 28, &bitcount, 2);
	ft_memcpy(header + 34, &strct.image_size, 4);
	fout = open("test.bmp", O_CREAT | O_APPEND | O_WRONLY, S_IRWXU);
	write(fout, header, 54);
	write(fout, (char *)buf, strct.image_size);
	free(buf);
}

void	put_to_zero(t_vector *plane)
{
	plane->x = 0;
	plane->y = 0;
	plane->z = 0;
}

void	ray_next_allocation(t_strct *strct)
{
	strct->ray = (t_ray *)malloc(sizeof(t_ray));
	strct->ray->origin = (t_vector *)malloc(sizeof(t_vector));
	strct->ray->dir = (t_vector *)malloc(sizeof(t_vector));
	strct->ray->next = NULL;
}

void	vec_next_allocation(t_strct *strct)
{
	strct->vec_dir = (t_vector *)malloc(sizeof(t_vector));
	strct->vec_dir->next = NULL;
}
