/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:52 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/06 15:18:30 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <errno.h>

# include "libft.h"
# include <stdio.h>
# include "mlx_keys_macos.h"
//# include "mlx_keys_linux.h"

# define WIN_W	1080
# define WIN_H	1080

# define VW_W	1.0
# define VW_H	(VW_W * WIN_H / WIN_W)
# define DIST	1.0

# define T_MIN	1.0
# define T_MAX	1000.0

# define ERROR(X)	ft_putendl_exit(X, -1)

typedef struct	s_quaternion
{
	double		r;
	double		i;
	double		j;
	double		k;
}				t_quaternion;

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
	t_vector	ray;
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
	int 		win_w;
	int	    	win_h;
}				t_scene;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*image;
	int			bpp;
	int			size_line;
	int			end;
}				t_window;

int				key_hook(int kcode, t_window *win);
int				free_exit(t_window *win);
int				expose_hook(t_window *win);

void			draw_scene(t_window *win, t_scene scene);
t_roots			get_roots(int i, t_scene s, t_vector cam, t_vector ray);
t_figure		closest_figure(t_scene scene, t_vector cam, \
	t_vector ray, t_closest closest);
t_vector		get_viewport(int x, int y);
t_vector		reflect_ray(t_vector normal, t_vector ray);
int				get_color(int color, int reflect_color, \
	double intensity, int state);

double			dot(t_vector v1, t_vector v2);
t_vector		sub(t_vector v1, t_vector v2);
t_vector		add(t_vector v1, t_vector v2);
t_vector		mult(double num, t_vector v);
t_vector		get_normal(t_vector v);

int				pixel_to_image(t_window *win, int x, int y, int color);
t_vector		set_point(double x, double y, double z);

t_plane			init_plane(t_vector center, t_vector normal);
t_sphere		init_sphere(t_vector center, double radius);
t_cylinder		init_cylinder(t_vector center, t_vector axis, double radius);
t_cone			init_cone(t_vector center, t_vector axis, double k);

t_plane			parse_plane(t_plane p, int shine, double reflect, int color);
t_sphere		parse_sphere(t_sphere s, int shine, double reflect, int color);
t_cylinder		parse_cylinder(t_cylinder c, int shine, \
	double reflect, int color);
t_cone			parse_cone(t_cone c, int shine, double reflect, int color);

t_vector		rotate_camera(t_vector vec, t_vector angle);
t_quaternion	new_quat(double r, double i, double j, double k);
t_quaternion	normal_quat(t_quaternion q);
t_quaternion	inverse_quat(t_quaternion q);
t_quaternion	mult_quat(t_quaternion q, t_quaternion p);

void			scene1(t_window *win);
t_light			*light1(void);
void			scene2(t_window *win);
t_light			*light2(void);
void			scene3(t_window *win);
t_light			*light3(void);
void			scene4(t_window *win);
t_light			*light4(void);
void			scene5(t_window *win);
t_light			*light5(void);
void			scene6(t_window *win);
t_light			*light6(void);
void			scene7(t_window *win);
t_light			*light7(void);
void			scene8(t_window *win);
t_light			*light8(void);

#endif
