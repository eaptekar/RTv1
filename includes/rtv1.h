/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:52 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/12 20:30:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "mlx_keys_macos.h"

#include <stdio.h>

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
	int			type;
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

typedef struct	s_light
{
	int			type;
	double		intensity;
	t_vector	ray;
}				t_light;

typedef struct	s_figure
{
	int			spheres;
	int			planes;
	t_sphere	*sphere;
	t_plane		*plane;
}				t_figure;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			figures;
	int			sources;
	int			recursion_depth;
}				t_window;

int				key_hook(int kcode, t_window *win);
int				pixel2image(t_window *win, int x, int y, int color);
void			draw_figure(t_window *win, t_vector cam, t_figure figure, t_light *light);
t_vector		get_viewport(int x, int y);

double			scal_prod(t_vector v1, t_vector v2);
t_vector		sub_vect(t_vector v1, t_vector v2);
t_vector		add_vect(t_vector v1, t_vector v2);
t_vector		num_mult_vec(double num, t_vector v);
t_vector		get_normal(t_vector v);

void			parse_figures(t_window *win);
double			compute_light(t_vector point, t_vector normal, t_vector ray, t_light *light, t_window *win, int shine, t_figure figure);
int				get_color(int color, int reflect_color, double intensity, int state);

t_closest		closest_intersection(t_vector cam, t_vector ray, t_figure figure, double t_min, double t_max);
t_roots			get_roots(t_vector cam, t_vector ray, t_sphere s);
t_vector		reflect_ray(t_vector normal, t_vector ray);

t_roots			sphere_intersect(t_vector cam, t_vector ray, t_sphere s);
t_roots			plane_intersect(t_vector cam, t_vector ray, t_plane p);

#endif
