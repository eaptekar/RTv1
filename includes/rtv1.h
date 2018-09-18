/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:52 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/18 18:57:13 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "mlx_keys_macos.h"

# include <stdio.h>  //delete this

# define WIN_W	1080
# define WIN_H	1080

# define VW_W	1.0
# define VW_H	(VW_W * WIN_H / WIN_W)
# define DIST	1.0

# define T_MIN	1.0
# define T_MAX	1000.0

# define ERROR(X)	ft_putendl_exit(X, -1)

typedef struct	s_closest
{
	double		t;
	int			i;
	int			type;
}				t_closest;

typedef struct	s_roots
{
	double		t1;
	double		t2;
	int			type;
	int			i;
}				t_roots;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_light
{
	int			type;
	double		intensity;
	t_vector	ray;
}				t_light;

typedef struct	s_plane
{
	t_vector	center;
	t_vector	normal;
	int			color;
	int			shine;
	double		reflect;
}				t_plane;

typedef struct	s_sphere
{
	t_vector	center;
	double		radius;
	int			color;
	int			shine;
	double		reflect;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vector	center;
	t_vector	axis;
	double		radius;
	float		maxm;
	int			color;
	int			shine;
	double		reflect;
}				t_cylinder;

typedef struct	s_cone
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
	t_vector	point;
	t_vector	normal;
	int			shine;
	int			color;
	double		r;
}				t_figure;

typedef struct	s_scene
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_cone		*cone;
	t_light		*light;
	int			planes;
	int			spheres;
	int			cylinders;
	int			cones;
	int			figures;
	int			sources;
	t_vector	cam;
	t_vector	angle;
	int			recursion_depth;
	double		t_min;
	double		t_max;
}				t_scene;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

int				key_hook(int kcode, t_window *win);
int				exit_redcross(t_window *win);

void			draw_scene(t_window win, t_scene scene);
void			parse_figures(t_window win);
t_roots			get_roots(int i, t_scene s, t_vector cam, t_vector ray);
t_figure		closest_figure(t_scene scene, t_vector cam, t_vector ray, t_closest closest);
t_vector		get_viewport(int x, int y);
t_vector		reflect_ray(t_vector normal, t_vector ray);
int				get_color(int color, int reflect_color, \
	double intensity, int state);

double			dot(t_vector v1, t_vector v2);
t_vector		sub(t_vector v1, t_vector v2);
t_vector		add(t_vector v1, t_vector v2);
t_vector		mult(double num, t_vector v);
t_vector		matrix_mult(t_vector vec, t_vector angle);
t_vector		get_normal(t_vector v);

#endif
