/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:52 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/16 00:51:50 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "mlx_keys_linux.h"

# include <stdio.h>

# define WIN_W	640
# define WIN_H	640

# define VW_W	1.0
# define VW_H	(VW_W * WIN_H / WIN_W)
# define DIST	1.0

# define T_MIN	1.0
# define T_MAX	1000.0

typedef struct	s_closest
{
	int			i;
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

typedef struct s_cone
{
	t_vector	center;
	t_vector	axis;
	double		k;
	float		maxm;
	float		minm;
	int			color;
	int			shine;
	double		reflect;
}				t_cone;

typedef struct	s_figure
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_cone		*cone;
	int			planes;
	int			spheres;
	int			cylinders;
	int			cones;
}				t_figure;

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
	int			recursion_depth;
}				t_window;

int				key_hook(int kcode, t_window *win);
int				exit_redcross(t_window *win);
int				pixel2image(t_window *win, int x, int y, int color);
t_vector		get_viewport(int x, int y);

double			scal_prod(t_vector v1, t_vector v2);
t_vector		sub_vect(t_vector v1, t_vector v2);
t_vector		add_vect(t_vector v1, t_vector v2);
t_vector		num_mult_vec(double num, t_vector v);
t_vector		get_normal(t_vector v);

void			parse_figures(t_window *win);
int				get_color(int color, int reflect_color, double intensity, int state);

void			draw_figure(t_window *win, t_vector cam, t_figure figure, t_light *light);

t_roots			sphere_intersect(t_vector cam, t_vector ray, t_sphere s);
t_roots			plane_intersect(t_vector cam, t_vector ray, t_plane p);
t_roots			cyl_intersect(t_vector cam, t_vector ray, t_cylinder c);
t_roots			cone_intersect(t_vector cam, t_vector ray, t_cone c);

t_vector		reflect_ray(t_vector normal, t_vector ray);

t_vector		matrix_mult(t_vector vec, double a, double b, double c);

#endif
