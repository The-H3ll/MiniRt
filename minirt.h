/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:16:09 by molabhai          #+#    #+#             */
/*   Updated: 2020/01/15 17:55:18 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "./libft/get_next_line.h"
#include "./libft/libft.h"

typedef struct			s_create
{
	void	*ptr;
	void	*win;
}						t_create;

typedef struct			s_vector
{
	float	x;
	float	y;
	float	z;
}						t_vector;

typedef	struct			s_color
{
	float		red;
	float		green;
	float   	blue;
}						t_color;

typedef struct			s_ray
{
	t_vector	*origin;
	t_vector	*dir;
	float			fov;
}						t_ray;

typedef	struct			s_sphere
{
	t_vector	*axe;
	t_color		*color;
	float		radius;
}						t_sphere;

typedef struct			s_display
{
	float 	height;
	float	width;
}						t_display;

typedef struct          s_ambiant
{
    float   ratio;
    t_color *color;
}                       t_ambiant;               

typedef struct          s_light
{
    t_vector    *pos;
    t_color     *color;
    float       ratio;
}                       t_light;

typedef struct          s_plane
{
    t_vector    *pos;
    t_color     *color;
    t_vector    *dir;
}                       t_plane;

typedef	struct			s_strct
{
	t_ray		*ray;
	t_sphere	*sphere;
	t_display	*display;
	t_create	*create;
    t_ambiant   *ambiant;
    t_color     *color;
    t_light     *light;
    t_plane     *plane;
}						t_strct;

void	            ft_putchar(char c);
void	            ft_putstr(char *s);
int		            minirt(int ac, char **av);
void	            triangl(void *mlx_ptr, void	*mlx_window, int x, int y);
void	            cercle(void *mlx_ptr, void	*mlx_window, int x, int y);
void	            eye_view(t_strct strc);
float	            ft_atoi_float(char *str);
void	            take_coordinate(t_strct *strct, char **av);
void	            take_resolution(t_strct *strct, char *str);
int		            rgb_to_int(t_color color);
t_vector            hit_point_sp(float *t0, t_vector *strct, t_strct *s);
t_vector            hit_point_pl(float *t0, t_strct *s);
float               dot_vec(t_vector *first, t_vector *second);
void                diff_vec(t_vector *first, t_vector *second, t_vector *vec);
t_vector            norm_vec(t_vector vector);
t_color             ambiant_light(float k, t_strct strct);
void                take_light(char *str, t_strct *strct);
float		        dot_v(t_vector *vec, t_vector *ray);
float               plane_intersect(t_strct *strct, float *t);
void                take_plane(char *str, t_strct *strct);
t_vector            scal_calculus(float *t0, t_vector *vector);
t_vector            vec_plus(t_vector *t_v, t_vector *vector);
t_color             plan_color(float k, t_strct strct);
#endif
