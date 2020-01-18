/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 10:20:26 by molabhai          #+#    #+#             */
/*   Updated: 2019/12/29 17:14:45 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./libx/mlx.h"
//#include "./libft/libft.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "minirt.h"

# define X  800
# define Y  800

void	triangl(void *mlx_ptr, void *mlx_window, int x, int y)
{
	while (x++ < 400 && y-- > 0)
		mlx_pixel_put(mlx_ptr, mlx_window, x, y, 0xffffff);
	x= 0;
	while (x++ < X)
		mlx_pixel_put(mlx_ptr, mlx_window, x, 400, 0xffffff);
	x = 400;
	y = 0;
	while (x++ < X && y++ < 400)
		mlx_pixel_put(mlx_ptr, mlx_window, x, y, 0xffffff);
	x = 0;
	int o = 1;
	int p = 800;
	while (y-- > 0)
	{
		while (x++ < p)
			mlx_pixel_put(mlx_ptr, mlx_window, x, y, 0xffffff);
		p = p - 1;
		x = o;
		o++;
	}
}

void	cercle(void *mlx_ptr, void	*mlx_window, int x, int y)
{
	float g = 0.0;
	int m;
	int l;
	int r  = 300;
	int p = x - 300;
	int k = x  + 300;
	printf(" p == %d\n", p);
	printf(" k == %d\n", k);
	while (g < 360)
	{
		m = x + r * cos(g * (M_PI /180));
		l = y + r * sin(g * (M_PI /180));
		mlx_pixel_put(mlx_ptr, mlx_window, m, l, 0xffffff);
		r = 0;
		while (r++ < 300)
		{
			m = x + r * cos(g * (M_PI /180));
			l = y + r * sin(g * (M_PI /180));
			mlx_pixel_put(mlx_ptr, mlx_window, m, l, 0x4b0082);
		}
		g += 0.1;
	}
	while (p++ < k)
		mlx_pixel_put(mlx_ptr, mlx_window, p, y, 0xffffff);
	int o = 100;
	while (o++ < 700)
		mlx_pixel_put(mlx_ptr, mlx_window, x, o, 0xffffff);

}

int		main(int ac, char **av)
{
	minirt(ac, av);
	return (0);
}	
