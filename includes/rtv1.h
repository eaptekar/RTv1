/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:52 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/14 14:59:37 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "mlx_keys_macos.h"

# include <stdio.h>

# define WIN_W	1080
# define WIN_H	1080

# define VW_W	1.0
# define VW_H	1.0
# define DIST	1.0

# define T_MIN	1.0
# define T_MAX	1000.0

typedef struct	s_closest
{
	int			figure;
	double		t;
}				t_closest;

typedef struct	s_roots
{
	double		t1;
	double		t2;
}				t_roots;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_sphere
{
	t_vector	center;
	double		radius;
	int			color;
	int			shine;
	double		reflect;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	center;
	t_vector	normal;
	int			color;
	int			shine;
	double		reflect;
}				t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	double		radius;
	float		maxm;
	int			color;
	int			shine;
	double		reflect;
}				t_cylinder;

typedef struct	s_light
{
	int			type;
	double		intensity;
	t_vector	ray;
}				t_light;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			figures;
	int			sources;
	int			closest_sphere;
	int			shadow_sphere;
	int			recursion_depth;
}				t_window;

int				key_hook(int kcode, t_window *win);
int				pixel2image(t_window *win, int x, int y, int color);
void			draw_sphere
(t_window *win, t_vector cam, t_sphere *sphere, t_light *light);
t_vector		get_viewport(int x, int y);

double			scal_prod(t_vector v1, t_vector v2);
t_vector		sub_vect(t_vector v1, t_vector v2);
t_vector		add_vect(t_vector v1, t_vector v2);
t_vector		num_mult_vec(double num, t_vector v);
t_vector		get_normal(t_vector v);

void			parse_figures(t_window *win);
double			compute_light(t_vector point, t_vector normal, t_vector ray, t_light *light, t_window *win, int shine, t_sphere *s);
int				get_color(int color, int reflect_color, double intensity, int state);

t_closest		closest_intersection(t_window *win, t_vector cam, t_vector ray, t_sphere *s, double t_min, double t_max);

t_roots			get_roots(t_vector cam, t_vector ray, t_sphere s);

t_vector		reflect_ray(t_vector normal, t_vector ray);

void			draw_plane(t_window *win, t_vector cam, t_plane *plane, t_light *light);

void			draw_cylinder(t_window *win, t_vector cam, t_cylinder *cylinder, t_light *light);

#endif
