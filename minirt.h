/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:16:09 by molabhai          #+#    #+#             */
/*   Updated: 2020/02/29 23:05:21 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "./get_next_line.h"

typedef struct			s_create
{
	void	*ptr;
	void	*win;
}						t_create;

typedef struct			s_vector
{
	float			x;
	float			y;
	float			z;
	struct s_vector	*next;
}						t_vector;

typedef	struct			s_color
{
	float		red;
	float		green;
	float		blue;
}						t_color;

typedef struct			s_ray
{
	t_vector		*origin;
	t_vector		*dir;
	float			fov;
	struct s_ray	*next;
}						t_ray;

typedef	struct			s_sphere
{
	t_vector			*axe;
	t_color				*color;
	float				radius;
	struct s_sphere		*next;
}						t_sphere;

typedef struct			s_display
{
	int		height;
	int		width;
}						t_display;

typedef struct			s_ambiant
{
	float	ratio;
	t_color	*color;
}						t_ambiant;

typedef struct			s_light
{
	t_vector			*pos;
	t_color				*color;
	float				ratio;
	struct s_light		*next;
}						t_light;

typedef struct			s_plane
{
	t_vector			*pos;
	t_color				*color;
	t_vector			*dir;
	struct s_plane		*next;
}						t_plane;

typedef struct			s_triangle
{
	t_vector	*vert1;
	t_vector	*vert2;
	t_vector	*vert3;
	t_color		*color;
}						t_triangle;

typedef struct			s_square
{
	t_vector	*pos;
	t_vector	*dir;
	float		rad;
	t_color		*color;
}						t_square;

typedef struct			s_cylindre
{
	t_vector			*pos;
	t_vector			*dir;
	t_color				*color;
	float				diam;
	float				height;
	struct s_cylindre	*next;
}						t_cylindre;

typedef	struct			s_strct
{
	t_ray		*ray;
	t_sphere	*sphere;
	t_display	*display;
	t_create	*create;
	t_ambiant	*ambiant;
	t_color		*color;
	t_light		*light;
	t_plane		*plane;
	t_triangle	*triangle;
	t_square	*square;
	t_cylindre	*cylindre;
	t_color		*object_color;
	t_vector	*vec_dir;
	int			wich_object;
	int			light_color_nmbr;
	int			sphere_nmbr;
	int			plan_nmbr;
	int			cylindre_nmbr;
	int			camera_nmbr;
	float		*shadow;
	float		t0;
	int			width_in_bytes;
	int			image_size;
	uint32_t	filesize;
	uint16_t	biplanes;
	int			save;
}						t_strct;

void					ft_putchar(char c);
void					ft_putstr(char *s);
int						minirt(int ac, char **av);
void					triangl(void *mlx_ptr, void	*mlx_window, int x, int y);
void					cercle(void *mlx_ptr, void	*mlx_window, int x, int y);
void					eye_view(t_strct strc, int ac, int h);
float					ft_atoi_float(char *str);
void					take_coordinate(t_strct *strct, char **av, int i);
void					take_resolution(t_strct *strct, char *str, int i);
int						rgb_to_int(t_color color);
t_vector				hit_point_sp(float *t0, t_vector *strct, t_strct *s);
t_vector				hit_point_pl(float *t0, t_strct *s);
float					dot_vec(t_vector *first, t_vector *second);
void					diff_vec(t_vector *first, t_vector *second,
		t_vector *vec);
t_vector				norm_vec(t_vector vector);
t_color					ambiant_light(float k, t_strct strct, t_color *color,
		float i);
void					take_light(char *str, t_strct *strct, t_strct *light);
float					dot_v(t_vector *vec, t_vector *ray);
float					plane_intersect(t_strct *strct, t_ray *ray);
void					take_plane(char *str, t_strct *strct, t_strct *head);
t_vector				scal_calculus(float *t0, t_vector *vector);
t_vector				vec_plus(t_vector *t_v, t_vector *vector);
t_color					plan_color(float k, t_strct strct, t_color *color,
		float i);
void					sphere_hit_point(float t0, t_strct strct, int i, int j);
t_vector				*normalize(t_vector *dir);
void					plan_hit_point(float t0, t_strct strct, int i, int j);
float					sphere_intersect(t_ray *ray, t_sphere *center,
		float *t0);
float					dot_product(t_vector *vec, t_ray *ray);
t_color					*take_color(t_color *s, int *i, char *str);
t_vector				*take_pos(t_vector *s, int *i, char *str);
void					take_triangle(char *str, t_strct *strct);
t_vector				vec_multi(t_vector a, t_vector b);
void					triangle_hit_point(t_strct strct, int i, int j,
		float t);
float					tri_hit(t_vector a, t_vector b, t_strct strct,
		t_vector v0);
t_color					tri_color(float k, t_strct *strct, t_color *color);
void					take_square(char *str, t_strct *strct);
void					hit_square(t_strct strct, int i, int j, float t0);
t_color					sq_color(float k, t_strct *strct, t_color *color);
t_vector				refraction(t_vector	dir, t_vector normal,
		t_vector p_hit);
void					take_cylindre(char *str, t_strct *strct, t_strct *head);
void					cylindre_hit_point(float t, t_strct strct, int i, int j,
		t_color *colori, int gl_k);
float					cy_hit(t_strct strct, t_ray *ray);
void					cy_colo(t_strct strct, int i, int j, float t0);
t_color					cy_color(float k, t_strct *strct, t_color *color,
		float o);
void					object_draw(t_strct strct, float t, int i, int j);
float					last_in_first_out(t_strct strct, float *t0, t_ray *ray,
		int i);
float					object_shadow(t_strct strct, t_vector normal,
		t_vector p_hit);
t_vector				specular_light(t_vector normal_s, t_vector normal);
float					plane_intersect_sq(t_strct *strct, t_ray *ray);
int						inter_or_not(t_strct strct, t_vector normal,
		float width);
t_vector				neg_value(t_vector *vec);
void					object_allocation(t_strct *strct);
void					object_allocation_two(t_strct *strct);
void					free_object(t_strct *strct);
void					free_object_two(t_strct *strct);
void					take_object(t_strct *strct, char *str, t_strct *head,
		int i);
void					take_camera(char *str, t_strct *strct, t_strct *head);
void					take_sphere(char *str, t_strct *strct, t_strct *head);
void					take_ambiant(t_strct *strct, char *str);
void					light_next_alocation(t_strct *strct);
t_light					*light_coordinate(t_strct *strct, char *str, int i);
t_square				*square_coordinate(t_strct *strct, char *str, int i);
t_cylindre				*cylindre_coordinate(t_strct *strct, char *str, int i);
void					sphere_next_allocation(t_strct *strct);
t_sphere				*sphere_coordinate(t_strct *strct, char *str, int i);
t_sphere				*wich_sphere(t_strct strct, t_strct *head);
void					plane_next_allocation(t_strct *strct);
t_plane					*wich_plane(t_strct strct, t_strct *head);
void					cylindre_next_allocation(t_strct *strct);
t_cylindre				*wich_cylindre(t_strct strct, t_strct *head);
void					*ft_memset(void *s, int c, size_t len);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
void					save_image(t_strct strct, unsigned char *buf);
void					set_object_to_null(t_strct *strct);
void					apply(t_strct strct, t_strct *head, int i, int j);
t_strct					ret_object(t_strct *strct, t_strct *head, float t0);
void					apply_light(t_strct strct, t_strct *head, int i, int j);
unsigned char			*buf_for_image(t_strct strct, unsigned char *buf,
		int k, int j);
void					ray_end(t_strct strct, unsigned char *buf, int ac,
		t_strct *head);
int						close_window(void *param);
int						use_key(int keycode, void *param);
void					using_keys(t_strct strct);
t_strct					*take_heads(t_strct strct);
t_strct					return_object(t_strct strct, t_strct *head, int i,
		int j);
t_vector				*camera_dir(int i, int j, t_strct strct);
t_strct					add_all(t_strct strct, t_strct *head, int i, int j);
void					ray_tracing(t_strct strct, t_strct *head, int i, int j);
void					just_take(char *str, t_strct *strct, t_strct *head);
void					cy_err(void);
void					for_plane(t_strct strct, int i, int j);
t_color					*color_limit(t_color *colore);
t_plane					*plane_coordinate(t_strct *strct, char *str, int i);
void					go_next_(t_strct *strct, t_strct *head);
void					*ft_memset(void *s, int c, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					put_to_zero(t_vector *plane);
int						check_save(char *av, int save, int *i);
int						check_rt(char *av);
void					ray_next_allocation(t_strct *strct);
void					vec_next_allocation(t_strct *strct);
t_vector				*for_camera(t_strct strct, int i, int j,
		float image_ratio);
void					for_cyhit(t_strct strct, t_ray *ray, float *a,
		float *b);
void					next_(t_strct *strct, t_strct *head);
void					return_camera(t_strct *strct, char *str, int i);
void					reset(t_strct *strct);
void					heads_point_to(t_strct *strct, t_strct *head);
void					just_some_error(char *str);
#endif
